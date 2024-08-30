//Priyansh Rai
// MT2024121

/*
23. Write a program to create a Zombie state of the running program
*/

#include <sys/types.h> // Import for `fork` system call
#include <unistd.h>    // Import for `fork`, `sleep`, `_exit` system calls
#include <stdio.h>     // Import for `printf` function

int main() {

    pid_t childPid;

    // Fork the process to create a child
    if ((childPid = fork()) != 0)  // If fork() returns a non-zero value, we're in the parent process
    {
        // Parent process
        printf("Parent PID: %d\n", getpid());
        printf("Putting parent to sleep for 100s!\n");
        sleep(100);  // Sleep for 100 seconds
        printf("Parent is now awake!\n");
    }
    else  // If fork() returns 0, we're in the child process
    {
        // Child process
        printf("Child PID: %d\n", getpid());
        printf("Exiting child!\n");
        _exit(0);  // Exit the child process
    }

    return 0;  // Return 0 to indicate successful execution
}



/*
TERMINAL :
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 23op 23.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./23op
Parent PID: 77053
Putting parent to sleep for 100s!
Child PID: 77054
Exiting child!
//after 100 sec
Parent is now awake!


*/
