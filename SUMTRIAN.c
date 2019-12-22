#include <stdio.h>

int a[99][99];
int bs[99][99] = {0};
int n;
int bestsum(int i, int j)
{
	if (i == n-1)
		return (bs[i][j] = a[i][j]);
	if (bs[i][j] != 0)
		return bs[i][j];
	int t1 = a[i][j] + (bs[i+1][j] = bestsum(i+1, j));
	int t2 = a[i][j] + (bs[i+1][j+1] = bestsum(i+1, j+1));

	return (bs[i][j] = t1>t2 ? t1 : t2);
}
main()
{
	int t;
	scanf("%d", &t);
	int i, j;
	while (t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			for (j = 0; j <= i; j++)
				scanf("%d", &a[i][j]);
		printf("%d\n", bestsum(0,0));
		for (i = 0; i < n; i++)
			for (j = 0; j <= i; j++)
				bs[i][j] = 0;
	}
	return 0;
}
