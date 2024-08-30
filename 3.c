//Priyansh Rai
// MT2024121


/*
Write a program to create a file and print the file descriptor value. Use creat ( ) system call
*/
#include<stdio.h>
#include<sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
/*#include<sys/stat.h> and #include<sys/types.h>: Includes definitions for file and directory operations, including file permissions.
#include<fcntl.h>: Includes file control options, such as creat.*/

int main(int argc,char *argv[]){
	int o=creat(argv[1],S_IRWXU);
    /*  
    int main(int argc, char *argv[]): The main function takes two arguments: argc (the argument count) and argv (an array of argument strings).
int o = creat(argv[1], S_IRWXU);: This line creates a new file with the name specified in argv[1] and assigns it 

the permissions S_IRWXU (read, write, and execute permissions for the owner). The creat function returns a file descriptor, which is stored in o
    */
	printf("%d\n",o);

    /* 
    priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 3_out_create_file_ 3.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ls
1a.c  2.c  3  3.c  3_out_create_file_  infiniteloop
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./3_out_create_file_ 3_out.txt
3
*/
	return 0;
}