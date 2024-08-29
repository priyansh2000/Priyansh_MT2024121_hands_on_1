//Priyansh Rai
// MT2024021

/*
9. Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change*/

#include <sys/types.h>  // For data types used in system calls
#include <sys/stat.h>   // For file attributes and the stat() system call
#include <unistd.h>     // For system calls
#include <stdio.h>      // For standard I/O functions
#include <time.h>       // For converting timestamps

int main(int argc, char *argv[]) {
    struct stat fileStat;
    
    // Check if exactly one argument is passed
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Retrieve file information
    if (stat(argv[1], &fileStat) == -1) {
        perror("Error while executing the stat call");
        return 1;
    }

    // Display file attributes
    printf("Inode: %ld\n", fileStat.st_ino);
    printf("Number of hard links: %ld\n", fileStat.st_nlink);
    printf("UID: %d\n", fileStat.st_uid);
    printf("GID: %d\n", fileStat.st_gid);
    printf("Size: %ld bytes\n", fileStat.st_size);
    printf("Block size: %ld bytes\n", fileStat.st_blksize);
    printf("Number of blocks: %ld\n", fileStat.st_blocks);
    printf("Time of last access: %s", ctime(&fileStat.st_atime));
    printf("Time of last modification: %s", ctime(&fileStat.st_mtime));
    printf("Time of last status change: %s", ctime(&fileStat.st_ctime));

    return 0;
}

/*
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 9op 9.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./9op 8.txt
Inode: 5524316
Number of hard links: 1
UID: 1000
GID: 1000
Size: 24 bytes
Block size: 4096 bytes
Number of blocks: 8
Time of last access: Thu Aug 29 16:06:30 2024
Time of last modification: Thu Aug 29 16:05:44 2024
Time of last status change: Thu Aug 29 16:05:44 2024

*/
