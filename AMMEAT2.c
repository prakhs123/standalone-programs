include <stdio.h>
#define ull unsigned long long

main()
{
	int T, N;
	ull M, P[10], total;
	int i, j, count, mincount;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %llu", &N, &M);
		for (i = 0; i < N; i++)
			scanf("%llu", &P[i]);
		mincount = 10;
		for (i = 0; i < (1<<N); i++) {
			total = 0ull;
			count = 0;
			for (j = 0; j < N; j++)
				if ((1<<j) & i) {
					count++;
					total += P[j];
				}
			if (count < mincount && total >= M)
				mincount = count;
		}
		if (mincount == 10)
			printf("-1\n");
		else
			printf("%d\n", mincount);
	}
	return 0;
}
