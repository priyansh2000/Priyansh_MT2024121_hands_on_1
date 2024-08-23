//Priyansh Rai
// MT2024021
/*
	Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
*/
	
#include <stdio.h>
#include <unistd.h>

int main() {
    while (1) {
        sleep(1);  // Sleep for 1 second to reduce CPU usage
        printf("hello");

    }
    return 0;
}
/* 
gcc -o infiniteloop 2.c
./infiniteloop &
ps aux | grep infiniteloop //getting pid

cd/proc/42069
cat status
Name:	infiniteloop
Umask:	0002
State:	S (sleeping)
Tgid:	42069
Ngid:	0
Pid:	42069
PPid:	3831
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000
FDSize:	256
Groups:	4 24 27 30 46 100 118 1000 
NStgid:	42069
NSpid:	42069
NSpgid:	42069
NSsid:	3831
VmPeak:	    2616 kB
VmSize:	    2616 kB
VmLck:	       0 kB
VmPin:	       0 kB
VmHWM:	    1280 kB
VmRSS:	    1280 kB
RssAnon:	       0 kB
RssFile:	    1280 kB
RssShmem:	       0 kB
VmData:	     224 kB
VmStk:	     132 kB
VmExe:	       4 kB
VmLib:	    1672 kB
VmPTE:	      44 kB
VmSwap:	       0 kB
HugetlbPages:	       0 kB
CoreDumping:	0
THP_enabled:	1
Threads:	1
SigQ:	1/29087
SigPnd:	0000000000000000
ShdPnd:	0000000000000000
SigBlk:	0000000000000000
SigIgn:	0000000000000000
SigCgt:	0000000000000000
CapInh:	0000000000000000
CapPrm:	0000000000000000
CapEff:	0000000000000000
CapBnd:	000001ffffffffff
CapAmb:	0000000000000000
NoNewPrivs:	0
Seccomp:	0
Seccomp_filters:	0
Speculation_Store_Bypass:	thread vulnerable
SpeculationIndirectBranch:	conditional enabled
Cpus_allowed:	ffff


*/