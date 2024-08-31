//Priyansh Rai
// MT2024021

/*
27. Write a program to execute ls -Rl by the following system calls
1)execl 2)execlp 3)execle 4)execv  5)execvp


*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
extern char **environ;
int main(){
int c;
printf("What is your choice to use to execute ls -Rl, 1)execl 2)execlp 3)execle 4)execv  5)execvp\n");
scanf("%d",&c);
switch(c){
case 1:
execl("/bin/ls","ls","-Rl",NULL);
break;
case 2:
execlp("ls", "ls", "-Rl", NULL);
break;
case 3:
execle("/bin/ls","ls","-Rl",NULL,environ);
break;
case 4:
char *args[] = {"ls", "-Rl", NULL};
execv("/bin/ls", args);
break;
case 5:
execvp("ls", (char *[]){"ls", "-Rl", NULL});
default:
printf("Not a correct option\n");

}

}
/*
Terminal :

priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ gcc -o 27op 27.c
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./27op 3
What is your choice to use to execute ls -Rl, 1)execl 2)execlp 3)execle 4)execv  5)execvp
1
.:
total 688
-rw-rw-r-- 1 priyansh priyansh  3206 Aug 30 17:48 10.c
-rwxrwxr-x 1 priyansh priyansh 16280 Aug 29 16:26 10op
-rw-rw-r-- 1 priyansh priyansh    40 Aug 29 16:26 10.txt
-rw-rw-r-- 1 priyansh priyansh  2887 Aug 30 17:48 11a.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 29 18:26 11aop
-rw-rw-r-- 1 priyansh priyansh    42 Aug 29 18:26 11a.txt
-rw-rw-r-- 1 priyansh priyansh  1679 Aug 30 17:48 11b.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 29 18:33 11bop
-rw-rw-r-- 1 priyansh priyansh  1704 Aug 30 17:49 11c.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 29 18:36 11cop
-rw-rw-r-- 1 priyansh priyansh  3711 Aug 30 17:49 12.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 29 18:43 12op
-rw-rw-r-- 1 priyansh priyansh    23 Aug 29 18:42 12.txt
-rw-rw-r-- 1 priyansh priyansh  1439 Aug 30 17:49 13.c
-rwxrwxr-x 1 priyansh priyansh 16096 Aug 30 09:48 13op
-rw-rw-r-- 1 priyansh priyansh  3007 Aug 30 17:50 14.c
-rwxrwxr-x 1 priyansh priyansh 16216 Aug 30 09:56 14op
-rw-rw-r-- 1 priyansh priyansh    17 Aug 30 09:56 14.txt
-rw-rw-r-- 1 priyansh priyansh  1446 Aug 30 10:05 15.c
-rwxrwxr-x 1 priyansh priyansh 16112 Aug 30 10:04 15op
-rw-rw-r-- 1 priyansh priyansh  2890 Aug 30 17:33 16a.c
-rwxrwxr-x 1 priyansh priyansh 16328 Aug 30 17:28 16aop
-rw-rw-r-- 1 priyansh priyansh  2642 Aug 30 17:40 16b.c
-rwxrwxr-x 1 priyansh priyansh 16352 Aug 30 17:39 16bop
-rw-rw-r-- 1 priyansh priyansh    44 Aug 30 17:38 16.txt
-rw-rw-r-- 1 priyansh priyansh   343 Aug 30 17:43 17.c
-rw-rw-r-- 1 priyansh priyansh     0 Aug 30 13:00 18a.c
-rw-rw-r-- 1 priyansh priyansh   259 Aug 30 13:06 18b.c
-rw-rw-r-- 1 priyansh priyansh  1640 Aug 30 10:22 19.c
-rwxrwxr-x 1 priyansh priyansh 16000 Aug 30 10:21 19op
-rw-rw-r-- 1 priyansh priyansh   461 Aug 30 17:47 1a.c
-rw-rw-r-- 1 priyansh priyansh  2080 Aug 30 17:51 20.c
-rwxrwxr-x 1 priyansh priyansh 16136 Aug 30 10:32 20op
-rw-rw-r-- 1 priyansh priyansh   748 Aug 30 17:51 21.c
-rwxrwxr-x 1 priyansh priyansh 16040 Aug 30 10:36 21op
-rw-rw-r-- 1 priyansh priyansh  1922 Aug 30 17:51 22.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 30 11:05 22op
-rw-rw-r-- 1 priyansh priyansh    35 Aug 30 11:06 22.txt
-rw-rw-r-- 1 priyansh priyansh  1287 Aug 30 17:51 23.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 30 11:18 23op
-rw-rw-r-- 1 priyansh priyansh  1442 Aug 30 17:51 24.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 30 11:32 24op
-rw-rw-r-- 1 priyansh priyansh  2620 Aug 30 17:52 25.c
-rwxrwxr-x 1 priyansh priyansh 16224 Aug 30 11:57 25op
-rw-rw-r-- 1 priyansh priyansh  1096 Aug 30 17:52 26.c
-rwxrwxr-x 1 priyansh priyansh 15960 Aug 30 12:19 26op
-rw-rw-r-- 1 priyansh priyansh   114 Aug 30 13:03 27b.c
-rw-rw-r-- 1 priyansh priyansh   673 Aug 31 12:03 27.c
-rw-rw-r-- 1 priyansh priyansh   116 Aug 30 13:03 27c.c
-rw-rw-r-- 1 priyansh priyansh   110 Aug 30 13:04 27d.c
-rw-rw-r-- 1 priyansh priyansh   112 Aug 30 13:04 27e.c
-rwxrwxr-x 1 priyansh priyansh 16344 Aug 31 12:04 27op
-rw-rw-r-- 1 priyansh priyansh  1004 Aug 30 17:52 28.c
-rwxrwxr-x 1 priyansh priyansh 16120 Aug 30 12:31 28op
-rw-rw-r-- 1 priyansh priyansh  1731 Aug 30 17:52 29.c
-rwxrwxr-x 1 priyansh priyansh 16248 Aug 30 12:39 29op
-rw-rw-r-- 1 priyansh priyansh  1550 Aug 30 17:50 2.c
-rwxrwxr-x 1 priyansh priyansh 16000 Aug 22 10:11 2outinfiniteloop
-rwxrwxr-x 1 priyansh priyansh 17560 Aug 23 18:58 3
-rw-rw-r-- 1 priyansh priyansh  1845 Aug 31 11:57 30.c
-rwxrwxr-x 1 priyansh priyansh 16416 Aug 30 12:51 30op
-rw-rw-r-- 1 priyansh priyansh  1268 Aug 30 17:47 3.c
-rwxrwxr-x 1 priyansh priyansh 16000 Aug 23 18:59 3_out_create_file_
-rwx------ 1 priyansh priyansh     0 Aug 23 19:01 3_out.txt
-rw-rw-r-- 1 priyansh priyansh  1372 Aug 30 17:47 4.c
-rwxrwxr-x 1 priyansh priyansh 16000 Aug 24 09:42 4opf
-rw-rw-r-- 1 priyansh priyansh  2386 Aug 30 17:47 5.c
-rwxrwxr-x 1 priyansh priyansh 16000 Aug 24 10:53 5opf
-rw-rw-r-- 1 priyansh priyansh  1144 Aug 30 17:47 6.c
-rwxrwxr-x 1 priyansh priyansh 16096 Aug 29 14:56 6op
-rw-rw-r-- 1 priyansh priyansh  3174 Aug 29 15:23 7.c
-rwxrwxr-x 1 priyansh priyansh 16304 Aug 29 15:20 7op
-rw-rw-r-- 1 priyansh priyansh  1728 Aug 30 17:48 8.c
-rwxrwxr-x 1 priyansh priyansh 16264 Aug 29 16:05 8op
-rw-rw-r-- 1 priyansh priyansh    24 Aug 29 16:05 8.txt
-rw-rw-r-- 1 priyansh priyansh  1995 Aug 30 17:48 9.c
-rwxrwxr-x 1 priyansh priyansh 16200 Aug 29 16:14 9op
-rw-rw-r-- 1 priyansh priyansh    40 Aug 29 15:21 dest_7.txt
-rw-rw-r-- 1 priyansh priyansh    40 Aug 29 15:12 source_7.txt
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./27op 
What is your choice to use to execute ls -Rl, 1)execl 2)execlp 3)execle 4)execv  5)execvp
2
.:
total 688
-rw-rw-r-- 1 priyansh priyansh  3206 Aug 30 17:48 10.c
-rwxrwxr-x 1 priyansh priyansh 16280 Aug 29 16:26 10op
-rw-rw-r-- 1 priyansh priyansh    40 Aug 29 16:26 10.txt
-rw-rw-r-- 1 priyansh priyansh  2887 Aug 30 17:48 11a.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 29 18:26 11aop
-rw-rw-r-- 1 priyansh priyansh    42 Aug 29 18:26 11a.txt
-rw-rw-r-- 1 priyansh priyansh  1679 Aug 30 17:48 11b.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 29 18:33 11bop
-rw-rw-r-- 1 priyansh priyansh  1704 Aug 30 17:49 11c.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 29 18:36 11cop
-rw-rw-r-- 1 priyansh priyansh  3711 Aug 30 17:49 12.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 29 18:43 12op
-rw-rw-r-- 1 priyansh priyansh    23 Aug 29 18:42 12.txt
-rw-rw-r-- 1 priyansh priyansh  1439 Aug 30 17:49 13.c
-rwxrwxr-x 1 priyansh priyansh 16096 Aug 30 09:48 13op
-rw-rw-r-- 1 priyansh priyansh  3007 Aug 30 17:50 14.c
-rwxrwxr-x 1 priyansh priyansh 16216 Aug 30 09:56 14op
-rw-rw-r-- 1 priyansh priyansh    17 Aug 30 09:56 14.txt
-rw-rw-r-- 1 priyansh priyansh  1446 Aug 30 10:05 15.c
-rwxrwxr-x 1 priyansh priyansh 16112 Aug 30 10:04 15op
-rw-rw-r-- 1 priyansh priyansh  2890 Aug 30 17:33 16a.c
-rwxrwxr-x 1 priyansh priyansh 16328 Aug 30 17:28 16aop
-rw-rw-r-- 1 priyansh priyansh  2642 Aug 30 17:40 16b.c
-rwxrwxr-x 1 priyansh priyansh 16352 Aug 30 17:39 16bop
-rw-rw-r-- 1 priyansh priyansh    44 Aug 30 17:38 16.txt
-rw-rw-r-- 1 priyansh priyansh   343 Aug 30 17:43 17.c
-rw-rw-r-- 1 priyansh priyansh     0 Aug 30 13:00 18a.c
-rw-rw-r-- 1 priyansh priyansh   259 Aug 30 13:06 18b.c
-rw-rw-r-- 1 priyansh priyansh  1640 Aug 30 10:22 19.c
-rwxrwxr-x 1 priyansh priyansh 16000 Aug 30 10:21 19op
-rw-rw-r-- 1 priyansh priyansh   461 Aug 30 17:47 1a.c
-rw-rw-r-- 1 priyansh priyansh  2080 Aug 30 17:51 20.c
-rwxrwxr-x 1 priyansh priyansh 16136 Aug 30 10:32 20op
-rw-rw-r-- 1 priyansh priyansh   748 Aug 30 17:51 21.c
-rwxrwxr-x 1 priyansh priyansh 16040 Aug 30 10:36 21op
-rw-rw-r-- 1 priyansh priyansh  1922 Aug 30 17:51 22.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 30 11:05 22op
-rw-rw-r-- 1 priyansh priyansh    35 Aug 30 11:06 22.txt
-rw-rw-r-- 1 priyansh priyansh  1287 Aug 30 17:51 23.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 30 11:18 23op
-rw-rw-r-- 1 priyansh priyansh  1442 Aug 30 17:51 24.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 30 11:32 24op
-rw-rw-r-- 1 priyansh priyansh  2620 Aug 30 17:52 25.c
-rwxrwxr-x 1 priyansh priyansh 16224 Aug 30 11:57 25op
-rw-rw-r-- 1 priyansh priyansh  1096 Aug 30 17:52 26.c
-rwxrwxr-x 1 priyansh priyansh 15960 Aug 30 12:19 26op
-rw-rw-r-- 1 priyansh priyansh   114 Aug 30 13:03 27b.c
-rw-rw-r-- 1 priyansh priyansh   673 Aug 31 12:03 27.c
-rw-rw-r-- 1 priyansh priyansh   116 Aug 30 13:03 27c.c
-rw-rw-r-- 1 priyansh priyansh   110 Aug 30 13:04 27d.c
-rw-rw-r-- 1 priyansh priyansh   112 Aug 30 13:04 27e.c
-rwxrwxr-x 1 priyansh priyansh 16344 Aug 31 12:04 27op
-rw-rw-r-- 1 priyansh priyansh  1004 Aug 30 17:52 28.c
-rwxrwxr-x 1 priyansh priyansh 16120 Aug 30 12:31 28op
-rw-rw-r-- 1 priyansh priyansh  1731 Aug 30 17:52 29.c
-rwxrwxr-x 1 priyansh priyansh 16248 Aug 30 12:39 29op
-rw-rw-r-- 1 priyansh priyansh  1550 Aug 30 17:50 2.c
-rwxrwxr-x 1 priyansh priyansh 16000 Aug 22 10:11 2outinfiniteloop
-rwxrwxr-x 1 priyansh priyansh 17560 Aug 23 18:58 3
-rw-rw-r-- 1 priyansh priyansh  1845 Aug 31 11:57 30.c
-rwxrwxr-x 1 priyansh priyansh 16416 Aug 30 12:51 30op
-rw-rw-r-- 1 priyansh priyansh  1268 Aug 30 17:47 3.c
-rwxrwxr-x 1 priyansh priyansh 16000 Aug 23 18:59 3_out_create_file_
-rwx------ 1 priyansh priyansh     0 Aug 23 19:01 3_out.txt
-rw-rw-r-- 1 priyansh priyansh  1372 Aug 30 17:47 4.c
-rwxrwxr-x 1 priyansh priyansh 16000 Aug 24 09:42 4opf
-rw-rw-r-- 1 priyansh priyansh  2386 Aug 30 17:47 5.c
-rwxrwxr-x 1 priyansh priyansh 16000 Aug 24 10:53 5opf
-rw-rw-r-- 1 priyansh priyansh  1144 Aug 30 17:47 6.c
-rwxrwxr-x 1 priyansh priyansh 16096 Aug 29 14:56 6op
-rw-rw-r-- 1 priyansh priyansh  3174 Aug 29 15:23 7.c
-rwxrwxr-x 1 priyansh priyansh 16304 Aug 29 15:20 7op
-rw-rw-r-- 1 priyansh priyansh  1728 Aug 30 17:48 8.c
-rwxrwxr-x 1 priyansh priyansh 16264 Aug 29 16:05 8op
-rw-rw-r-- 1 priyansh priyansh    24 Aug 29 16:05 8.txt
-rw-rw-r-- 1 priyansh priyansh  1995 Aug 30 17:48 9.c
-rwxrwxr-x 1 priyansh priyansh 16200 Aug 29 16:14 9op
-rw-rw-r-- 1 priyansh priyansh    40 Aug 29 15:21 dest_7.txt
-rw-rw-r-- 1 priyansh priyansh    40 Aug 29 15:12 source_7.txt
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./27op 
What is your choice to use to execute ls -Rl, 1)execl 2)execlp 3)execle 4)execv  5)execvp
3
.:
total 688
-rw-rw-r-- 1 priyansh priyansh  3206 Aug 30 17:48 10.c
-rwxrwxr-x 1 priyansh priyansh 16280 Aug 29 16:26 10op
-rw-rw-r-- 1 priyansh priyansh    40 Aug 29 16:26 10.txt
-rw-rw-r-- 1 priyansh priyansh  2887 Aug 30 17:48 11a.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 29 18:26 11aop
-rw-rw-r-- 1 priyansh priyansh    42 Aug 29 18:26 11a.txt
-rw-rw-r-- 1 priyansh priyansh  1679 Aug 30 17:48 11b.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 29 18:33 11bop
-rw-rw-r-- 1 priyansh priyansh  1704 Aug 30 17:49 11c.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 29 18:36 11cop
-rw-rw-r-- 1 priyansh priyansh  3711 Aug 30 17:49 12.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 29 18:43 12op
-rw-rw-r-- 1 priyansh priyansh    23 Aug 29 18:42 12.txt
-rw-rw-r-- 1 priyansh priyansh  1439 Aug 30 17:49 13.c
-rwxrwxr-x 1 priyansh priyansh 16096 Aug 30 09:48 13op
-rw-rw-r-- 1 priyansh priyansh  3007 Aug 30 17:50 14.c
-rwxrwxr-x 1 priyansh priyansh 16216 Aug 30 09:56 14op
-rw-rw-r-- 1 priyansh priyansh    17 Aug 30 09:56 14.txt
-rw-rw-r-- 1 priyansh priyansh  1446 Aug 30 10:05 15.c
-rwxrwxr-x 1 priyansh priyansh 16112 Aug 30 10:04 15op
-rw-rw-r-- 1 priyansh priyansh  2890 Aug 30 17:33 16a.c
-rwxrwxr-x 1 priyansh priyansh 16328 Aug 30 17:28 16aop
-rw-rw-r-- 1 priyansh priyansh  2642 Aug 30 17:40 16b.c
-rwxrwxr-x 1 priyansh priyansh 16352 Aug 30 17:39 16bop
-rw-rw-r-- 1 priyansh priyansh    44 Aug 30 17:38 16.txt
-rw-rw-r-- 1 priyansh priyansh   343 Aug 30 17:43 17.c
-rw-rw-r-- 1 priyansh priyansh     0 Aug 30 13:00 18a.c
-rw-rw-r-- 1 priyansh priyansh   259 Aug 30 13:06 18b.c
-rw-rw-r-- 1 priyansh priyansh  1640 Aug 30 10:22 19.c
-rwxrwxr-x 1 priyansh priyansh 16000 Aug 30 10:21 19op
-rw-rw-r-- 1 priyansh priyansh   461 Aug 30 17:47 1a.c
-rw-rw-r-- 1 priyansh priyansh  2080 Aug 30 17:51 20.c
-rwxrwxr-x 1 priyansh priyansh 16136 Aug 30 10:32 20op
-rw-rw-r-- 1 priyansh priyansh   748 Aug 30 17:51 21.c
-rwxrwxr-x 1 priyansh priyansh 16040 Aug 30 10:36 21op
-rw-rw-r-- 1 priyansh priyansh  1922 Aug 30 17:51 22.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 30 11:05 22op
-rw-rw-r-- 1 priyansh priyansh    35 Aug 30 11:06 22.txt
-rw-rw-r-- 1 priyansh priyansh  1287 Aug 30 17:51 23.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 30 11:18 23op
-rw-rw-r-- 1 priyansh priyansh  1442 Aug 30 17:51 24.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 30 11:32 24op
-rw-rw-r-- 1 priyansh priyansh  2620 Aug 30 17:52 25.c
-rwxrwxr-x 1 priyansh priyansh 16224 Aug 30 11:57 25op
-rw-rw-r-- 1 priyansh priyansh  1096 Aug 30 17:52 26.c
-rwxrwxr-x 1 priyansh priyansh 15960 Aug 30 12:19 26op
-rw-rw-r-- 1 priyansh priyansh   114 Aug 30 13:03 27b.c
-rw-rw-r-- 1 priyansh priyansh   673 Aug 31 12:03 27.c
-rw-rw-r-- 1 priyansh priyansh   116 Aug 30 13:03 27c.c
-rw-rw-r-- 1 priyansh priyansh   110 Aug 30 13:04 27d.c
-rw-rw-r-- 1 priyansh priyansh   112 Aug 30 13:04 27e.c
-rwxrwxr-x 1 priyansh priyansh 16344 Aug 31 12:04 27op
-rw-rw-r-- 1 priyansh priyansh  1004 Aug 30 17:52 28.c
-rwxrwxr-x 1 priyansh priyansh 16120 Aug 30 12:31 28op
-rw-rw-r-- 1 priyansh priyansh  1731 Aug 30 17:52 29.c
-rwxrwxr-x 1 priyansh priyansh 16248 Aug 30 12:39 29op
-rw-rw-r-- 1 priyansh priyansh  1550 Aug 30 17:50 2.c
-rwxrwxr-x 1 priyansh priyansh 16000 Aug 22 10:11 2outinfiniteloop
-rwxrwxr-x 1 priyansh priyansh 17560 Aug 23 18:58 3
-rw-rw-r-- 1 priyansh priyansh  1845 Aug 31 11:57 30.c
-rwxrwxr-x 1 priyansh priyansh 16416 Aug 30 12:51 30op
-rw-rw-r-- 1 priyansh priyansh  1268 Aug 30 17:47 3.c
-rwxrwxr-x 1 priyansh priyansh 16000 Aug 23 18:59 3_out_create_file_
-rwx------ 1 priyansh priyansh     0 Aug 23 19:01 3_out.txt
-rw-rw-r-- 1 priyansh priyansh  1372 Aug 30 17:47 4.c
-rwxrwxr-x 1 priyansh priyansh 16000 Aug 24 09:42 4opf
-rw-rw-r-- 1 priyansh priyansh  2386 Aug 30 17:47 5.c
-rwxrwxr-x 1 priyansh priyansh 16000 Aug 24 10:53 5opf
-rw-rw-r-- 1 priyansh priyansh  1144 Aug 30 17:47 6.c
-rwxrwxr-x 1 priyansh priyansh 16096 Aug 29 14:56 6op
-rw-rw-r-- 1 priyansh priyansh  3174 Aug 29 15:23 7.c
-rwxrwxr-x 1 priyansh priyansh 16304 Aug 29 15:20 7op
-rw-rw-r-- 1 priyansh priyansh  1728 Aug 30 17:48 8.c
-rwxrwxr-x 1 priyansh priyansh 16264 Aug 29 16:05 8op
-rw-rw-r-- 1 priyansh priyansh    24 Aug 29 16:05 8.txt
-rw-rw-r-- 1 priyansh priyansh  1995 Aug 30 17:48 9.c
-rwxrwxr-x 1 priyansh priyansh 16200 Aug 29 16:14 9op
-rw-rw-r-- 1 priyansh priyansh    40 Aug 29 15:21 dest_7.txt
-rw-rw-r-- 1 priyansh priyansh    40 Aug 29 15:12 source_7.txt
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./27op 
What is your choice to use to execute ls -Rl, 1)execl 2)execlp 3)execle 4)execv  5)execvp
4
.:
total 688
-rw-rw-r-- 1 priyansh priyansh  3206 Aug 30 17:48 10.c
-rwxrwxr-x 1 priyansh priyansh 16280 Aug 29 16:26 10op
-rw-rw-r-- 1 priyansh priyansh    40 Aug 29 16:26 10.txt
-rw-rw-r-- 1 priyansh priyansh  2887 Aug 30 17:48 11a.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 29 18:26 11aop
-rw-rw-r-- 1 priyansh priyansh    42 Aug 29 18:26 11a.txt
-rw-rw-r-- 1 priyansh priyansh  1679 Aug 30 17:48 11b.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 29 18:33 11bop
-rw-rw-r-- 1 priyansh priyansh  1704 Aug 30 17:49 11c.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 29 18:36 11cop
-rw-rw-r-- 1 priyansh priyansh  3711 Aug 30 17:49 12.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 29 18:43 12op
-rw-rw-r-- 1 priyansh priyansh    23 Aug 29 18:42 12.txt
-rw-rw-r-- 1 priyansh priyansh  1439 Aug 30 17:49 13.c
-rwxrwxr-x 1 priyansh priyansh 16096 Aug 30 09:48 13op
-rw-rw-r-- 1 priyansh priyansh  3007 Aug 30 17:50 14.c
-rwxrwxr-x 1 priyansh priyansh 16216 Aug 30 09:56 14op
-rw-rw-r-- 1 priyansh priyansh    17 Aug 30 09:56 14.txt
-rw-rw-r-- 1 priyansh priyansh  1446 Aug 30 10:05 15.c
-rwxrwxr-x 1 priyansh priyansh 16112 Aug 30 10:04 15op
-rw-rw-r-- 1 priyansh priyansh  2890 Aug 30 17:33 16a.c
-rwxrwxr-x 1 priyansh priyansh 16328 Aug 30 17:28 16aop
-rw-rw-r-- 1 priyansh priyansh  2642 Aug 30 17:40 16b.c
-rwxrwxr-x 1 priyansh priyansh 16352 Aug 30 17:39 16bop
-rw-rw-r-- 1 priyansh priyansh    44 Aug 30 17:38 16.txt
-rw-rw-r-- 1 priyansh priyansh   343 Aug 30 17:43 17.c
-rw-rw-r-- 1 priyansh priyansh     0 Aug 30 13:00 18a.c
-rw-rw-r-- 1 priyansh priyansh   259 Aug 30 13:06 18b.c
-rw-rw-r-- 1 priyansh priyansh  1640 Aug 30 10:22 19.c
-rwxrwxr-x 1 priyansh priyansh 16000 Aug 30 10:21 19op
-rw-rw-r-- 1 priyansh priyansh   461 Aug 30 17:47 1a.c
-rw-rw-r-- 1 priyansh priyansh  2080 Aug 30 17:51 20.c
-rwxrwxr-x 1 priyansh priyansh 16136 Aug 30 10:32 20op
-rw-rw-r-- 1 priyansh priyansh   748 Aug 30 17:51 21.c
-rwxrwxr-x 1 priyansh priyansh 16040 Aug 30 10:36 21op
-rw-rw-r-- 1 priyansh priyansh  1922 Aug 30 17:51 22.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 30 11:05 22op
-rw-rw-r-- 1 priyansh priyansh    35 Aug 30 11:06 22.txt
-rw-rw-r-- 1 priyansh priyansh  1287 Aug 30 17:51 23.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 30 11:18 23op
-rw-rw-r-- 1 priyansh priyansh  1442 Aug 30 17:51 24.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 30 11:32 24op
-rw-rw-r-- 1 priyansh priyansh  2620 Aug 30 17:52 25.c
-rwxrwxr-x 1 priyansh priyansh 16224 Aug 30 11:57 25op
-rw-rw-r-- 1 priyansh priyansh  1096 Aug 30 17:52 26.c
-rwxrwxr-x 1 priyansh priyansh 15960 Aug 30 12:19 26op
-rw-rw-r-- 1 priyansh priyansh   114 Aug 30 13:03 27b.c
-rw-rw-r-- 1 priyansh priyansh   673 Aug 31 12:03 27.c
-rw-rw-r-- 1 priyansh priyansh   116 Aug 30 13:03 27c.c
-rw-rw-r-- 1 priyansh priyansh   110 Aug 30 13:04 27d.c
-rw-rw-r-- 1 priyansh priyansh   112 Aug 30 13:04 27e.c
-rwxrwxr-x 1 priyansh priyansh 16344 Aug 31 12:04 27op
-rw-rw-r-- 1 priyansh priyansh  1004 Aug 30 17:52 28.c
-rwxrwxr-x 1 priyansh priyansh 16120 Aug 30 12:31 28op
-rw-rw-r-- 1 priyansh priyansh  1731 Aug 30 17:52 29.c
-rwxrwxr-x 1 priyansh priyansh 16248 Aug 30 12:39 29op
-rw-rw-r-- 1 priyansh priyansh  1550 Aug 30 17:50 2.c
-rwxrwxr-x 1 priyansh priyansh 16000 Aug 22 10:11 2outinfiniteloop
-rwxrwxr-x 1 priyansh priyansh 17560 Aug 23 18:58 3
-rw-rw-r-- 1 priyansh priyansh  1845 Aug 31 11:57 30.c
-rwxrwxr-x 1 priyansh priyansh 16416 Aug 30 12:51 30op
-rw-rw-r-- 1 priyansh priyansh  1268 Aug 30 17:47 3.c
-rwxrwxr-x 1 priyansh priyansh 16000 Aug 23 18:59 3_out_create_file_
-rwx------ 1 priyansh priyansh     0 Aug 23 19:01 3_out.txt
-rw-rw-r-- 1 priyansh priyansh  1372 Aug 30 17:47 4.c
-rwxrwxr-x 1 priyansh priyansh 16000 Aug 24 09:42 4opf
-rw-rw-r-- 1 priyansh priyansh  2386 Aug 30 17:47 5.c
-rwxrwxr-x 1 priyansh priyansh 16000 Aug 24 10:53 5opf
-rw-rw-r-- 1 priyansh priyansh  1144 Aug 30 17:47 6.c
-rwxrwxr-x 1 priyansh priyansh 16096 Aug 29 14:56 6op
-rw-rw-r-- 1 priyansh priyansh  3174 Aug 29 15:23 7.c
-rwxrwxr-x 1 priyansh priyansh 16304 Aug 29 15:20 7op
-rw-rw-r-- 1 priyansh priyansh  1728 Aug 30 17:48 8.c
-rwxrwxr-x 1 priyansh priyansh 16264 Aug 29 16:05 8op
-rw-rw-r-- 1 priyansh priyansh    24 Aug 29 16:05 8.txt
-rw-rw-r-- 1 priyansh priyansh  1995 Aug 30 17:48 9.c
-rwxrwxr-x 1 priyansh priyansh 16200 Aug 29 16:14 9op
-rw-rw-r-- 1 priyansh priyansh    40 Aug 29 15:21 dest_7.txt
-rw-rw-r-- 1 priyansh priyansh    40 Aug 29 15:12 source_7.txt
priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_1$ ./27op 
What is your choice to use to execute ls -Rl, 1)execl 2)execlp 3)execle 4)execv  5)execvp
5
.:
total 688
-rw-rw-r-- 1 priyansh priyansh  3206 Aug 30 17:48 10.c
-rwxrwxr-x 1 priyansh priyansh 16280 Aug 29 16:26 10op
-rw-rw-r-- 1 priyansh priyansh    40 Aug 29 16:26 10.txt
-rw-rw-r-- 1 priyansh priyansh  2887 Aug 30 17:48 11a.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 29 18:26 11aop
-rw-rw-r-- 1 priyansh priyansh    42 Aug 29 18:26 11a.txt
-rw-rw-r-- 1 priyansh priyansh  1679 Aug 30 17:48 11b.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 29 18:33 11bop
-rw-rw-r-- 1 priyansh priyansh  1704 Aug 30 17:49 11c.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 29 18:36 11cop
-rw-rw-r-- 1 priyansh priyansh  3711 Aug 30 17:49 12.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 29 18:43 12op
-rw-rw-r-- 1 priyansh priyansh    23 Aug 29 18:42 12.txt
-rw-rw-r-- 1 priyansh priyansh  1439 Aug 30 17:49 13.c
-rwxrwxr-x 1 priyansh priyansh 16096 Aug 30 09:48 13op
-rw-rw-r-- 1 priyansh priyansh  3007 Aug 30 17:50 14.c
-rwxrwxr-x 1 priyansh priyansh 16216 Aug 30 09:56 14op
-rw-rw-r-- 1 priyansh priyansh    17 Aug 30 09:56 14.txt
-rw-rw-r-- 1 priyansh priyansh  1446 Aug 30 10:05 15.c
-rwxrwxr-x 1 priyansh priyansh 16112 Aug 30 10:04 15op
-rw-rw-r-- 1 priyansh priyansh  2890 Aug 30 17:33 16a.c
-rwxrwxr-x 1 priyansh priyansh 16328 Aug 30 17:28 16aop
-rw-rw-r-- 1 priyansh priyansh  2642 Aug 30 17:40 16b.c
-rwxrwxr-x 1 priyansh priyansh 16352 Aug 30 17:39 16bop
-rw-rw-r-- 1 priyansh priyansh    44 Aug 30 17:38 16.txt
-rw-rw-r-- 1 priyansh priyansh   343 Aug 30 17:43 17.c
-rw-rw-r-- 1 priyansh priyansh     0 Aug 30 13:00 18a.c
-rw-rw-r-- 1 priyansh priyansh   259 Aug 30 13:06 18b.c
-rw-rw-r-- 1 priyansh priyansh  1640 Aug 30 10:22 19.c
-rwxrwxr-x 1 priyansh priyansh 16000 Aug 30 10:21 19op
-rw-rw-r-- 1 priyansh priyansh   461 Aug 30 17:47 1a.c
-rw-rw-r-- 1 priyansh priyansh  2080 Aug 30 17:51 20.c
-rwxrwxr-x 1 priyansh priyansh 16136 Aug 30 10:32 20op
-rw-rw-r-- 1 priyansh priyansh   748 Aug 30 17:51 21.c
-rwxrwxr-x 1 priyansh priyansh 16040 Aug 30 10:36 21op
-rw-rw-r-- 1 priyansh priyansh  1922 Aug 30 17:51 22.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 30 11:05 22op
-rw-rw-r-- 1 priyansh priyansh    35 Aug 30 11:06 22.txt
-rw-rw-r-- 1 priyansh priyansh  1287 Aug 30 17:51 23.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 30 11:18 23op
-rw-rw-r-- 1 priyansh priyansh  1442 Aug 30 17:51 24.c
-rwxrwxr-x 1 priyansh priyansh 16168 Aug 30 11:32 24op
-rw-rw-r-- 1 priyansh priyansh  2620 Aug 30 17:52 25.c
-rwxrwxr-x 1 priyansh priyansh 16224 Aug 30 11:57 25op
-rw-rw-r-- 1 priyansh priyansh  1096 Aug 30 17:52 26.c
-rwxrwxr-x 1 priyansh priyansh 15960 Aug 30 12:19 26op
-rw-rw-r-- 1 priyansh priyansh   114 Aug 30 13:03 27b.c
-rw-rw-r-- 1 priyansh priyansh   673 Aug 31 12:03 27.c
-rw-rw-r-- 1 priyansh priyansh   116 Aug 30 13:03 27c.c
-rw-rw-r-- 1 priyansh priyansh   110 Aug 30 13:04 27d.c
-rw-rw-r-- 1 priyansh priyansh   112 Aug 30 13:04 27e.c
-rwxrwxr-x 1 priyansh priyansh 16344 Aug 31 12:04 27op
-rw-rw-r-- 1 priyansh priyansh  1004 Aug 30 17:52 28.c
-rwxrwxr-x 1 priyansh priyansh 16120 Aug 30 12:31 28op
-rw-rw-r-- 1 priyansh priyansh  1731 Aug 30 17:52 29.c
-rwxrwxr-x 1 priyansh priyansh 16248 Aug 30 12:39 29op
-rw-rw-r-- 1 priyansh priyansh  1550 Aug 30 17:50 2.c
-rwxrwxr-x 1 priyansh priyansh 16000 Aug 22 10:11 2outinfiniteloop
-rwxrwxr-x 1 priyansh priyansh 17560 Aug 23 18:58 3
-rw-rw-r-- 1 priyansh priyansh  1845 Aug 31 11:57 30.c
-rwxrwxr-x 1 priyansh priyansh 16416 Aug 30 12:51 30op
-rw-rw-r-- 1 priyansh priyansh  1268 Aug 30 17:47 3.c
-rwxrwxr-x 1 priyansh priyansh 16000 Aug 23 18:59 3_out_create_file_
-rwx------ 1 priyansh priyansh     0 Aug 23 19:01 3_out.txt
-rw-rw-r-- 1 priyansh priyansh  1372 Aug 30 17:47 4.c
-rwxrwxr-x 1 priyansh priyansh 16000 Aug 24 09:42 4opf
-rw-rw-r-- 1 priyansh priyansh  2386 Aug 30 17:47 5.c
-rwxrwxr-x 1 priyansh priyansh 16000 Aug 24 10:53 5opf
-rw-rw-r-- 1 priyansh priyansh  1144 Aug 30 17:47 6.c
-rwxrwxr-x 1 priyansh priyansh 16096 Aug 29 14:56 6op
-rw-rw-r-- 1 priyansh priyansh  3174 Aug 29 15:23 7.c
-rwxrwxr-x 1 priyansh priyansh 16304 Aug 29 15:20 7op
-rw-rw-r-- 1 priyansh priyansh  1728 Aug 30 17:48 8.c
-rwxrwxr-x 1 priyansh priyansh 16264 Aug 29 16:05 8op
-rw-rw-r-- 1 priyansh priyansh    24 Aug 29 16:05 8.txt
-rw-rw-r-- 1 priyansh priyansh  1995 Aug 30 17:48 9.c
-rwxrwxr-x 1 priyansh priyansh 16200 Aug 29 16:14 9op
-rw-rw-r-- 1 priyansh priyansh    40 Aug 29 15:21 dest_7.txt
-rw-rw-r-- 1 priyansh priyansh    40 Aug 29 15:12 source_7.txt

*/