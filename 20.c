//Priyansh Rai
// MT2024021

//20. Find out the priority of your running program. Modify the priority with nice command

/*
Main Function:

    The main function starts by checking if exactly one command-line argument is provided 
    (the value to be added to the current nice value).
    It retrieves the current priority of the running process using nice(0) and prints it.
    The program then modifies the priority by adding the value specified by the user via the command-line 
    argument and prints the new priority.

Usage of nice:

    The nice system call adds a value to the current priority (nice value) of the process. 
    A lower nice value indicates a higher priority, and a higher nice value indicates a lower priority.
*/

#include <unistd.h> // For `nice` system call
#include <stdio.h>  // For `printf` function
#include <stdlib.h> // For `atoi` function
#include <errno.h>  // For checking errors from `nice`

int main(int argc, char *argv[]) {
    int current_priority, new_priority, adjustment;

    // Check if the correct number of arguments is provided
    if (argc != 2) {
        printf("Usage: %s <priority adjustment>\n", argv[0]);
        return 1;
    }

    // Convert the argument to an integer
    adjustment = atoi(argv[1]);

    // Get the current priority
    errno = 0;  // Clear errno before calling nice
    current_priority = nice(0);

    if (current_priority == -1 && errno != 0) {
        perror("Failed to get the current priority");
        return 1;
    }

    printf("Current priority: %d\n", current_priority);

    // Adjust the priority
    errno = 0;  // Clear errno before calling nice
    new_priority = nice(adjustment);

    if (new_priority == -1 && errno != 0) {
        perror("Failed to change the priority");
        return 1;
    }

    printf("New priority: %d\n", new_priority);

    return 0;
}

/*
Terminal :

priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 20op 20.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./20op 5
Current priority: 0
New priority: 5

*/
