#include <stdio.h>
#include <time.h>

main()
{
	int n, v[50], i, j, dp[1000000], S;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &v[i]);
	scanf("%d", &S);
	dp[0] = 0;
	clock_t start, end;
	double cpu_time_used;
	start = clock();
	for (i = 1; i <= S; i++) {
		dp[i] = 1000000000;
		for (j = 0; j < n; j++)
			if (v[j] <= i && dp[i-v[j]] + 1 < dp[i])
				dp[i] = dp[i-v[j]] + 1;
	}
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("%f\n", cpu_time_used);
	return 0;
}
