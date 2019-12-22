#include <stdio.h>

main()
{
	int test;	
	scanf("%d", &test);
	while (test--) {
		int i;
		int N, M;
		int chakras_count = 0;
		int chakras[2][101] = {0};
		scanf("%d %d", &N, &M);
		while (N--) {
			int c, l;
			scanf("%d %d", &c, &l);
			chakras[0][l] += c;
		}
		while (M--) {
			int c, l;
			scanf("%d %d", &c, &l);
			chakras[1][l] += c;
		}
		
		for (i = 1; i <= 100; i++)
			if (chakras[0][i] < chakras[1][i])
				chakras_count += chakras[1][i] - chakras[0][i];
		printf("%d\n", chakras_count);
	}
}
