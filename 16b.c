//Priyansh Rai
// MT2024021

/*
16. Write a program to perform mandatory locking.
b. Implement read lock
*/

#include <unistd.h>    // For system calls such as fcntl, close
#include <fcntl.h>     // For file control options (O_RDONLY) and file locking
#include <sys/types.h> // For data types used in system calls like open
#include <sys/stat.h>  // For file status flags used in open
#include <stdio.h>     // For standard I/O functions like printf

int main(int argc, char *argv[]) 
{
    char *filePath;
    struct flock fileLock, lockInfo;
    int fd;

    // Ensure the user provides exactly one argument (the file name)
    if (argc != 2) {
        fprintf(stderr, "Please specify the file name to be locked as an argument.\n");
        return 1;
    }

    filePath = argv[1];

    // Initialize lock structure to set a read lock on the file
    fileLock.l_type = F_RDLCK;    // Request a read lock
    fileLock.l_whence = SEEK_SET; // Start the lock from the beginning of the file
    fileLock.l_start = 0;         // Lock the file from the start
    fileLock.l_len = 0;           // When l_len is 0, lock applies to the entire file
    fileLock.l_pid = getpid();    // Set the lock owner to the current process

    // Copy the lock structure to another variable for status checking
    lockInfo = fileLock;

    // Open the file in read-only mode
    fd = open(filePath, O_RDONLY);

    // Check if the file opened successfully
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Check the current lock status of the file
    if (fcntl(fd, F_GETLK, &lockInfo) == -1) {
        perror("Error retrieving lock information");
        close(fd);
        return 1;
    }

    // Determine the lock status and inform the user
    if (lockInfo.l_type == F_WRLCK) {
        printf("The file is already locked for writing by process %d\n", lockInfo.l_pid);
    } else if (lockInfo.l_type == F_RDLCK) {
        printf("The file is already locked for reading by process %d\n", lockInfo.l_pid);
    } else {
        // Apply the read lock if no conflicting lock is found
        if (fcntl(fd, F_SETLK, &fileLock) == -1) {
            perror("Error applying the lock");
            close(fd);
            return 1;
        }
        printf("File has been successfully locked for reading.\n");
    }

   

    // Close the file descriptor
    close(fd);

    return 0; 
}


/*
Terminal :
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 16bop 16b.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./16bop 16.txt
File has been successfully locked for reading.


*/