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
int main(int c,char *argv[]){
char buffer[200];
if(c!=3){printf("Wrong number of arguments\n"); exit(-1);}
int fd = open(argv[1],O_RDONLY,0400);
if(fd==-1) printf("file not opened");
int ret;
int fd2 =open(argv[2],O_RDWR|O_CREAT|O_EXCL,0600);
if(fd2==-1) printf("file cannot be copied");
while((ret=read(fd,buffer,sizeof(buffer)))>0)
write(fd2,buffer,ret);

close(fd);
close(fd2);
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

/*
0 (First Digit): This digit affects the special modes (setuid, setgid, and sticky bit), which are not relevant here, so it's set to 0.
4 (Second Digit): This digit controls the permissions for the owner of the file.

    4: Read permission.

0 (Third Digit): This digit controls the permissions for the group associated with the file.

    0: No permissions.

0 (Fourth Digit): This digit controls the permissions for others (anyone else who is not the owner or in the group).

    0: No permissions.*/

    /*
    _RDWR

    Description: Opens the file for both reading and writing.
    Usage: open(argv[2], O_RDWR | O_CREAT | O_EXCL, 0600);
    Effect: The file can be read from and written to. If the file is opened successfully, the file descriptor allows both operations.

3. O_CREAT

    Description: If the file does not exist, this flag tells the open() system call to create the file.
    Usage: open(argv[2], O_RDWR | O_CREAT | O_EXCL, 0600);
    Effect: If the file specified by argv[2] does not exist, it will be created with the permissions specified by the third argument (0600 in this case).

4. O_EXCL

    Description: When used with O_CREAT, this flag ensures that the open() call will fail if the file already exists.
    Usage: open(argv[2], O_RDWR | O_CREAT | O_EXCL, 0600);
    Effect: If the file specified by argv[2] already exists, open() will return -1 and set errno to EEXIST. This is useful for ensuring that files aren't accidentally overwritten.

Permissions (0600)

When creating a file with O_CREAT, you also need to specify the file permissions. These are provided as the third argument to open() if O_CREAT is used:

    0600: This sets the file's permissions to allow the owner to read and write to the file, but no one else (neither group nor others) can access the file.
        0: No permissions for others.
        6: Read and write permissions for the owner (4 for read + 2 for write = 6).
        0: No permissions for the group.
        0: No permissions for others.*/