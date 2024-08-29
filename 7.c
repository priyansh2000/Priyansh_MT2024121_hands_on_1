// PRIYANSH RAI
// MT2024121
/*
7. Write a program to copy file1 into file2 ($cp file1 file2).
*/
#include <sys/types.h>   // For data types used in system calls
#include <sys/stat.h>    // For file permission macros
#include <fcntl.h>       // For file control options such as open()
#include <unistd.h>      // For system calls like read() and write()
#include <stdio.h>       // For standard I/O functions like printf() and perror()

// Note: This program is limited by the buffer size; if the file exceeds the buffer size, not all contents will be copied.
int main(int argc, char *argv[]) {

    char *srcFilePath;
    char *destFilePath;

    int srcFileDesc, destFileDesc;  // File descriptors for source and destination
    ssize_t bytesRead;              // Number of bytes read from the source file
    ssize_t bytesWritten;           // Number of bytes written to the destination file

    char buffer[100];  // Buffer to hold chunks of data during file copy

    // Ensure that the correct number of arguments are provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    srcFilePath = argv[1];
    destFilePath = argv[2];

    // Open the source file in read-only mode
    srcFileDesc = open(srcFilePath, O_RDONLY);
    // Create or open the destination file in write-only mode; give the user full permissions
    destFileDesc = open(destFilePath, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IXUSR);

    // Check for errors during file opening
    if (srcFileDesc == -1 || destFileDesc == -1) {
        perror("Error opening source or destination file");
        return 1;
    }

    // Copy the data from the source file to the destination file in chunks
    while ((bytesRead = read(srcFileDesc, buffer, sizeof(buffer))) > 0) {
        bytesWritten = write(destFileDesc, buffer, bytesRead);
        if (bytesWritten == -1) {
            perror("Error writing to destination file");
            close(srcFileDesc);
            close(destFileDesc);
            return 1;
        }
    }

    // Check for errors during reading
    if (bytesRead == -1) {
        perror("Error reading from source file");
    } else {
        printf("File copy completed successfully!\n");
    }

    // Close file descriptors
    close(srcFileDesc);
    close(destFileDesc);

    return 0;
}
/*
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ nano source_7.txt
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ cat source_7.txt
HI THIS THE SOURCE CONTENT TO BE COPIED
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ nano dest_7.txt
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ cat dest_7.txt
....

priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 7op 7.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./7op ^C
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./7op source_7.txt dest_7.txt
File copy completed successfully!
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ cat dest_7.txt
HI THIS THE SOURCE CONTENT TO BE COPIED

*/