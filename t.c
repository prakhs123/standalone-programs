#include <stdio.h>

int dp[1001];
int pre() {
	int i;
	dp[1] = 0;
	for	(i = 2; i <= 1000; i++) {
		if (i&1)
			dp[i] = 1 + dp[i-1];
		else
			dp[i] = 1 + (dp[i-1] < dp[i/2] ? dp[i-1] : dp[i/2]);
	}
	for	(i = 1; i<= 1000; i++) {
		printf("%d: %d\n", i, dp[i]);
	}
}

int main() {
	pre();
	int i, j, k, c;
	for (i = 1; i <= 1000; i++) {
		c =1001;
		int x, y;
		for (j = 1; j < i; j++) {
			if (c > dp[j] + dp[i-j]) {
				c = dp[j] + dp[i-j];
				x = j;
				y = i-j;
			}
		}
		printf("%d: %d %d %d\n", i, c, x, y);
	}
	return 0;
}