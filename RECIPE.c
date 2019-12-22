#include <stdio.h>

main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int i, n, a[60], b[60], gcd = 1;
		scanf("%d", &n);
		for (i = 0; i < n ; i++)
			scanf("%d", &a[i]);
		for (i = 0; i < n ; i++)
			b[i] = a[i];
		for (i = 1; i < n; i++) {
			while (a[i-1] != a[i])
				if (a[i-1] > a[i])
					a[i-1]-=a[i];
				else
					a[i]-=a[i-1];
			gcd = a[i-1];
			a[i] = gcd;
		}
		for (i = 0; i < n - 1 ; i++)
			printf("%d ", b[i] / gcd);
		printf("%d\n", b[n-1] / gcd);
	}
}
