#include <stdio.h>

main()
{
	int a[10001];
	int i, j, T, N, max, temp;
	scanf("%d", &T);
	while (T--) {
		for (i = 0; i < 10001; i++)
			a[i] = 0;
		scanf("%d", &N);
		for (i = 0, j = 0, max = 0; i < N; i++) {
			scanf("%d", &temp);
			a[temp]++;
			if (max < a[temp])
				max = a[temp];
		}
		for (i = 0; i < 10001; i++)
			if (a[i] == max)
				break;
		printf("%d %d\n", i, a[i]);
	}
	return 0;
}
