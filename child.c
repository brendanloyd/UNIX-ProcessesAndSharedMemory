#include "child.h"

int main(int argc, char** argv) {
	int i;
	int segment_id = atoi(argv[1]);
	
	printf("Hello from Child.c, ia new executable!\n");

	int *shared_memory = (int*) shmat(segment_id, NULL, 0);
	if (shared_memory == NULL) {
                perror("Error: child.c : shared memory attach failed.");
        }
	//printf("My process id is: %d\n",getpid());
	//printf(" I got %d arguments: \n", argc);
	//printf("Memory segment is: %i\n", segment_id);

	printf("The clock increment is: %i\n", atoi(argv[2]));

	//shared_memory = shared_memory + atoi(argv[2]); 

	printf("Clock value is: %i\n",&shared_memory);	

	for (i =0; i < argc; i++)
		printf("|%s| ", argv[i]);

	printf("\nChild is now ending.\n");
	sleep(3);
	return EXIT_SUCCESS;
}
