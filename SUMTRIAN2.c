#include <stdio.h>

inline void scan(int *a) {
	register char c=0;
	while (c < 33)
		c = getchar_unlocked();
	*a = 0;	
	while (c > 33) {
		*a = *a * 10 + c - '0';
		c = getchar_unlocked();
	}
}

main()
{
	int T;
	scan(&T);
	while (T--) {
		int n;
		scan(&n);
		int a[100][100];
		int i, j;
		for (i = 0; i < n; i++)
			for (j = 0; j <= i; j++)
				scan(&a[i][j]);
		for (i = n-2; i >= 0; i--)
			for (j = 0; j <= i; j++)
				a[i][j] += a[i+1][j] > a[i+1][j+1] ? a[i+1][j] : a[i+1][j+1];
		printf("%d\n", a[0][0]);
	}
	return 0;
}
