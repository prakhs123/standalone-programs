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
	int n;
	while (scanf("%d", &n) != EOF) {
		int m[n][n], color[n][n], i, j, k, l, q;
		for (i = 0; i < n; i++)
			scan(&color[i][i]);
		for (i = 0; i < n; i++)
			for (j = i+1; j < n; j++)
				color[i][j] = (color[i][j-1] + color[j][j]) % 100;
		for (i = 0; i < n; i++)
			m[i][i] = 0;
		for (l = 2; l <= n; l++)
			for (i = 0; i < n-l+1; i++) {
				j = i+l-1;
				m[i][j] = 1000000;
				for (k = i; k < j; k++) {
					q = m[i][k] + m[k+1][j] + color[i][k] * color[k+1][j];
					if (q < m[i][j])
						m[i][j] = q;
				}
			}
		printf("%d\n", m[0][n-1]);
	}
	return 0;
}
