#include <stdio.h>

int maxSubArraySum(int a[], int n)
{
	int i;
	int max_so_far = 0;
	int max_ending_here = 0;
	for (i = 0; i < n; i++) {
		max_ending_here += a[i];
		if (max_ending_here < 0)
			max_ending_here = 0;
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;
	}
	
	return max_so_far;
}

main()
{
	int n, i;
	int a[1000];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	printf("%d\n", maxSubArraySum(a, n));
	
	return 0;
}
