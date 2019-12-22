#include <stdio.h>
#include <math.h>

main()
{
	long A;
	int j, k, N;
	long power[101] = {0};
	scanf("%ld %d", &A, &N);
	for (j = 0; A - (power[j] = (long)pow(N+1, j)) >= 0 && j < 101; ++j)
		printf("%ld %ld\n", power[j], A - (power[j] = (long)pow(N+1, j)));
	printf("%d\n", j);
	for (k = 0; k < j; ++k) 
		printf("%lu ", power[k]);
	
	printf("\n");
	return 0;
}
