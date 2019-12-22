#include <stdio.h>
#include <math.h>

main()
{
	long int A;
	int N, k;
	scanf("%lu %d %d", &A, &N, &k);
	int a[k];	/* stores no. of particles in a chamber */
	int j;
	long int power[101];
	for (j = 0; j < k; ++j)
		a[j] = 0;

	for (j = 0; A - (power[j] = (long)pow(N+1, j)) >= 0 && j < 101; ++j)
		;
	while (A != 0) {
		while (A - power[j] < 0)
			--j;
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
