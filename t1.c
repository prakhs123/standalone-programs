#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isprime[100001];
int compute[100002];
int comp(long long m, long long n) {
	int i, diff, j;
	long long sqr = sqrt(n);
	diff = n-m;
	for (i = 0; i <= 100000; ++i)
	{
		compute[i] = 1;
	}
	for (i = 2; i <= sqr; ++i)
	{
		if (isprime[i]) {
			j = m%i;
			if (j != 0)
				j = i-j;
			for ( ; j <= diff; j += i)
				compute[j] = 0;
		}
	}
	for (i = 0; i <= diff; i++)
		if (compute[i])
			printf("%lld\n", m+i);
	return 0;
}

int main() {
	int i, size, j, t;
	long long m, n;
	size = sqrt(100000);
	isprime[0] = isprime[1] = 0;
	for (i = 2; i <= 100000; i++)
		if (isprime[i]) {
			j = i*i;
			for ( ; j <= 100000; j += i)
				comp(m, n);
			else {
				for (i = m; i <= n; i++)
					if (isprime[i])
						printf("%d\n", i);
			}
		}
	return 0;
}
