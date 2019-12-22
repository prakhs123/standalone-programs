#include <stdio.h>
#include <math.h>
/* power: raise base to n-th power: n >= 0 */
long pow1(int base, int n)
{
	int i;
	long p;
	p = 1l;
	for (i = 1; i <= n; ++i)
		p = p * base;
	return p;
}
main()
{
	long int A;
	int N, k;
	scanf("%ld %d %d", &A, &N, &k);
	int a[k];	/* stores no. of particles in a chamber */
	int j;
	long int power[101];
	for (j = 0; j < k; ++j)
		a[j] = 0;

	for (j = 0; A - (power[j] = pow1(N+1, j)) >= 0 && j < 101; ++j)
		;
	while (A != 0) {
		j = 0;
		while (A - power[j] >= 0)
			++j;
		a[j-1] = A/power[j-1];
		A = A % power[j-1];
	}

	for (j = 0; j < k; ++j)
		if (j == k - 1)
			printf("%d\n", a[j]);
		else
			printf("%d ", a[j]);
	
	return 0;
}
