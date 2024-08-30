//Priyansh Rai
// MT2024021

//15. Write a program to display the environmental variable of the user (use environ).

#include <stdio.h> // For standard input/output functions
#include <string.h> // For string manipulation functions like `strncmp`

extern char **environ; // Access to the environment variables

/*
extern char **environ;:

    This statement declares that the program will use the environ variable, 
    which is an array of strings containing all the environment variables of the current process.

isUser Function:

    The function isUser checks if a given environment variable starts with "USER" by examining the first 
    few characters of the string. If it does, the function returns 1 (true); otherwise, it returns 0 (false)
*/
int isUserVariable(const char *var) {
    // Check if the variable starts with "USER"
    return strncmp(var, "USER", 4) == 0;
}

int main() {
    int i = 0; // Index for iterating over environment variables

    // Loop through all environment variables
    while (environ[i] != NULL) {
        // Print the environment variable if it starts with "USER"
        if (isUserVariable(environ[i])) {
            printf("%s\n", environ[i]);
        }
        i++;
    }

    return 0;
}

/*
Terminal:

priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 15op 15.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./15op 
USERNAME=priyansh
USER=priyansh

*/
