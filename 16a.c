//Priyansh Rai
// MT2024021

/*
16. Write a program to perform mandatory locking.
a. Implement write lock
*/
#include <unistd.h>    // For system calls like fcntl and close
#include <fcntl.h>     // For file control options like O_RDWR and fcntl commands
#include <sys/types.h> // For data types used in system calls like open
#include <sys/stat.h>  // For file status and permissions macros used in open
#include <stdio.h>     // For input/output functions like printf and perror

int main(int argc, char *argv[]) 
{
    char *fileToLock;
    struct flock fileLock, checkLock;
    int fd;

    //to  Ensure  the correct number of arguments has provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fileToLock = argv[1];

    // Set up the lock properties
    fileLock.l_type = F_WRLCK;    // Request a write lock
    fileLock.l_whence = SEEK_SET; // Start at the beginning of the file
    fileLock.l_start = 0;         // Start locking from the beginning of the file
    fileLock.l_len = 0;           // Lock the entire file
    fileLock.l_pid = getpid();    // Set the process ID

    // Copy lock settings to checkLock for testing if the file is already locked
    checkLock = fileLock;

    // Open the file with read and write permissions
    fd = open(fileToLock, O_RDWR);

    // Check if the file was successfully opened
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Check the current lock status of the file
    if (fcntl(fd, F_GETLK, &checkLock) == -1) {
        perror("Error checking file lock");
        close(fd);
        return 1;
    }

    // Determine and display the lock status
    if (checkLock.l_type == F_WRLCK) {
        printf("File is already locked for writing by process %d\n", checkLock.l_pid);
    } else if (checkLock.l_type == F_RDLCK) {
        printf("File is currently locked for reading by process %d\n", checkLock.l_pid);
    } else {
        // Attempt to apply the write lock
        if (fcntl(fd, F_SETLK, &fileLock) == -1) {
            perror("Error setting file lock");
            close(fd);
            return 1;
        }
        printf("File is now locked for writing\n");
    }

     // pause();  // Used for testing purposes, prevents the program from terminating

    // Close the file descriptor
    close(fd);

    return 0; 
}
/*
Terminal:
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ nano 16.txt
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ cat 16.txt
this file is about to lock for writing

priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 16aop 16a.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./16oap 16.txt
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./16aop 16.txt
File is now locked for writing


*/
