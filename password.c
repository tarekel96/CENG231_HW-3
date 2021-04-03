#include <stdlib.h> // exit()
#include <stdio.h> // fgets()
#include <unistd.h> // read()
#include <sys/types.h> // fd_set type
#include <sys/time.h> // timeval struct
#include <sys/select.h> // select()

#define PASSWORD_LEN 8

// method responsible for controlling/timing the read() fd process
int inputTimeout(int filedesc, unsigned int seconds){
	fd_set set; // set of file descriptors that will pass to select()
	struct timeval timeout; //need timeval struct for read()
	
	// init file descriptor set
	FD_ZERO(&set);
	FD_SET(filedesc, &set); 
	
	// init timeval struct
	timeout.tv_sec = seconds;
	timeout.tv_usec = 0; // 0 micro-seconds
	
	// select() returns: 0 if timeout, 1 if input is available, -1 if error
	return select(FD_SETSIZE, &set, NULL, NULL, &timeout);
}

int main(int argv, char ** argc){
	
	// ensure user did not input console arguments
	if(argv != 1){
			printf("Error: Console arguments are not to be provided\n");
			exit(EXIT_FAILURE);
	}
	
	// declare vars
	char password[PASSWORD_LEN + 1]; // array of chars where pw is stored
	const unsigned int MAX_TIME_SECONDS = 10; // amt of time user has to input a pw
	
	// prompt user for pw
	printf("Enter a password\n");
	
	int n_select = inputTimeout(STDIN_FILENO, MAX_TIME_SECONDS);
	
	while(n_select != 0){
		
		// select() error handling case
		if(n_select == -1){
			fprintf(stderr, "Error: An error occurred with select()\n");
			exit(EXIT_FAILURE);
		}
		
		// retrieve password from stdin
		char* nget = fgets(password, PASSWORD_LEN, stdin);
		
		// error handling if input was not successfully captured
		if(nget == NULL){
			fprintf(stderr, "Error: cannot store password. Password cannot exceed 8 characters");
			exit(EXIT_FAILURE);
		}
		
		// output to user the pw by stdout
		int nprint = fprintf(stdout, "You ented: %s\n", password);
		
		// if the password was not able to be printed, handle error
		if(nprint < 0){
			fprintf(stderr, "Error: An error occurred with outputting the password\n");
			exit(EXIT_FAILURE);
		}
		// tell user program was successful and exit program
		else{
			printf("Messsage: Program has been terminated with no error\n");
			exit(EXIT_SUCCESS);
		}
	}
	
	// program ended, but not as expected
	exit(EXIT_FAILURE);
}
