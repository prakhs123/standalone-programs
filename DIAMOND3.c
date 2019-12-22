#include <stdio.h>

#define MAXN	2000
#define ALICE	0
#define BOB		1

double dp[MAXN+1][MAXN+1][2];

int main() {
	int T, N;
	int V[MAXN+1];
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		int i, j;
		for (i = 1; i <= N; i++) {
			scanf("%d", &V[i]);
			dp[i][i][ALICE] = (double)V[i];
			dp[i][i][BOB] = 0.0;
		}
		int l;
		for (l = 2; l <= N; l++) {
			for (i = 1; i <= N-l+1; i++) {
				j = i + l - 1;
				dp[i][j][ALICE] = 0.5 * (V[i] + dp[i+1][j][BOB] + V[j] + dp[i][j-1][BOB]);
				dp[i][j][BOB] = 0.5 * (dp[i+1][j][ALICE] + dp[i][j-1][ALICE]);
				//printf("%d %d: %f %f\n", i, j, dp[i][j][ALICE], dp[i][j][BOB]);
			}
		}
		printf("%f\n", dp[1][N][ALICE]);
	}
	return 0;
}