#include <stdio.h>

int pathi = 0;
int p[1000000][10] = {0};

int find (int path[], int k)
{
	int i, j;
	int flag = 0;
	
	for (j = 0; j <= pathi; j++) {
		for (i = 0; i < k; i++)
			if (p[j][i] != path[i])
				break;
			if (i == k) {
				flag = 1;
				break;
			}
	}
	return flag;
}

void copy(int path[], int k)
{
	int i;
	for (i = 0; i < k; i++)
		p[pathi][i] = path[i];
}

void recursion(int a[5][5], int i, int j, int path[], int k)
{
	a[i][j] = 1;
	path[k++] = 10 * i + j;
	int m; 
	if (!find(path, k)) {
		copy(path, k);
		pathi++;
		for (m = 0; m < k; m++)
			printf("(%d)->", path[m]);
		printf("\n");
	}
	if (a[i+1][j] == -1)
		recursion(a, i+1, j, path, k);
	if (a[i+1][j+1] == -1)
		recursion(a, i+1, j+1, path, k);
	if (a[i][j+1]  == -1)
		recursion(a, i, j+1, path, k);
	if (a[i][j-1] == -1)
		recursion(a, i, j-1, path, k);
	if (a[i+1][j-1] == -1)
		recursion(a, i+1, j-1, path, k);
	if (a[i-1][j-1] == -1)
		recursion(a, i-1, j-1, path, k);
	if (a[i-1][j] == -1)
		recursion(a, i-1, j, path, k);
	if (a[i-1][j+1] == -1)
		recursion(a, i-1, j+1, path, k);
	--k;
	a[i][j] = -1;
	return;
}
main()
{
	int a[5][5] = {0};
	int path[10];
	int i, j;
	int sum = 0;
	for (i = 1; i < 4; i++)
		for(j = 1; j < 4; j++)
			a[i][j] = -1;
	for (i = 1; i < 4; i++)
		for (j = 1; j < 4 ; j++) {
			recursion(a, i, j, path, 0);
			sum += pathi;
			pathi = 0;
		}
	
	printf("%d\n", sum);
}
