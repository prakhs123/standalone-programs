#include <stdio.h>
#define ull unsigned long long
ull gcd(ull a, ull b)
{
	ull t;
	while (b != 0ull) {
		t = b;
		b = a % b;
		a = t;
	}
	
	return a;
}

main()
{
	int t;
	ull a, b, g;
	scanf("%d", &t);
	while (t--) {
		scanf("%llu %llu", &a, &b);
		if (a == 0ull || b == 0ull) {
			printf("0\n");
			continue;
		}
		g = gcd(a,b);
		a = a/g;
		b = b/g;
		printf("%llu\n", (a+b-1ull)*g);
	}
	return 0;
}
