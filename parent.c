#include "parent.h"

void terminateSigHandler(int sig) {
	if(sig == SIGTERM) {
		printf("SIGTERM signal encountered. Terminating.\n");
		exit(0);
	}	

}
void timeoutSigHandler(int sig) {
	if(sig == SIGUSR1) {
		printf("SIGUSR1 signal ecountered indicating a timeout. Terminating");
		exit(0);
	}

}

int main(int argc, char **argv) {
	int option, totalChildProcesses, childrenRunningAtOneTime, clockIncrement;
	signal(SIGTERM, terminateSigHandler);
	signal(SIGUSR1, timeoutSigHandler);

	//char *tChildProcesses;
	//char *cRunningAtOneTime;
	//char *cIncrement;
        while ((option = getopt(argc, argv, "hn:s:m:")) != -1) {
                switch (option) {
                        case 'h' :
                                printf("To run this program please use the following format:\n");
                                printf("./oss [-h] [-n] [-s] [-m]\nWhere [-n] [-s] [-m] require arguments.\n");
                                return 0;

                        case 'n' :

				totalChildProcesses = (atoi(optarg));
				//tChildProcesses = (char*)malloc(strlen(argv[optind]));
                                printf("Total number of child processes to be ran is: %i\n", totalChildProcesses);
				break;
			case 's' :
				childrenRunningAtOneTime = (atoi(optarg));
				if (childrenRunningAtOneTime > 18) {
				perror("Error: parent.c : Can't be more than 18 child processes running at one time.");
				exit(-1);

				}
				//cRunningAtOneTime = (char*)malloc(strlen(argv[optind]));
				printf("Total children that will be running at one time: %i\n", childrenRunningAtOneTime);
				break;
			case 'm' :
				clockIncrement = (atoi(optarg));
				//cIncrement = (char*)malloc(strlen(argv[optind]));
				printf("Each child will increment the clock by: %i\n", clockIncrement);
				break;
                        case '?':
                                printf("Driver : main : Invalid option.\n");
                                exit(-1);

                        default :
                                printf("Driver : main : Invalid argument\n");
                                return 0;
                
		}

        }
	int segment_id; 
	int* shared_memory; 
	struct shmid_ds shmbuffer; 
	int segment_size; 
	const int shared_segment_size = 0x6400; 

	  /* Allocate a shared memory segment.  */ 
	segment_id = shmget (IPC_PRIVATE, shared_segment_size, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
	if (segment_id == -1) {
		perror("Error: parent.c : shared memory failed.");
	}
	  /* Attach the shared memory segment.  */ 
	shared_memory = (int*)shmat(segment_id, NULL, 0);
	if (shared_memory == NULL) {
		perror("Error: parent.c : shared memory attach failed.");
	} 
	//printf ("shared memory attached at address %p\n", shared_memory); 

	  /* Determine the segment's size. */ 
	//shmctl (segment_id, IPC_STAT, &shmbuffer); 
	//segment_size = shmbuffer.shm_segsz; 
	//printf ("segment size: %d\n", segment_size); 
	
	
	  /* Set shared memory segment to 0  */
	int i = 0;

	char *seg_id;
	char *clock_Increment;
	clock_Increment = malloc(sizeof(clockIncrement));
	seg_id = malloc(sizeof(segment_id));
	//printf("the segment_id is: %i\n", segment_id);
	sprintf(seg_id, "%d", segment_id);
	//printf("the seg_id is: %s\n", seg_id);
        sprintf(clock_Increment, "%d", clockIncrement);
	
	for (i; i < totalChildProcesses; i++) {
        	pid_t childPid = fork(); // This is where the child process splits from the parent

        	if (childPid == 0) {
                	char* args[] = {"./child", seg_id, clock_Increment, 0};
                	execvp(args[0], args);
                	execlp(args[0],args[0],args[1],args[2], args[3]);
                	fprintf(stderr,"Exec failed, terminating\n");
                	exit(1);
        	} else {
                	sleep(1);
                	//wait(0);
		}
	}
                printf("Parent is now ending.\n");




	shared_memory = shared_memory + clockIncrement;
	  /* Print out the int from shared memory.  */ 
	printf ("%i\n", shared_memory); 
	
	shared_memory = shared_memory + clockIncrement;
          /* Print out the int from shared memory.  */
        printf ("%i\n", shared_memory);
	  /* Detach the shared memory segment.  */ 
	shmdt (shared_memory);

	return EXIT_SUCCESS; 
}
