//Priyansh Rai
// MT2024021

// Question : Write a program to open a file in read only mode, read line by line and display each line as it is read. Close the file when end of file is reached.

#include <sys/types.h>   // For data types used in system calls
#include <sys/stat.h>    // For file permission macros
#include <fcntl.h>       // For file control options such as open()
#include <unistd.h>      // For system calls like read() and write()
#include <stdio.h>       // For standard I/O functions like printf() and perror()

int main(int argc, char *argv[]) {
    char buffer[1];       // Buffer to hold one character at a time
    int fileDescriptor;

    // Ensure exactly one argument is provided (the filename)
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the file in read-only mode
    fileDescriptor = open(argv[1], O_RDONLY);
    if (fileDescriptor == -1) {
        perror("Error while opening the file");
        return 1;
    }

    // Read the file character by character
    ssize_t bytesRead;
    while ((bytesRead = read(fileDescriptor, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytesRead);
    }

    // Check for read error
    if (bytesRead == -1) {
        perror("Error while reading the file");
        close(fileDescriptor);
        return 1;
    }

    // Close the file descriptor
    close(fileDescriptor);

    return 0;
}
/*
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ nano 8.txt
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 8op 8.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./8op 8.txt
this file is to be read


*/
