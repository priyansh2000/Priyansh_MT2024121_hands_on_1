//Priyansh Rai
// MT2024121

/*
18. Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
*/



#include <stdio.h>  // For Standard ticketNo Output Functions like printf().
#include <fcntl.h>  // For opening a file - open().
#include <unistd.h> // For using functions like read(), write() and close().

int main() {
    int fileDescript, ticketNo;
    struct {                           // Ticket Structure
        int trainNo;
        int tktCnt;
    } database[3];

    fileDescript = open("18b.txt", O_RDWR);
    printf("choose the  train number: (1 to 3)\n");
    scanf("%d", &ticketNo);

    struct flock updateLock;             // Setting lock for the specific record.
    updateLock.l_whence = SEEK_SET;
    updateLock.l_type = F_WRLCK;
    updateLock.l_len = sizeof(database);
    updateLock.l_start = (ticketNo - 1) * sizeof(database);
    updateLock.l_pid = getpid();


    lseek(fileDescript, (ticketNo - 1) * sizeof(database), SEEK_SET);    // Move pointer to that record.
    
    fcntl(fileDescript, F_SETLKW, &updateLock);          // Set the lock to the specific record.

    read(fileDescript, &database, sizeof(database));     // Read the record.


    printf("Current ticket count: %d\n", database[ticketNo-1].tktCnt);   // Get value of ticket count.
    database[ticketNo-1].tktCnt++;                       // Update the value ticket count.

    lseek(fileDescript, -1 * sizeof(database), SEEK_CUR);      // Now move to start of that specific record.
    write(fileDescript, &database, sizeof(database));          // Overwrites content at that location.

    updateLock.l_type = F_UNLCK;                          // Unlock the lock.
    fcntl(fileDescript, F_SETLK, &updateLock);
    printf("Total tickets booked in this session : %d\n", database[ticketNo-1].tktCnt);
}
 


/*



TERMINAL :
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ nano 18b.txt
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 18bop 18b.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./18bop
choose the  train number: (1 to 3)
1
Current ticket count: 1767993972
Total tickets booked in this session : 1767993973
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/



*/