#include <stdio.h>

#define	N	501

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
	int t, n, H[N], K[N], dp[2*N-1];
	int i, j, sum, max;
	
	scan(&t);
	while (t--) {
		scan(&n);
		max = 0;
		for (i = 0; i < n; i++) {
			scan(&H[i]);
			if (max < 2*H[i])
				max = 2*H[i];
		}
		for (i = 0; i < n; i++)
			scan(&K[i]);
		
		dp[0] = 0;
		for (i = 1; i <= max; i++) {
			dp[i] = 1000000000;
			for (j = 0; j < n; j++)
				if (K[j] <= i && dp[i-K[j]] + 1 < dp[i])
					dp[i] = dp[i-K[j]] + 1;
		}
		
		sum = 0;
		for (i = 0; i < n; i++)
			sum += dp[2*H[i]];
		
		printf("%d\n", sum);
	}
	
	return 0;
}
