#include <stdio.h>
#include <math.h>

main()
{
	unsigned long int A;
	int N, k;
	scanf("%lu %d %d", &A, &N, &k);
	int a[k];	/* stores no. of particles in a chamber */
	int j;
	for (j = 0; j < k; ++j)
		a[j] = 0;
	
	printf("%lu %d %d\n", A, N, k);
	long double powers[k];
	for (j = 0; j < k ; ++j)
		powers[j] = pow(N+1, j+1);

	while (A >= N+1) {
		for (j = 0; j < k; ++j) {
			if (A - powers[j] < 0) {
					++a[j+1];
				A -= powers[j];
				break;
			}
		}
	}
	a[0] = A;

	for (j = 0; j < k; ++j)
		if (j == k - 1)
			printf("%d\n", a[j]);
		else
			printf("%d ", a[j]);
	
	return 0;
}
