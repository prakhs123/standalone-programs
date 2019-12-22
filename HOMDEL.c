#include <stdio.h>

#define min(A, B)	((A) < (B) ? (A) : (B))
int D[251][251];

int main() {
	int N, M, S, G, d;
	scanf("%d", &N);
	int i, j, k;
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			scanf("%d", &D[i][j]);
	for (k = 1; k <= N; k++)
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
	scanf("%d", &M);
	while (M--) {
		scanf("%d %d %d", &S, &G, &d);
		S++;
		G++;
		d++;
		printf("%d %d\n", D[S][G] + D[G][d], D[S][G] + D[G][d] - D[S][d]);
	}
	return 0;
}