#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <sys/time.h>
#include <unistd.h>

/*

The Loop Invariant is that the top number of any
half of the array is always the lowest number in
the list. Even if the top is taken off.

*/
void MERGE(int *A,int p,int q,int r){
	int na = q - p + 2;
	int nb = r - q + 1;
	int L[na], R[nb], i, j, k;
	for(i = 0; i < na ; i++){
		L[i] = A[p+i];
		//printf("L %d ; i %d\n", L[i], i);
	}
	for(j = 0; j < nb ; j++){
		R[j] = A[q+1+j];
		//printf("R %d ; j %d\n", R[j], j);
	}
	L[na-1] = INT_MAX;
	R[nb-1] = INT_MAX;
	i = 0;
	j = 0;
	for (k = p; k <= r ; k++){
		if (L[i] <= R[j]){
			A[k] = L[i];
			//printf("A[%d] %d; L[%d] %d;\n", k, A[k], i, L[i]);
			i = i + 1;
		}else{
			A[k] = R[j];
			//printf("A[%d] %d; R[%d] %d;\n", k, A[k], j, R[j]);
			j = j + 1;
		}
	}
}

void MERGESORT(int *A, int p, int r){
	int k;
	if (p < r) {
		int q = (p + r)/2;
		//printf("%d %d %d\n", p, q, r);
		MERGESORT(A,p,q);
		MERGESORT(A,q + 1, r);
		MERGE(A,p,q,r);
		//printf("end %d %d %d\n", p, q, r);
		for (k=p ; k <= r ; k++){
			//printf("%d, ", A[k]);
		}
		//printf("\n");
	}
}

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
	
	gettimeofday(&start,NULL);
	MERGESORT(sorted, 0, slength-1);
	gettimeofday(&end,NULL);
	
	secs  = end.tv_sec  - start.tv_sec;
	usecs = end.tv_usec - start.tv_usec;
	printf("Time Spent: %d.%06d Seconds\n", (int)secs, (int)usecs);
}