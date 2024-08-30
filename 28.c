//Priyansh Rai
// MT2024121

//28. Write a program to get maximum and minimum real time priority.

#include <sched.h> // Import for `sched_get_priority_*` functions
#include <stdio.h> // Import for `printf`

void main()
{
    int max_priority, min_priority;

    max_priority = sched_get_priority_max(SCHED_RR);
    //Get maximum priority value for a scheduler.
    if (max_priority == -1)
        perror("Error\n");
    else
        printf("The max priority (RR SHEDULING )is: %d\n", max_priority);

    min_priority = sched_get_priority_min(SCHED_RR);
    //Get minimum priority value for a scheduler.
    if (min_priority == -1)
        perror("Error \n");
    else
        printf("The min priority (RR Scheduling) is : %d\n", min_priority);
}

/*
Terminal :
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 28op 28.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./28op
The max priority (RR SHEDULING )is: 99
The min priority (RR Scheduling) is : 1

*/