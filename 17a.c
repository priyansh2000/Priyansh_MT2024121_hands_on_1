// PRIYANSH RAI
 // MT2024121
 /* Write a program to simulate online ticket reservation. Implement write lock
                    Write a program to open a file, store a ticket number and exit. Write a separate program, to
                    open the file, implement write lock, read the ticket number, increment the number and print
                    the new ticket number then close the file.
 */

#include <stdio.h>  // For Standard Input Output Functions like printf().
#include <fcntl.h>  // For opening a file - open().
#include <unistd.h> // For using functions like read(), write() and close().

int main() {

    struct {
        int ticket_no;
    } database;

    struct flock updateLock;
    int fileDescript;
    fileDescript = open("database", O_RDWR);
 
    fcntl(fileDescript, F_SETLKW, &updateLock);  // Setting and Waiting for a lock on database file.
   
    read(fileDescript, &database, sizeof(database));        // Reading the content in the database file.

    printf("Ticket number: %d\n", database.ticket_no); 
    database.ticket_no++;                           // Incrementing ticket number.
   
    lseek(fileDescript, 0, SEEK_SET);               // Move the pointer to start of file. To overwrite the content.
    write(fileDescript, &database, sizeof(database));    // Overwrite the content.


    
    updateLock.l_type = F_UNLCK;                  // Unlock the file lock.
    fcntl(fileDescript, F_SETLK, &updateLock);

}



/*
Terminal :

priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 17aop 17a.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 17bop 17b.c
17b.c: In function ‘main’:

      |                         
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 17bop 17b.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./17bop 100
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./17aop 
Ticket number: 100



*/