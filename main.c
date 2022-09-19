#include "main.h"

int main(int argc, char **argv) {
	int option, totalChildProcesses, childrenRunningAtOneTime, clockIncrement;
        while ((option = getopt(argc, argv, "hn:s:m:")) != -1) {
                switch (option) {
                        case 'h' :
                                printf("To run this program please use the following format:\n");
                                printf("./oss [-h] [-n] [-s] [-m]\nWhere [-n] [-s] [-m] require arguments.\n");
                                return 0;

                        case 'n' :

				totalChildProcesses = (atoi(optarg));
                                printf("Total number of child processes to be ran is: %i\n", totalChildProcesses);
				break;
			case 's' :
				childrenRunningAtOneTime = (atoi(optarg));
				printf("Total children that will be running at one time: %i\n", childrenRunningAtOneTime);
				break;
			case 'm' :
				clockIncrement = (atoi(optarg));
				printf("Each child will increment the clock: %i times.\n", clockIncrement);
				break;
                        case '?':
                                printf("Driver : main : Invalid option.\n");
                                exit(-1);

                        default :
                                printf("Driver : main : Invalid argument\n");
                                return 0;
                }
        }
	return 0;
}
