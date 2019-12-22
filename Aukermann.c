#include <stdio.h>

#define MAXSIZEM	10
#define MAXSIZEN	10000000

int memo[MAXSIZEM][MAXSIZEN];
int aukermann(int m, int n)
{
	if (memo[m][n] != -1)
		return memo[m][n];
	if (m == 0)
		return (memo[m][n] = n + 1);
	else if (n == 0)
		return (memo[m][n] = aukermann(m - 1, 1));
	else {
		memo[m][n-1] = aukermann(m, n-1);
		return (memo[m][n] = aukermann(m - 1, memo[m][n-1]));
	}
}
main()
{
	int m, n;
	int i,j;
	for (i = 0; i < MAXSIZEM; ++i)
		for (j = 0; j < MAXSIZEN; ++j)
			memo[i][j] = -1;
	scanf("%d %d", &m, &n);
	printf("%d\n", aukermann(m, n));
	return 0;
}
