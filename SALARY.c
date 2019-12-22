#include <stdio.h>

inline void scan(int *a) {
	register char c=0;
	while (c < 33)
		c = getchar_unlocked();
	*a = 0;	
	while (c > 33) {
		*a = *a * 10 + c - '0';
		c = getchar_unlocked();
	}
}

void shellsort(int a[], int n) {
	unsigned int gaps[] = {57, 23, 10, 4, 1};
	int i, j, k, temp;
	int gap;
	
	for (k = 0; k < 5; k++) {
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

main()
{
	int N, t, i, result;
	int a[101];
	scan(&t);
	while (t--) {
		scan(&N);
		for (i = 0; i < N; i++)
			scan(&a[i]);
		shellsort(a, N);
		for (i = 0, result = 0; i < N-1; i++)
			result += (a[i+1]-a[i]) * (N-1-i);
		printf("%d\n", result);
	}
	
	return 0;
}
