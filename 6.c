//Priyansh Rai
// MT2024121
// Question: Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls


#include <unistd.h> // Import for read & write system call
#include <stdio.h>  // Import for perror function

void main()
{
    char *buffer[100];
    int readByteCount, writeByteCount;
    while (1)
    {
        readByteCount = read(STDIN_FILENO, buffer, 1);
        writeByteCount = write(STDOUT_FILENO, buffer, 1);

        if (readByteCount == -1 || writeByteCount == -1)
        {
            perror("Error while reading from STDIN / writing to STDOUT");
            break;
        }
    }
}


/*
Read and Write Loop:

    The loop continuously reads one byte from STDIN and writes that byte to STDOUT.
    If read() returns -1, an error occurred during reading, and similarly, if write() returns -1, an error occurred during writing.
    The loop will continue indefinitely until interrupted or an error occurs.

Error Handling:

    The error handling with perror is correctly implemented. If either read() or write() fails, perror will output an appropriate error message, and the loop breaks.*/