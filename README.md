# UNIX-ProcessesAndSharedMemory

Proper call of this program is 

./oss -n 4 -s 2 -m 10


-n: number of processes to be ran

-s: number of processes allowed to be run at one time

-m: how much each process will increment the clock

Shortcomings: I was unable to get the cap of how many processes that are allowed to be ran at one time working properly.
I commented out my attempt in the parent.c file and in place put an if statement only allowing 18 or less as an input
for the -n and -s arguments. This will prevent a fork bomb on the hoare server.

git log

Commits on Sep 29, 2022
Final push ✨

brendan loyd committed 5 minutes ago
 
Commits on Sep 28, 2022
timed sig handling and deallocating memory

brendan loyd committed 22 hours ago
 
Commits on Sep 27, 2022
shared memory offically working, signal handler for ctrl c also

brendan loyd committed 2 days ago
 
Passing arguments to children, error handling, and signal interupts

brendan loyd committed 2 days ago
 
Commits on Sep 19, 2022
getopt implemented

brendan loyd committed 10 days ago
 
Commits on Sep 18, 2022
initial commit with Makefile and main files

brendan loyd committed 11 days ago
 
Initial commit

@brendanloyd
brendanloyd committed 11 days ago
