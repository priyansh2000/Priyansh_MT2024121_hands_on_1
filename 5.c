//Priyansh Rai
// MT2024121

/*
Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
*/
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
void main(int argv,char *argc[]){
	int f1=creat(argc[1],S_IRWXU|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
	int f2=creat(argc[2],S_IRWXU|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
	int f3=creat(argc[3],S_IRWXU|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
	int f4=creat(argc[4],S_IRWXU|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
	int f5=creat(argc[5],S_IRWXU|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);

    /*creat(argc[1], ...):

    creat is a function that creates a new file or truncates an existing one to zero length.
    argc[1] refers to the first command-line argument, which should be the name of the file you want to create.

File Permissions:

    S_IRWXU: Read, write, and execute permission for the owner (user).
    S_IRGRP: Read permission for the group.
    S_IWGRP: Write permission for the group.
    S_IROTH: Read permission for others.
    S_IWOTH: Write permission for others.*/
	printf("f1=%d\tf2=%d\tf3=%d\tf4=%d\tf5=%d\t\n",f1,f2,f3,f4,f5);
    /*After running the program, the file myfile.txt will be created with the following permissions:

    Owner (User): Read, write, execute (rwx).
    Group: Read, write (rw-).
    Others: Read, write (rw-).

You can verify the permissions using the ls -l command:

bash

ls -l myfile.txt

This should output something like:

sql

-rwxrw-rw- 1 user group 0 Aug 22 12:34 myfile.txt

This shows that the file has the permissions rwxrw-rw-.*/
	while(1);
}

/*
OUTPOT
riyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ps aux | grep 5opf
priyansh    9480  100  0.0   2616  1152 pts/1    R    10:54   2:13 ./5opf
priyansh    9532  0.0  0.0   9072  2304 pts/1    S+   10:56   0:00 grep --color=auto 5opf
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ls -l /proc/9480/fd
total 0
lrwx------ 1 priyansh priyansh 64 Aug 24 10:57 0 -> /dev/pts/1
lrwx------ 1 priyansh priyansh 64 Aug 24 10:57 1 -> /dev/pts/1
lrwx------ 1 priyansh priyansh 64 Aug 24 10:57 2 -> /dev/pts/1
l-wx------ 1 priyansh priyansh 64 Aug 24 10:57 3 -> '/home/priyansh/hands_on_1/QT_ACCESSIBILITY=1'
l-wx------ 1 priyansh priyansh 64 Aug 24 10:57 4 -> '/home/priyansh/hands_on_1/COLORTERM=truecolor'

*/