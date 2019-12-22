#include <stdio.h>

int a[3001][3001];
int square[4244];

void pre()
{
	int i;
	for (i = 1; i <= 4243; i++)
		square[i] = i*i;
}

int ispresent(int num)
{
	int i;
	for (i = 1; i <= 4243; i++)
		if (square[i] == num)
			return 1;
	return 0;
}

void precompute() {
	int i, j;
	for (i = 1; i <= 3000; i++)
		for (j = 1; j <= 3000; j++)
			if (ispresent(i*i+j*j))
				a[i][j] = 1;
			else
				a[i][j] = 0;
}
