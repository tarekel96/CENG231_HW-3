#include <termios.h>
#include <stdlib.h> // exit()
#include <stdio.h>
#include <unistd.h> // read()
#include <sys/types.h>
#include <sys/time.h>
#include <sys/select.h> // select()

#define PASSWORD_LEN 8

int main(int argv, char ** argc){
	
	if(argv != 1){
			printf("Error: Console arguments are not to be provided\n");
			exit(EXIT_FAILURE);
	}
	
	//struct timeval {
			//time_t tv_sec; // seconds
			//long tv_usec; // microseconds
	//};
	
	char password[PASSWORD_LEN + 1];
	const int maxTimeSeconds = 10;
	struct timeval tv;
	fd_set rfds; // read() file descriptors
	int retval;
	
	FD_ZERO(&rfds); // init read() fd_set
	FD_SET(0, &rfds); // sets the bit for the fd
	
	tv.tv_sec = 3;
	tv.tv_usec = 0;
	
	printf("Enter a password\n");

	retval = select(1, &rfds, NULL, NULL, &tv);
	//~ char* nget = fgets(password, PASSWORD_LEN, stdin);
	
	if(retval == -1){
		fprintf(stderr, "There was an error with select()\n");
		exit(EXIT_FAILURE);
	}
	else if(retval == 0){
		//printf("Enter a password\n");
		//char* nget = fgets(password, PASSWORD_LEN, stdin);
		//if(nget == NULL){
			//fprintf(stderr, "Error: cannot store password. Password cannot exceed 8 characters");
			//exit(EXIT_FAILURE);
		//}
		char* nget = fgets(password, PASSWORD_LEN, stdin);
		if(nget == NULL){
			fprintf(stderr, "Error: cannot store password. Password cannot exceed 8 characters");
			exit(EXIT_FAILURE);
		}
		fprintf(stdout, "\n You ented: %s\n", password);
	}
	else{
		printf("No password was typed within 60 seconds\n");
	}
	
	exit(EXIT_SUCCESS);
}
