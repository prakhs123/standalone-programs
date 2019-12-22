#include <stdio.h>

main()
{
	int T;
	int G;
	int N;
	int I;
	int Q;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &G);
		while (G--) {
			scanf("%d %d %d", &I, &N, &Q);
			if (N % 2 == 0) {
				printf("%d\n", N / 2);
				continue;
			}
			printf("%d\n", I == 1 ? (Q == 1 ? N / 2: (N+1) / 2) : (Q == 1 ? (N+1) / 2 : N / 2));
		}
	}
	return 0;
}
