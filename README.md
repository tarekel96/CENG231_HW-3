# CENG231_HW-3

## Description of Program
- A C password program that utilizes termios, select, and appropriate error handling.
- The program prompts user to enter a password.
- The user's inputted characters are masked by termios.
- The inputted password is outputted to terminal via stdout.

## Instructions to run the program:
- Compile with gcc: gcc password.c
- Run the program with this command: ./a.out
- NOTE: Program will not run if arguments are provided (error msg will be displayed) 

## Source Files:
- password.c
- README.md
- .gitignore
## Sources referred to:
- C select: https://man7.org/linux/man-pages/man2/select.2.html
- C read: https://man7.org/linux/man-pages/man2/read.2.html
- C select file descriptors: https://www.mkssoftware.com/docs/man3/select.3.asp
- C fgets: https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm
- C fprintf: https://www.tutorialspoint.com/c_standard_library/c_function_fprintf.htm
- C waiting for I/O: https://www.gnu.org/software/libc/manual/html_node/Waiting-for-I_002fO.html
- C fd_set: https://linux.die.net/man/3/fd_set
- C hiding password input on terminal: https://stackoverflow.com/questions/6856635/hide-password-input-on-terminal
