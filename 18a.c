//Priyansh Rai
// MT2024121

/*
18. Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
*/


#include <stdio.h>  // For Standard Input Output Functions like printf().
#include <fcntl.h>  // For opening a file - open().
#include <unistd.h> // For using functions like read(), write() and close().


int main(int argumentCount, char *argumentValues[]) {
   
    int fileDescript;

    struct {                           // Ticket Structure
        int trainNo;
        int tktCnt;
    } database[3];

    int inc = 0;
    while (inc<3) {
        database[inc].trainNo = inc+1000;
        database[inc].tktCnt = inc;
        inc++;
    }

    fileDescript = open("18b.txt", O_CREAT|O_RDWR|O_APPEND, 0766);    // Open a file

    write(fileDescript, &database, sizeof(database));     // Write the database structure to the file.

    close(fileDescript);

}

/*
TERMINAL:
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ cat 18b.txt
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 18aop 18a.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./18aop


for train booking

for urain booking

���p


*/
