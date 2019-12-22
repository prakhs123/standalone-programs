#include <stdio.h>

#define	N 40

int pascalTriangle[N][N];

void create(void) {
	int i, j;
	
	pascalTriangle[0][0] = 1;
	
	for (i = 1; i < N; i++)
		for (j = 1, pascalTriangle[i][0] = 1, pascalTriangle[i][i] = 1; j < i; j++)
			pascalTriangle[i][j] = pascalTriangle[i-1][j] + pascalTriangle[i-1][j-1];
}

main()
{
	create();
	int n, r;
	scanf("%d %d", &n, &r);
	printf("%d\n", pascalTriangle[n][r]);
	
	return 0;
}
