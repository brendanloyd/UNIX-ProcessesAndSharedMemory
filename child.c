#include "child.h"

int main(int argc, char** argv) {

	int segment_id = shmget(SHMKEY, BUFF_SZ, 0777);
        if (segment_id == -1) {
                perror("Error: child.c : shared memory failed.");
        }	
	int* shared_memory = (int*)(shmat(segment_id, 0, 0));
	if (shared_memory == NULL) {
                perror("Error: child.c : shared memory attach failed.");
        }

	printf("\nChild_pid %d : Iteration %d  : Incrementing by %d\n", getpid(), atoi(argv[1]), atoi(argv[2]));
	//printf("My process id is: %d\n",getpid());
	//printf(" I got %d arguments: \n", argc);
	//printf("Memory segment is: %i\n", segment_id);

	//printf("The clock increment is: %i\n", atoi(argv[2]));

	//shared_memory = shared_memory + atoi(argv[2]); 
	*shared_memory = *shared_memory + atoi(argv[2]);
	printf("Clock value is: %d\n", *shared_memory);	

	//for (i =0; i < argc; i++)
	//	printf("|%s| ", argv[i]);

	printf("Child is now ending.\n\n");
	shmdt(shared_memory);
	//sleep(3);
	return EXIT_SUCCESS;
}
