# UNIX-ProcessesAndSharedMemory

Proper call of this program is 

./oss -n 4 -s 2 -m 10


-n: number of processes to be ran

-s: number of processes allowed to be run at one time

-m: how much each process will increment the clock

Shortcomings: I was unable to get the cap of how many processes that are allowed to be ran at one time working properly.
I commented out my attempt in the parent.c file and in place put an if statement only allowing 18 or less as an input
for the -n and -s arguments. This will prevent a fork bomb on the hoare server.
