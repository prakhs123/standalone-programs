#include <stdio.h>
#define TRUE 1
#define FALSE 0
int N;	/* maximum number of particles - 1 that can be in one chamber */
int k;	/* number of chambers	*/ 
/* if possible to bombard in the index */
int if_possible(int a[], int index)
{
	if (index == k)
		if (a[index] >= N)
			return 0;
		else {
			++a[index];
			return 1;
		}

	if (a[index] < N) {
		a[index]++;
		return 1;
	}
	else {
		a[index] = 0;
		if_possible(a, index + 1);
	}
}

main()
{
	unsigned long int A;
	scanf("%lu %d %d", &A, &N, &k);
	int a[k];	/* no. of particles in all k chambers	*/
	int i = 1;	/* particle number that will be bombarded */
	char flag = TRUE;
	int j;
	for (j = 0; j < k; ++j)
		a[j] = 0;
	
	while (i <= A && flag) {
		flag = if_possible(a, 0);
		i++;
	}

	for (j = 0; j < k; ++j)
		if (j == k - 1)
			printf("%d\n", a[j]);
		else
			printf("%d ", a[j]);
	
	return 0;
}
