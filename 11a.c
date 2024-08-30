//Priyansh Rai
// MT2024121
/*
11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup*/
// Question: Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not using `dup`

#include <unistd.h>    // Import for `dup` system call
#include <sys/types.h> // Import for `open` system call
#include <sys/stat.h>  // Import for `open` system call
#include <fcntl.h>     // Import for `open` system call
#include <stdio.h>     // Import required for `perror` & `perror`

void main(int argc, char *argv[])
{

    char *filename;                        // File name of the source file
    int fileDescriptor, dupFileDescriptor; // The original & duplicate file descriptor
    int writeByteCount;                    // Number of bytes written to the source file

    if (argc != 2)
        printf("Pass the file name as the argument!");
    else
    {
        filename = argv[1];
        fileDescriptor = open(filename, O_WRONLY | O_APPEND);
        if (fileDescriptor == -1)
            perror("Error while opening file");
        else
        {
            dupFileDescriptor = dup(fileDescriptor);

            // Writing using original file descriptor
            writeByteCount = write(fileDescriptor, "Using original FDs", 18);
            if (writeByteCount == -1)
                perror("Error while writing file using original FD");

            // Writing using duplicate file descriptor
            writeByteCount = write(dupFileDescriptor, "Using duplicate FDs", 19);
            if (writeByteCount == -1)
                perror("Error while writing file using duplicate FD");

            close(fileDescriptor);
        }
    }
}
/*Duplicate the File Descriptor:

    dup(fileDescriptor) duplicates the file descriptor, returning a new file descriptor (dupFileDescriptor) that refers to the same file description (the underlying open file). Both file descriptors share the same file offset, file status flags, etc.

Write Using Both Descriptors:

    The program writes "Using original FD" (17 bytes) using the original file descriptor.
    It then writes "Using duplicate FD" (18 bytes) using the duplicated file descriptor.
    After each write, the return value is checked. If write returns -1, an error occurred, and perror is used to report it.*/


    /*
    terminal
    riyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ nano 11a.txt
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 11aop 11a.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./11aop 11a.txt
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ cat 11a.txt
...

Using original FDsUsing duplicate FDs
    */

