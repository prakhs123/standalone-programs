#include <stdio.h>

char cars[10][55];

int nCr(int n, int r)
{
	if (r > n)
		return 0;
	if (r == 0)
		return 0;
	if (r > n/2)
		r = n - r;
	int i;
	int temp1 = 1, temp2 = 1;
	for (i = 1; i <= r; i++) {
		temp1 *= i;
		temp2 *= n--;
	}
	
	return temp2/temp1;
}

main()
{
	int X, N;
	scanf("%d %d\n", &X, &N);
	int i, j, k;
	for (i = 0; i < N; i++)
		scanf("%s", cars[i]);
	int count = 0;
	for (i = 0; i < N; i++) {
		for (j = 1; j <= 9; j++) {
			int freespaces = 0;
			int t1 = 4 * j;
			int t2 = 4 * (j-1);
			for (k = t1; k > t2; k--)
				if (cars[i][k-1] == '0')
					freespaces++;
			t1 = 54 - 2 * j;
			for (k = t1+1, t2 = 1; t2 <= 2; k++, t2++)
				if (cars[i][k-1] == '0')
					freespaces++;
			count += nCr(freespaces, X);
		}
	}
	printf("%d\n", count);
}
