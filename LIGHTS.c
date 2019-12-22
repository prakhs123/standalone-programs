#include <stdio.h>
void shellsort(int a[], int n) {
	unsigned int gaps[] = {23, 10, 4, 1};
	
	int i, j, k, temp;
	int gap;
	
	for (k = 0; k < 4; k++) {
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
	int T, count[51], i, j, N, M, K;
	char c;
	scanf("%d\n", &T);
	while (T--) {
		scanf("%d %d %d\n", &N, &M, &K);
		for (i = 0; i < N; i++) {
			for (j = 0, count[i] = 0; j < M; j++) {
				c = getchar();
				if (c == '*')
					count[i]++;
			}
			getchar();
		}
		shellsort(count, N);
		for (i = 0; i < K; i++) {
			count[0] = M - count[0];
			int key = count[0];
			j = 1;
			while (j < N && key > count[j]) {
				count[j-1] = count[j];
				j++;
			}
			count[j-1] = key;
		}
		int sum = 0;
		for (i = 0; i < N; i++)
			sum += count[i];
		printf("%d\n", sum);
	}
	return 0;
}
