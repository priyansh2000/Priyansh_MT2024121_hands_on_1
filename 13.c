//Priyansh Rai
// MT2024121

/*
13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).*/



#include <sys/time.h>  // For struct timeval
#include <sys/types.h> // For fd_set and select
#include <unistd.h>    // For STDIN_FILENO, select
#include <stdio.h>     // For printf and perror

int main() {
    fd_set input_set;    // File descriptor set for input
    struct timeval timer; // Timer struct to specify timeout

    int result;          // Result of select call

    // Initialize the file descriptor set
    FD_ZERO(&input_set);              // Clear all entries in the set
    FD_SET(STDIN_FILENO, &input_set); // Add STDIN to the set

    // Set the timeout to 10 seconds
    timer.tv_sec = 10;
    timer.tv_usec = 0;

    // Wait for input on STDIN with a 10-second timeout
    result = select(STDIN_FILENO + 1, &input_set, NULL, NULL, &timer);

    if (result == -1) {
        perror("Error using select");
    } else if (result == 0) {
        printf("No input received within 10 seconds.\n");
    } else {
        printf("Input is available on STDIN.\n");
    }

    return 0;
}

/*
terminal:
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 13op 13.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./13op 
f
Input is available on STDIN.


*/
