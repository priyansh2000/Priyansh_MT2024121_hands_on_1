//Priyansh Rai
// MT2024121

// Question : Write a program to open a file in read only mode, read line by line and display each line as it is read. Close the file when end of file is reached.

#include <sys/types.h>   // For data types used in system calls
#include <sys/stat.h>    // For file permission macros
#include <fcntl.h>       // For file control options such as open()
#include <unistd.h>      // For system calls like read() and write()
#include <stdio.h>       // For standard I/O functions like printf() and perror()
int main(int c, char* argv[]){
if(c!=2) { printf("the file doesn't exit"); exit(-1);}

int fd = open(argv[1],O_RDONLY);
if(fd==-1) printf("No such file");
char buffer[5000];
int  buff = read(fd,buffer,sizeof(buffer));
int move =0;
for(int i=0;i<buff;i++){

if(buffer[i]=='\n'){
write(1,buffer+move,i+1-move);
printf("The program has read one line\n");
move = i+1;
i=i+1;

}

}
close(fd);
}
/*
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ nano 8.txt
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 8op 8.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./8op 8.txt
this file is to be read


*/
