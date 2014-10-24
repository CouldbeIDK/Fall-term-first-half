#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

int Parent(int i){
	return i/2;
}

int Left(int i){
	return 2 * i;
}

int Right(int i){
	return 2*i - 1;
}

void printer(int *A, int length){
	int j;
	for (j=0; j < length; j++) {
		printf("%d\t", A[j]);
	}printf("\n");
}

void MaxHeapify(int * A,int i){
	int l,r,largest,hold;
	l = Left(i);
	r = Right(i);
	if (l <= A[0] && A[l] > A[i]){
		largest = l;
	}else{
		largest = i;
	}
	if (r <= A[0] && A[r] > A[largest]){
		largest = r;
	}
	printf("A[%d] %d \t A[%d] %d \t largest: A[%d] %d\n", l, A[l], r, A[r], largest, A[largest]);
	if (largest != i){
		hold = A[i];
		A[i] = A[largest];
		A[largest] = hold;
		MaxHeapify(A, largest);
	}
	printer(A,A[0]);
}

BuildMaxHeap(int *A, int length){
	int i;
	A[0] = length;
	for(i = A[0] / 2; i >= 1; i--){
		MaxHeapify(A,i);
	}
}

HeapSort(int *A, int length){
	int i, temp;
	BuildMaxHeap(A, length);
	for(i = length; i >= 2; i--){
		temp = A[1];
		A[1] = A[i];
		A[i] = temp;
		A[0] = A[0] - 1;
		MaxHeapify(A,1);
	}
	A[0] = length;
}

int main() {
	struct timeval start, end;
	long mtime, secs, usecs;
	int sorted[100001];
	int i, j, k, key, slength;
	sorted[0] = 0;
	i=0;
	while ((scanf("%d", &j) >= 0) && (i<100000)){
		sorted[++i] = j;
	}
	slength = i;
	gettimeofday(&start, NULL);
	HeapSort(sorted, slength);
	gettimeofday(&end, NULL);
	printer(sorted, sorted[0] + 1);
	secs  = end.tv_sec  - start.tv_sec;
	usecs = end.tv_usec - start.tv_usec;
	printf("Time Spent: %d.%06d Microseconds\n", (int)secs, (int)usecs);
}