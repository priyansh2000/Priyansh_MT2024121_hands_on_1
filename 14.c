//Priyansh Rai
// MT2024021
/*
14 Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
*/

#include <sys/types.h>  // For data types used in system calls
#include <sys/stat.h>   // For file status flags used with `stat`
#include <unistd.h>     // For `stat`, `write`, and other system calls
#include <fcntl.h>      // For file control options like `O_RDONLY`
#include <stdio.h>      // For standard I/O functions like `printf`

int main(int argc, char *argv[]) {
    struct stat fileStat; // Structure to hold file status information
    int fileDesc;         // File descriptor for the opened file

    // Check if exactly one argument (the filename) is provided
    if (argc != 2) {
        printf("Please provide the name of the file as an argument.\n");
        return 1;
    }

    // Attempt to open the file in read-only mode
    fileDesc = open(argv[1], O_RDONLY);
    if (fileDesc == -1) {
        perror("Error opening file");
        return 1;
    }

    // Retrieve the file's status information
    if (fstat(fileDesc, &fileStat) == -1) {
        perror("Error retrieving file status");
        close(fileDesc);
        return 1;
    }
/*
 Determining the File Type:

    The file type is determined using macros such as S_ISREG, S_ISDIR, etc., which check the st_mode field 
    of the stat structure to identify the file type.
    For each type of file (regular file, directory, character device, block device, FIFO, symbolic link, socket), 
    the program prints a corresponding message.
    If the file type is unknown, it prints "Unknown file type."
*/
    // Determine the type of file based on the `st_mode` field
    if (S_ISREG(fileStat.st_mode)) {
        write(STDOUT_FILENO, "This is a regular file.\n", 24);
    } else if (S_ISDIR(fileStat.st_mode)) {
        write(STDOUT_FILENO, "This is a directory.\n", 21);
    } else if (S_ISCHR(fileStat.st_mode)) {
        write(STDOUT_FILENO, "This is a character device.\n", 28);
    } else if (S_ISBLK(fileStat.st_mode)) {
        write(STDOUT_FILENO, "This is a block device.\n", 25);
    } else if (S_ISFIFO(fileStat.st_mode)) {
        write(STDOUT_FILENO, "This is a FIFO (named pipe).\n", 30);
    } else if (S_ISLNK(fileStat.st_mode)) {
        write(STDOUT_FILENO, "This is a symbolic link.\n", 25);
    } else if (S_ISSOCK(fileStat.st_mode)) {
        write(STDOUT_FILENO, "This is a socket.\n", 18);
    } else {
        write(STDOUT_FILENO, "Unknown file type.\n", 19);
    }

    // Close the file descriptor
    close(fileDesc);

    return 0;
}

/*
Terminal:

priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ nano 14.txt
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ cat 14.txt
TODAY IS FRIDAY 
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 14op 14.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./14op 14.txt
This is a regular file.
*/
