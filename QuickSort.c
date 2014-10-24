#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

/*
	The loop invariant is that after each pass of the sort, the pivot element is in the correct place. 
*/

void printer(int *A, int length){
	int j;
	for (j=0; j < length; j++) {
		printf("%d\n", A[j]);
	}
}

int partition(int *A, int p, int r){
	int x, i, j, temp;
	x = A[r];
	i = p - 1;
	for(j = p; j <= r-1; j++){
		if(A[j] <= x){
			i++;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	temp = A[i+1];
	A[i+1] = A[r];
	A[r] = temp;
	return i+1;
}

void quicksort(int *A, int p, int r){
	int q;
	if(p < r){
		q = partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
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
	quicksort(sorted, 0, slength-1);
	gettimeofday(&end, NULL);
	printer(sorted,slength);
	secs  = end.tv_sec  - start.tv_sec;
	usecs = end.tv_usec - start.tv_usec;
	//printf("Time Spent: %d.%06d Microseconds\n", (int)secs, (int)usecs);
}
