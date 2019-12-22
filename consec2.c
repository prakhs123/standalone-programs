#include <stdio.h>

main() {
	int n, i;
	int a[1000];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int sum = 0;
	int max = -1;
	int max_neg = -1000000000;
	for (i = 0; i < n; i++) {
		sum += a[i];
		if (sum < 0)
			sum = 0;
		if (sum > max)
			max = sum;
		if (a[i] > max_neg)
			max_neg = a[i];
	}
	if (max == 0)
		printf("%d\n", max_neg);
	else
		printf("%d\n", max);
	sum = 0;
	int min = 1;
	int max_pos = 1000000000;
	for (i = 0; i < n; i++) {
		sum += a[i];
		if (sum > 0)
			sum = 0;
		if (sum < min)
			min = sum;
		if (a[i] < max_pos)
			max_pos = a[i];
	}
	if (min == 0)
		printf("%d\n", max_pos);
	else
		printf("%d\n", min);
	return 0;
}
