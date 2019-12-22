#include <stdio.h>

#define MAXN	10000

void shellsort(int a[], int n) {
	unsigned int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1}; /* or {
        1, 5, 19, 41, 109, 209, 505, 929, 2161, 3905, 8929, 
        16001, 36289, 64769, 146305, 260609, 587521, 1045505,
        2354689, 4188161, 9427969, 16764929, 37730305, 67084289, 
        150958081, 268386305, 603906049, 1073643521, 2415771649U
    }; */
	
	int i, j, k, temp;
	int gap;
	
	for (k = 0; k < 8; k++) {		// or (k = 28; k >= 0; k --)
		gap = gaps[k];
		for (i = gap; i < n; i++) {
			temp = a[i];
			for (j = i; j >= gap && a[j-gap] > temp; j -= gap)
				a[j] = a[j-gap];
			a[j] = temp;
		}
	}
	
	return;
}

void fill(int *a, int lb, int ub) {
    int i;
    srand(1);
    for (i = lb; i <= ub; i++) 
    	a[i] = rand() % 1000;
}

void print(int *a, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
main()
{
	int n;
	int a[MAXN];
	
	scanf("%d", &n);
	
	fill(a, 0, n-1);
	print(a, n);
	shellsort(a, n);
	print(a, n);
	
	return 0;
}
