#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

//time segments taken from http://stackoverflow.com/questions/9871071/why-c-clock-returns-0

// The Loop invariant is that you always know that 
// everything before the last sorted int is in order
// starting with the very first index.

int main() {
	struct timeval start, end;
	long secs, usecs;
	
	int sorted[100000];
	int i, j, k, key, slength;
	i=0;
	while ((scanf("%d", &j) >= 0) && (i<100000)){
		sorted[i++] = j;
	}
	slength = i;
	gettimeofday(&start, NULL);
	for (j=1 ; j < slength ; j++){
		key = sorted[j];
		i = j - 1;
		while (i >= 0 && sorted[i] > key) {
			sorted[i+1] = sorted[i];
			i = i - 1;
		}
		sorted[i+1] = key;
	}
	gettimeofday(&end, NULL);
	
	secs  = end.tv_sec  - start.tv_sec;
	usecs = end.tv_usec - start.tv_usec;
	printf("Time Spent: %d.%06d Seconds\n", (int)secs, (int)usecs);
}