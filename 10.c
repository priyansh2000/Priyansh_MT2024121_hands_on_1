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
#include <stdlib.h>    // For `exit` function>
int main(int c,char* argv[]){
if(c!=2){ printf("wrong number of arguments\n"); exit(-1);}
int fd = open(argv[1],O_CREAT|O_RDWR,0744);
write(fd,"1234567890\n",10);
int r=lseek(fd,10L,SEEK_CUR);
write(fd,"EXTRASTUFF",10);
printf("The return value of lseek %d\n",r);

close(fd);

}
/* Output:
$./a.out seek
The return value of lseek 20
$od -c seek
0000000   1   2   3   4   5   6   7   8   9   0  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   E   X   T   R   A   S   T   U   F   F
0000036

   */