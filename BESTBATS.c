#include <stdio.h>

int nCr(int n, int r)
{
	if (r > n/2)
		r = n - r;
	int i;
	int temp1 = 1, temp2 = 1;
	for (i = 1; i <= r; i++) {
		temp1 *= i;
		temp2 *= n--;
	}
	
	return temp2/temp1;
}

void shellsort(int a[], int n) {
	unsigned int gaps[] = {10, 4, 1};
   
	
	int i, j, k, temp;
	int gap;
	
	for (k = 0; k < 3; k++) {
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

int count (int a[], int s) {
	int i, count = 0;
	for (i = 0; i < 11; i++)
		if (a[i] == s)
			count++;
	return count;
}
main()
{
	int scores[11], K, T, i, minscore, countminscore, noofminscore;
	scanf("%d", &T);
	while (T--) {
		for (i = 0; i < 11; i++)
			scanf("%d", &scores[i]);
		scanf("%d", &K);
		shellsort(scores, 11);
		minscore = scores[11-K];
		countminscore = count(scores, minscore);
		noofminscore = 0;
		for (i = 11-K; i < 11; i++)
			if (scores[i] == minscore)
				noofminscore++;
			else
				break;
		printf("%d\n", nCr(countminscore, noofminscore));
	}
	return 0;
}
