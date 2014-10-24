#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>



void printer(int *A, int length){
	int j;
	for (j=0; j < length; j++) {
		printf("%d\n", A[j]);
	}
}

void countsort(int* A, int length){
	int tally[101] = { 0 };
	int i, r, x;
	for(i=0; i < length; i++){
		x = A[i];
		tally[x] = tally[x] + 1;
	}
	r = 0;
	for(i=0; i < 101 && r < length; i++){
		while(tally[i] > 0){
			A[r] = i;
			r++;
			tally[i] = tally[i] - 1;
		}
	}
}


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
	countsort(sorted, slength);
	gettimeofday(&end, NULL);
	secs  = end.tv_sec  - start.tv_sec;
	usecs = end.tv_usec - start.tv_usec;
	printf("Time Spent: %d.%06d Microseconds\n", (int)secs, (int)usecs);
}
