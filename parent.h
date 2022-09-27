#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void terminateSigHandler(int);
void timeoutSigHandler(int); 

extern int errno;

