#include <stdio.h>

main() {
	int n, i;
	int a[1000];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int start = -1;
	int end = -1;
	int current = -1;
	int sum = 0;
	int max = -1;
	int max_neg = -1000000000;
	for (i = 0; i < n; i++) {
		sum += a[i];
		if (sum < 0) {
			sum = 0;
			current = i+1;
		}
		if (sum > max) {
			max = sum;
			start = current;
			end = i;
		}
		if (a[i] > max_neg)
			max_neg = a[i];
	}
	if (start > end)
		printf("%d\n", max_neg);
	else {
		printf("%d %d\n", start, end);
		printf("%d\n", max);
	}
	return 0;
}
