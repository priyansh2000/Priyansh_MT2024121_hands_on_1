//Priyansh Rai
// MT2024121

/*26. Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)*/

#include <unistd.h> // Import for `execl` library function

void main()
{
    char *executable_path = "./14op";
    char *arg = "14.c";

    execl(executable_path, executable_path, arg, NULL);
}
/*
execl(executable_path, executable_path, arg, NULL)
 The execl() function replaces the current process with the new executable (14.out).
  The first argument to execl() is the path to the executable, and the following arguments are
   the arguments passed to the executable. The list of arguments must be terminated by NULL.

The first executable_path argument is typically the name of the program (i.e., argv[0] in the new process).
 This is why the same path appears twice.

*/
/*
Terminal :
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 26op 26.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./26op
This is a regular file.


*/