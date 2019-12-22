#include <stdio.h>

int main() {
	int T;
	int k = 1;
	scanf("%d", &T);
	while (T--) {
		int M, N;
		int R[101], C[101];
		int lawn[101][101];
		int i, j;
		scanf("%d %d", &N, &M);
		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				scanf("%d", &lawn[i][j]);
		int max;
		for (i = 0; i < N; i++) {
			max = 0;
			for (j = 0; j < M; j++)
				if (lawn[i][j] > max)
					max = lawn[i][j];
			R[i] = max;
		}
		for (j = 0; j < M; j++) {
			max = 0;
			for (i = 0; i < N; i++)
				if (lawn[i][j] > max)
					max = lawn[i][j];
			C[j] = max;
		}
		int flag = 1;
		for (i = 0; i < N && flag; i++)
			for (j = 0; j < M; j++)
				if (lawn[i][j] != R[i] && lawn[i][j] != C[j]) {
					flag = 0;
					break;
				}
		if (flag)
			printf("Case #%d: YES\n", k);
		else
			printf("Case #%d: NO\n", k);
		k++;
	}
	return 0;
}
