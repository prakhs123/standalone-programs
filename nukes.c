#include <stdio.h>
#include <math.h>

int k;
int N;

/* if [A - (N + 1) ^ (p + 1) < 0], then pth chamber will have one particle and new value of A i.e. A' will be [A - (N + 1) ^ p] and the same procedure will be applied to get the new value of p. This process will continue till A* will be less than N + 1 */
void recurse(int a[], long A)
{
	if (A < N + 1) {
		a[0] = A;
		return;
	}
	int p = 0;
	int A2 = 0;
	while (A - pow(N + 1, p + 1) >= 0)
		++p;
	if (p < k)	/* there are only k chambers, rest will go to waste */
		++a[p];
	A2 = A - pow(N + 1, p);
	recurse(a, A2);
}
main()
{
	long int A;
	scanf("%lu %d %d", &A, &N, &k);
	int a[k];
	int j;
	for (j = 0; j < k; ++j)
		a[j] = 0;
	
	recurse(a, A);

	for (j = 0; j < k; ++j)
		if (j == k - 1)
			printf("%d\n", a[j]);
		else
			printf("%d ", a[j]);
	
	return 0;
}
