#include <stdio.h>

main()
{
	int n, a[500], i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	int dp[500][500], b[500][500];
	for (i = 0; i < n; i++) {
		dp[i][i] = 1;
		b[i][i] = 1;
	}
	int max = 0;
	for (i = 0; i < n; i++) {
		for (j = i+1; j < n; j++) {
			if (b[j-1][i] == 1) {
				if (a[j] > a[j-1]) {
					dp[j][i] = dp[j-1][i] + 1;
					b[j][i] = 0;
				}
				else {
					dp[j][i] = dp[j-1][i];
					b[j][i] = 1;
				}
			}
			else if (b[j-1][i] == 0) {
				if (a[j] < a[j-1]) {
					dp[j][i] = dp[j-1][i] + 1;
					b[j][i] = 1;
				}
				else {
					dp[j][i] = dp[j-1][i];
					b[j][i] = 0;
				}
			}
		}
		if (max < dp[n-1][i])
			max = dp[n-1][i];
	}
	printf("%d\n", max);
}
	
