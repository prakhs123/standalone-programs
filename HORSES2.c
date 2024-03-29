#include <stdio.h>

main()
{
	int t;
	int horses[5000];
	int n;
	int i, j, k;
	int diff;
	int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
	int temp;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &horses[i]);
		for (k = 0; k < 8; k++)
			for (i = gaps[k]; i < n; ++i) {
				temp = horses[i];
				for (j = i; j >= gaps[k] && horses[j-gaps[k]] > temp; j -= gaps[k])
					horses[j] = horses[j-gaps[k]];
				horses[j] = temp;
			}
		diff = horses[1] - horses[0];
		for (i = 2; i < n; i++)
			if (horses[i] - horses[i-1] < diff)
				diff = horses[i] - horses[i-1];
		printf("%d\n", diff);
		
	}
	return 0;
}
