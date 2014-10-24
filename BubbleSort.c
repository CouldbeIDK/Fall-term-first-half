#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

//the Loop invariant is that everything before index
// i is sorted.

int main() {
	struct timeval start, end;
	long mtime, secs, usecs;
	int sorted[100000];
	int i, j, k, key, slength;
	i=0;
	while ((scanf("%d", &j) >= 0) && (i<100000)){
		sorted[i++] = j;
	}
	slength = i;
	gettimeofday(&start, NULL);
	for(i=0; i <= slength - 2; i++){
		for(j=(slength-1); j >= i+1; j--){
			if (sorted[j] < sorted[j-1]){
				key = sorted[j];
				sorted[j] = sorted[j-1];
				sorted[j-1] = key;
			}
		}
	}
	gettimeofday(&end, NULL);
	
	secs  = end.tv_sec  - start.tv_sec;
	usecs = end.tv_usec - start.tv_usec;
	printf("Time Spent: %d.%06d Microseconds\n", (int)secs, (int)usecs);
}