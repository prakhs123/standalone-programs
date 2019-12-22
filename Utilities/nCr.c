#include <stdio.h>

#define LL long long
LL nCr(LL n, LL r)
{
	if (r > n/2)
		r = n - r;
	LL i;
	LL temp1 = 1, temp2 = 1;
	for (i = 1; i <= r; i++) {
		temp1 *= i;
		temp2 *= n--;
	}
	
	return temp2/temp1;
}

main()
{
	LL n, r, i;
	for (i = 1; i <= 64; ++i)
	{
		/* code */
		printf("%lld,", nCr(i, i/2));
	}
	return 0;
}
