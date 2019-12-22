#include <stdio.h>
#include <time.h>

int binsearch1(int x, int v[], int n)
{
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int binsearch2(int x, int v[], int n)
{
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	while (low <= high && x != v[mid]) {
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
		mid = (low + high) / 2;
	}
	if (x == v[mid])
		return mid;
	else
		return -1;
}
main()
{
	int v[] = {1, 2, 4, 7, 8, 9, 10, 13, 13, 16};
	clock_t start = clock();
	binsearch1(4, v, 10);
	printf("Time elapsed: %lf\n", ((double)clock() - start));
}
