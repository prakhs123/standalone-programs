#include <stdio.h>

main()
{
	long long n, m, a;
	scanf("%lld %lld %lld", &n, &m, &a);
	long long x, y;
	if (m % a == 0)
		x = m/a;
	else
		x = m/a+1;
	if (n % a == 0)
		y = n/a;
	else
		y = n/a+1;
	printf("%lld\n", x*y);
	return 0;
}
