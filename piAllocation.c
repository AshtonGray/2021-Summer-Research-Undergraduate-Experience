#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/time.h>
#include<unistd.h>
#include<time.h>

int main()
{
	// Initialize variables

	// pi stuff
	int r[2800 + 1];
	int i, k;
	int b, d;
	int c = 0;

	int *ptr, *ptr1;
	long long int n1;
	
	// Time
	struct timeval tv;
	time_t t;
	
	// File stuff
	FILE *fp;

	n1 = 1000000; // 125 MB

	// Get the PID
	pid_t pid = getpid();
	printf("pid: %1u \n", pid);
	
	// Start
	printf("Press S to Start\n");
	while(getchar() != 'S');
	
	// Open File
	fp = fopen("piAllocation.txt", "w+");
	
	fprintf(fp, "Time since last epoch, KB allocated\n");

	// Allocate for 30 Seconds
	for(int j = 0; j < 15; j++){

		// time
		time(&t);
		gettimeofday(&tv, NULL);
		unsigned long long ms = (unsigned long long)(tv.tv_sec) * 1000 + (unsigned long long)(tv.tv_usec) / 1000;

		// Printing to command Prompt
		//printf("%s", ctime(&t));
		printf("%llu KBytes being allocated\n\n", n1*sizeof(int)/8000);

		// Printing to Text file
		fprintf(fp, "%llu, %llu\n", ms, n1*sizeof(int)/8000);

		// Allocate data
		ptr = (int*)malloc(n1 * sizeof(int)); // 500 KB

		// calculate pi
		for (i = 0; i < 2800; i++) {
			r[i] = 2000;
		}

		for (k = 2800; k > 0; k -= 14) {
			d = 0;
			i = k;
			ptr1 = (int*)malloc(n1 * sizeof(int)); // 500 KB
			for (;;) {
				
				d += r[i] * 10000;
				b = 2 * i - 1;

				r[i] = d % b;
				d /= b;
				i--;
				if (i == 0) break;
				d *= i;
			}
			//printf("%.4d", c + d / 10000);
			c = d % 10000;
			usleep(100);
			free(ptr1);
		}

		sleep(1);
		free(ptr);
		sleep(1);
	}

	// Close the file
	fclose(fp);
	sleep(3);

	

	return 0;
}

