#include <stdio.h>

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

int euler(int n) {
	int i;
	int c = 0;
	for (i = 1; i <= n; i++)
		if (gcd(n,i) == 1)
			c++;
	return c;
}

int is_prime(int n) {
	int i;
	for (i = 2; i*i <= n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}

main() {
	int i;
	int k;
	for (i = 2; i <= 100; i++) {
		k = euler(i);
		printf("%d %d %d %f\n", k, i, is_prime(i), (double)k/i);
	}
	
	return 0;
}
