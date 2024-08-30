//Priyansh Rai
// MT2024121
/*
10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.*/


#include <sys/stat.h>  // For `open` system call
#include <fcntl.h>     // For `open` system call
#include <sys/types.h> // For `open`, `lseek` system calls
#include <unistd.h>    // For `close`, `lseek` system calls
#include <stdio.h>     // For `perror`, `printf` functions
#include <stdlib.h>    // For `exit` function

int main(int argc, char *argv[])
{
    char *filename;     // File name passed as an argument
    int fileDescriptor; // File descriptor obtained after opening the file
    off_t offset;       // Holds the new offset after seeking
    ssize_t writeByteCount; // Number of bytes written using `write`
    
    // Check if the correct number of arguments is passed
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    filename = argv[1];
    
    // Open the file in read-write mode
    fileDescriptor = open(filename, O_RDWR);
    if (fileDescriptor == -1) {
        perror("Error while opening file");
        exit(EXIT_FAILURE);
    }

    // Move the file pointer 10 bytes from the start of the file and write 10 bytes
    offset = lseek(fileDescriptor, 10, SEEK_SET);
    if (offset == (off_t)-1) {
        perror("Error while seeking in the file");
        close(fileDescriptor);
        exit(EXIT_FAILURE);
    }
    writeByteCount = write(fileDescriptor, "PRIYANSH0P", 10);
    if (writeByteCount == -1) {
        perror("Error while writing to the file");
        close(fileDescriptor);
        exit(EXIT_FAILURE);
    }

    // Move the file pointer 10 bytes from the current position and write 10 bytes
    offset = lseek(fileDescriptor, 10, SEEK_CUR);
    if (offset == (off_t)-1) {
        perror("Error while seeking in the file");
        close(fileDescriptor);
        exit(EXIT_FAILURE);
    }
    writeByteCount = write(fileDescriptor, "PRIYANSHOP", 10);
    if (writeByteCount == -1) {
        perror("Error while writing to the file");
        close(fileDescriptor);
        exit(EXIT_FAILURE);
    }

    // Print the final position of the file pointer
    printf("Final offset after lseek: %ld\n", (long)offset);

    // Close the file
    close(fileDescriptor);

    return 0;
}

/*
iyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ nano 10.txt
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 10op 10.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./10op 10.txt
Final offset after lseek: 30
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ cat 10.txt
..

PRIYANSH0PPRIYANSHOPpriyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ^C
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ od -c 10.txt
0000000   .   .  \n  \n  \0  \0  \0  \0  \0  \0   P   R   I   Y   A   N
0000020   S   H   0   P  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0   P   R
0000040   I   Y   A   N   S   H   O   P
0000050
*/
