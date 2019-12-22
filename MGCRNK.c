#include <stdio.h>

inline void scan(int *a) {
	register char c=0;
	register char sign = 1;
	while (c < 33)
		c = getchar_unlocked();
	*a = 0;
	if (c == 45) {
		sign = -1;
		c = getchar_unlocked();
	}	
	while (c > 33) {
		*a = *a * 10 + c - '0';
		c = getchar_unlocked();
	}
	*a = *a * sign;
}

#define N	101

main()
{
	int t, i, j, n;
	int a[N][N];
	scan(&t);
	while (t--) {
		scan(&n);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				scan(&a[i][j]);
				
		for (i = n - 2; i >= 0; i--) {
			a[n-1][i] += a[n-1][i+1];
			a[i][n-1] += a[i+1][n-1];
		}
		
		for (i = n - 2; i >= 0; i--)
			for (j = n - 2; j >= 0; j--)
				a[i][j] += a[i+1][j] > a[i][j+1] ? a[i+1][j] : a[i][j+1];
		
		if (a[0][0] < 0)
			printf("Bad Judges\n");
		else
			printf("%f\n", a[0][0] / (2.0 * n - 3.0));
	}
	
	return 0;
}
