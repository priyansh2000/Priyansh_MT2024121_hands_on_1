// Priyansh Rai
// MT2024121
/*
	Create the following types of a files using (i) shell command (ii) system call
	a.soft link(symlink system call)
*/
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(int c,char* argv[]){
int check=mknod(argv[1],S_IFIFO|0666,0);
if(check==-1){printf("Cannot create named pipe\n");}
}
/*
include <stdio.h>: Provides standard input/output functions like printf.
#include <fcntl.h>: Contains definitions for file control options.creat,
#include <sys/types.h> 
 #include <sys/stat.h>: These headers are needed for system calls and to handle file attributes.
--------------------------------------------------------------------------

int check= symlink(argv[1],argv[2]);
The symlink system call in Unix-like operating systems is used to create a symbolic link, or "symlink," which is a type of file that points to another file or directory. This is useful for creating shortcuts or references to files or directories in different locations.
------------------------------------------------------------------------------
int check = link(argv[1],argv[2]);
The link system call in Unix-like operating systems creates a hard link between two files. A hard link is essentially an additional name for an existing file; both names (or paths) refer to the same underlying file data.
-------------------------------------------------------------------------------
mknod(argv[1], S_IFIFO | 0666, 0);
    S_IFIFO: Indicates that a FIFO (named pipe) is to be created.
    0666: The file permissions, meaning the FIFO is readable and writable by everyone.
    The mknod system call is used to create a named pipe (FIFO) in this program. 
    A FIFO file allows two or more processes to communicate by reading from and writing to the same file
    ------------------------------------------------------------------------------
    ps aux | grep infiniteloop //getting pid 0r more/proc/pid/status
cd/proc/42069
cat status
-------------------------------------------------------------------------------
int o=creat(argv[1],S_IRWXU);
This line creates a new file with the name specified in argv[1] and assigns it 

the permissions S_IRWXU (read, write, and execute permissions for the owner). The creat function returns a file descriptor, which is stored in o
    --------------------------------------------
    
    
*/