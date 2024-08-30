//Priyansh Rai
// MT2024021

/*
22. Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
*/

#include <unistd.h>    // Import for `fork` system call
#include <sys/types.h> // Import for `open`, `fork` system call
#include <sys/stat.h>  // Import for `open` system call
#include <fcntl.h>     // Import for `open` system call
#include <stdio.h>     // Import for `perror`, `printf`

int main(int argc, char *argv[])  // Use argc and argv to handle command-line arguments
{
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];  // Get the file name from command-line arguments
    int childPid, fileDescriptor;

    // Open the file with write and append mode; create if not exists
    fileDescriptor = open(filename, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);

    // Error handling in case the file cannot be opened
    if (fileDescriptor < 0) {
        perror("Failed to open file");
        return 1;
    }

    // Fork the process to create a child
    childPid = fork();

    if (childPid < 0) {
        // Fork failed
        perror("Fork failed");
        close(fileDescriptor);
        return 1;
    }

    if (childPid != 0) { 
        // Parent process
        write(fileDescriptor, "Parent\n", 7);
    } else { 
        // Child process
        write(fileDescriptor, "Child\n", 6);
    }

    // Close the file descriptor in both parent and child processes
    close(fileDescriptor);

    return 0; // Return 0 to indicate successful execution
}

/*
Terminal :
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 22op 22.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./22op 22.txt 
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ cat 22.txt
this is a sample file
Parent
Child



*/