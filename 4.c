//Priyansh Rai
// MT2024121


/*Write a program to open an existing file with read write mode. Try O_EXCL flag also.
 */
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argv,char *argc[])
{
	int a=open(argc[1],O_RDWR);
	printf("%d \n",a);
	int b=open(argc[1],O_EXCL);
	printf("%d \n",b);

    return 0;
}
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