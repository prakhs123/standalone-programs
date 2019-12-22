#include <stdio.h>
#include <stdlib.h>

main()
{
	int **p;
	int n;
	scanf("%d", &n);
	p = (int **) malloc (sizeof(int *) * n);
	int i, j;
	for (i = 0; i < n; i++)
		p[i] = (int *) malloc (sizeof(int) * (i+1));
	for (i = 0; i < n; i++)
		for (j = 0; j <= i; j++)
			scanf("%d", &p[i][j]);
	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++)
			printf("%d ", p[i][j]);
		printf("\n");
	}
	return 0;
}
