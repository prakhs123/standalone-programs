#include <stdio.h>

#define MAXN	100000

int minp[MAXN + 1];

int gcd(int a, int b)
{
	int t;
	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
	}
	
	return a;
}

main()
{
	int t, n;
	int a[MAXN];
	int i, j;
	int g;
	int answer;
	minp[1] = -1;
	for (i = 2; i < MAXN+1; i++)
		if (minp[i] == 0)
			for (j = i; j < MAXN+1; j+=i)
				if (minp[j] == 0)
					minp[j] = i;
	scanf("%d", &t);
	while (t--) {
		
		scanf("%d", &n);
		g = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			g = gcd(a[i], g);
		}
		
		answer = minp[g];
		printf("%d\n", answer);
	}
	
	return 0;
}
			
