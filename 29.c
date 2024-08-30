//Priyansh Rai
// MT2024021

/*
29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR)
*/



#include <sched.h> // Import for `sched_getscheduler` and `sched_setscheduler`
#include <sys/types.h> // Import for `getpid`
#include <unistd.h>    // Import for `getpid`
#include <stdio.h>     // Import for `perror` and `printf`

void main()
{
    int currentPolicy;
    pid_t pid;
    pid = getpid();
    currentPolicy = sched_getscheduler(pid);
    //Retrieve scheduling algorithm for a particular purpose
    struct sched_param priority;
    //Data structure to describe a process' schedulability.
    priority.sched_priority = 10;

    switch (currentPolicy)
    {
    case SCHED_FIFO:
        printf("Current policy is FIFO\n");
        sched_setscheduler(pid, SCHED_RR, &priority);
        currentPolicy = sched_getscheduler(pid);
        printf("Current policy is %d\n", currentPolicy);
        break;
    case SCHED_RR:
        printf("Current policy is RR\n");
        sched_setscheduler(pid, SCHED_FIFO, &priority);
        currentPolicy = sched_getscheduler(pid);
        printf("Current policy is %d\n", currentPolicy);
        break;
    case SCHED_OTHER:
        printf("Current policy is OTHER\n");
        sched_setscheduler(pid, SCHED_RR, &priority);
        currentPolicy = sched_getscheduler(pid);
        printf("Current policy is %d\n", currentPolicy);
        break;
    default:
        perror("Error while getting current policy\n");
    }
}

/*
Terminal :
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 29op 29.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./29op
Current policy is OTHER
Current policy is 0


*/

