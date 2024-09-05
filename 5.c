//Priyansh Rai
// MT2024121

/*
Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
*/
#include<stdio.h>
#include<fcntl.h>
int main(int c, char* argv[]){
// I will take 5 files names  as input
for(int i=1;i<c;i++){
creat(argv[i],0744);}
for( ; ; ){}}
/* Output:$./a.out fl1 fl2 fl3 fl4 fl5 &
           [1] 5734
           $ls /proc/5734/fd
           0  1  2  3  4  5  6  7

   */