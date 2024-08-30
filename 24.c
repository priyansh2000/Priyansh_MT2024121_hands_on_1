//Priyansh Rai
// MT2024021

//24. Write a program to create an orphan process.

#include <sys/types.h> // Import for `fork` system call
#include <unistd.h>    // Import for `fork`, `sleep`, `_exit` system calls
#include <stdio.h>     // Import for `printf` function

int main() 
{
    pid_t childPid;

    // Fork the process to create a child
    if ((childPid = fork()) != 0)  // If fork() returns a non-zero value, we're in the parent process
    {
        // Parent process
        printf("Parent PID: %d\n", getpid());
        printf("Putting Parent to sleep for 10s\n");
        sleep(10);  // Sleep for 10 seconds
        printf("Exiting parent!\n");
        _exit(0);  // Exit the parent process
    }
    else  // If fork() returns 0, we're in the child process
    {
        // Child process
        printf("Child PID: %d\n", getpid());
        printf("Putting child to sleep for 100s\n");
        sleep(100);  // Sleep for 100 seconds
        printf("Child is now awake!\n");
    }

    return 0;  // Return 0 to indicate successful execution
}
/*
Terminal : 
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 24op 24.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./24op
Parent PID: 77769
Putting Parent to sleep for 10s
Child PID: 77770
Putting child to sleep for 100s
Exiting parent!
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ Child is now awake!


*/


