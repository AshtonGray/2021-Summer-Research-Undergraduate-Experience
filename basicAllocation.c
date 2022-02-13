#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/time.h>
#include<unistd.h>
#include<time.h>

int main()
{
	// Initialize variables

	int *ptr;
	long long int n1;
	
	// Time
	struct timeval tv;
	time_t t;
	
	// File stuff
	FILE *fp;

	n1 = 1000000; // 1.25 MB

	// Get the PID
	pid_t pid = getpid();
	printf("pid: %1u \n", pid);
	
	// Start
	printf("Press S to Start\n");
	while(getchar() != 'S');
	
	// Open File
	fp = fopen("BasicAllocationData.txt", "w+");
	
	fprintf(fp, "Time since last epoch, KB allocated\n");
	// Allocate for 3 Minutes
	for(int i = 0; i < 90; i++){

		// time
		time(&t);
		gettimeofday(&tv, NULL);
		unsigned long long ms = (unsigned long long)(tv.tv_sec) * 1000 + (unsigned long long)(tv.tv_usec) / 1000;

		// Printing to command Prompt
		//printf("%s", ctime(&t));
		//printf("%llu KBytes being allocated\n\n", n1*sizeof(int)/8000);

		// Printing to Text file
		fprintf(fp, "%llu, %llu\n", ms, n1*sizeof(int)/8000);

		// Allocate data
		ptr = (int*)malloc(n1 * sizeof(int));
		//n1 = n1 + 100000; // allocate in a linear fashion
		sleep(1);
		free(ptr);
		sleep(1);
	}

	// Close the file
	printf("Done");
	fclose(fp);
	sleep(3);

	return 0;
}
