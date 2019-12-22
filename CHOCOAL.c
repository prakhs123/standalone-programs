#include <stdio.h>
void shellsort(int a[], int n) {
	unsigned int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
	
	int i, j, k, temp;
	int gap;
	
	for (k = 0; k < 8; k++) {
		gap = gaps[k];
		for (i = gap; i < n; i++) {
			temp = a[i];
			for (j = i; j >= gap && a[j-gap] > temp; j -= gap)
				a[j] = a[j-gap];
			a[j] = temp;
		}
	}
	
	return;
}
int solve(int a[], int t, int K, int N)
{
	int i, count = 0;
	for (i = N-1; i >= 0; i--) {
		if (a[i] == t)
			count++;
		if (a[i] < t)
			break;
	}
	for (; i >= 0; i--) {
		if (K >= t-a[i]) {
			K -= t - a[i];
			count++;
		}
		else
			break;
	}
	return count;
}
main()
{
	int N, K, i, j;
	int a[100010], min, max, M;
	scanf("%d %d\n", &N, &K);
	for (i = 0, min = 100000000, max = 0; i < N; i++) {
		scanf("%d", &a[i]);
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	shellsort(a, N);
	for (i = min, M = 0; i <= max + K; i++) {
		j = solve(a,i,K,N);
		if (j > M)
			M = j;
	}
	printf("%d\n", M);
}
