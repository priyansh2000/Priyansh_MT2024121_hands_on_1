//Priyansh Rai
// MT2024121


/*Write a program to open an existing file with read write mode. Try O_EXCL flag also.
 */
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
int main(int c, char *argv[]){
int fd1 = open(argv[1],O_CREAT|O_RDWR,0744);
if(fd1==-1){printf("The file %s couldn't be opened in read write mode\n",argv[1]);}
if(fd1!=-1) {printf("The file %s has been opened\n ",argv[1]);}
printf("The file descriptor value is  %d\n",fd1);
int fd2 = open("filenow1",O_CREAT|O_EXCL,0744);
if(fd2==-1){printf("The file %s already exists so cannot be opened with O_EXCL flag\n",argv[2]);}
if(fd2!=-1){printf("The file %s has been opened\n", argv[2]);}
printf("The file descriptor value is %d\n",fd2);
}
/* Terminal:./a.out file1 file2
   Output:
The file file1 has been opened
The file descriptor value is  3
The file file1 already exists so cannot be opened with O_EXCL flag
The file descriptor value is -1
*/
/*Opening the File:

    int o = open(argv[1], O_RDWR);: Opens the file in read/write mode. The open function returns a file descriptor, which is a
     non-negative integer if successful or -1 if an error occurs.
    int e = open(argv[1], O_EXCL);: The O_EXCL flag is used with O_CREAT to ensure that a file is created exclusively
     (i.e., it will fail if the file already exists). However, since O_CREAT is missing, this call doesn't make sense on its own and will likely fail.

Output:

    The code prints the file descriptors returned by open. If the open call fails, it will return -1

    priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 4opf 4.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./4opf 
-1 
-1 
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ls
1a.c  2.c  2outinfiniteloop  3  3.c  3_out_create_file_  3_out.txt  4.c  4opf
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./4opf 3_out.txt
3 
4 

    
    */