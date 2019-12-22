#include <stdio.h>
#include <time.h>

main()
{
	int n, v[50], i, j, k, dp[1000000] = { 0 }, s;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		dp[v[i]] = 1;
	}
	scanf("%d", &s);
	clock_t start, end;
	double cpu_time_used;
	start = clock();
	for (j = 2; dp[s] == 0; j++)
		for (i = 0; i < 1000000; i++)
			if (dp[i] == j-1)
				for (k = 0; k < n; k++)
					if (i+v[k] < 1000000 && dp[i+v[k]] == 0)
						dp[i+v[k]] = j;
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("%f\n", cpu_time_used);
	return 0;
}
