//Priyansh Rai
// MT2024021


//19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.

/*
Using __rdtsc():

    __rdtsc() is an intrinsic function that reads the Time Stamp Counter.
     This function returns the number of CPU cycles since the last reset, 
     allowing for very accurate time measurements.
*/


#include <sys/types.h> // For `getpid` system call
#include <unistd.h>    // For `getpid` system call
#include <stdio.h>     // For printf

// Use __rdtsc() to read the Time Stamp Counter
#ifdef _MSC_VER
#include <intrin.h>
#else
#include <x86intrin.h>
#endif

int main() {

    /*
    The program captures the TSC value before and after calling getpid() to measure the time taken to execute this system call.
It then calculates and prints the difference, which represents the number of CPU cycles taken by the getpid() call.
    
    */
    unsigned long long start, end; // Use unsigned long long to hold large TSC values
    pid_t pid;                     // Type for process IDs

    // Capture the starting TSC value
    start = __rdtsc();

    // Perform the getpid() system call
    pid = getpid();

    // Capture the ending TSC value
    end = __rdtsc();

    // Output the process ID and the number of CPU cycles taken
    printf("Process ID: %d\n", pid);
    printf("CPU cycles taken by getpid(): %llu\n", end - start);

    return 0;
}

/*
Terminal :

priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 19op 19.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./19op
Process ID: 73362
CPU cycles taken by getpid(): 19981

*/

