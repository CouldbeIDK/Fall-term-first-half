#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

/*
get the range of the numbers

make a list the size of the range

iterate through the randomlist and increment the corresponding index by one

go through the tally list and print the index the amount of times in the index
*/

/*
Let A = a new unsorted array
let u,l = the upper and lower bounds
tally[u-l+1]
for i = 0 to A.length - 1
	x = A[i]
	tally[x-l]++
r = 0
for j = 0 to tally.length - 1
	if tally[j] > 0 then
		for tally[j]
			A[r] = l + j
			r++
*/

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
	printer(sorted, slength);
	secs  = end.tv_sec  - start.tv_sec;
	usecs = end.tv_usec - start.tv_usec;
	printf("Time Spent: %d.%06d Microseconds\n", (int)secs, (int)usecs);
}
