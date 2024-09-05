//Priyansh Rai
// MT2024121
// Question: Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls


#include <unistd.h> // Import for read & write system call
#include <stdio.h>  // Import for perror function
#include<fcntl.h>

int main(){
char buff[100];
int ret = read(0,buff,sizeof(buff));
write(1,buff,ret);
}/*
 priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 6op 6.c
 priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./6op 
wfffrferf
wfffrferf
*/

/*
input from the standard input (file descriptor 0, which typically corresponds to the keyboard) 
and writes it to the standard output (file descriptor 1, which typically corresponds to the terminal screen).
*/
