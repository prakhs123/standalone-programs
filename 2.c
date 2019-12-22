#include <stdio.h>
#include <math.h>
#define ull unsigned long long
int a[10000];

void find(ull num)
{
	ull i;
	ull sqr = sqrt(num);
	for (i = 2; i <= sqr; i++) {
		while (num % i == 0) {
			printf("%lld ", i);
			num = num / i;
		}
	}
}

main()
{
	find (1010824870255200ull);
	return 0;
}
