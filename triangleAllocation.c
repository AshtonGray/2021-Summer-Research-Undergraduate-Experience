#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/time.h>
#include<unistd.h>
#include<time.h>

int main()
{
	// Initialize variables

	int *ptr1, *ptr2, *ptr3;
	long long int n1, n2, n3;
	unsigned long long ms;
	
	// Time
	struct timeval tv;
	time_t t;
	
	// File stuff
	FILE *fp;

	n1 = 1000000; // 125 KB
	n2 = 2000000; // 250 KB
	n3 = 4000000; // 500 KB

	// Get the PID
	pid_t pid = getpid();
	printf("pid: %1u \n", pid);
	
	// Start
	printf("Press S to Start\n");
	while(getchar() != 'S');
	
	// Open File
	fp = fopen("TriangleAllocationData.txt", "w+");
	
	fprintf(fp, "Time since last epoch, KB allocated\n");
	// Run for 3 minutes
	for(int i = 0; i < 10; i++){

		// time
		//time(&t);

		// Printing to command Prompt
		//printf("%s", ctime(&t));
		//printf("%llu KBytes being allocated\n\n", n1*sizeof(int)/8000); //500 KB

		// Allocate data for 18 seconds
		ptr1 = (int*)malloc(n1 * sizeof(int));
		gettimeofday(&tv, NULL);
		ms = (unsigned long long)(tv.tv_sec) * 1000 + (unsigned long long)(tv.tv_usec) / 1000;
		fprintf(fp, "%llu, %llu\n", ms, n1*sizeof(int)/8000); // print to file
		sleep(3);

		ptr2 = (int*)malloc(n2 * sizeof(int));
		gettimeofday(&tv, NULL);
		ms = (unsigned long long)(tv.tv_sec) * 1000 + (unsigned long long)(tv.tv_usec) / 1000;
		fprintf(fp, "%llu, %llu\n", ms, n2*sizeof(int)/8000); // print to file
		sleep(3);

		ptr3 = (int*)malloc(n3 * sizeof(int));
		gettimeofday(&tv, NULL);
		ms = (unsigned long long)(tv.tv_sec) * 1000 + (unsigned long long)(tv.tv_usec) / 1000;
		fprintf(fp, "%llu, %llu\n", ms, n3*sizeof(int)/8000); // print to file
		sleep(3);

		free(ptr3);
		sleep(3);
		free(ptr2);
		sleep(3);
		free(ptr1);
		sleep(3);
	}

	// Close the file
	fclose(fp);
	printf("Done\n");
	sleep(3);

	return 0;
}
