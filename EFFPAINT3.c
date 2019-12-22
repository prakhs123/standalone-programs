#include <stdio.h>
#include <stdbool.h>
int N;
char painting[51][51];
struct node {
	int x1,y1;
	int x2,y2;
	int prod;
} points[1000][62500], startpoint[100];
bool copy[100][51][51];
int limit[100];
int seq[1000][62500];
void sort(int n,int index) {
	unsigned int gaps[] =  {
        1, 5, 19, 41, 109, 209, 505, 929, 2161, 3905, 8929, 
        16001, 36289, 64769, 146305, 260609, 587521, 1045505,
        2354689, 4188161
    };
	
	int i, j, k, temp, x, y, p, q;
	int gap;
	
	for (k = 19; k >= 0; k --) {
		gap = gaps[k];
		for (i = gap; i < n; i++) {
			temp = points[index][i].prod;
			x = points[index][i].x1;
			y = points[index][i].y1;
			p = points[index][i].x2;
			q = points[index][i].y2;
			for (j = i; j >= gap && points[index][j-gap].prod > temp; j -= gap) {
				points[index][j].prod = points[index][j-gap].prod;
				points[index][j].x1 = points[index][j-gap].x1;
				points[index][j].y1 = points[index][j-gap].y1;
				points[index][j].x2 = points[index][j-gap].x2;
				points[index][j].y2 = points[index][j-gap].y2;
			}
			points[index][j].prod = temp;
			points[index][j].x1 = x;
			points[index][j].y1 = y;
			points[index][j].x2 = p;
			points[index][j].y2 = q;
		}
	}	
	return;
}

int alreadypainted(int it, int index)
{
	int i1, i2, l1 = points[index][it].x2, l2 = points[index][it].y2;
	for (i1 = points[index][it].x1; i1 <= l1; i1++)
		for (i2 = points[index][it].y1; i2 <= l2; i2++)
			if (copy[index][i1][i2] != false)
				return 1;
	for (i1 = points[index][it].x1; i1 <= l1; i1++)
		for (i2 = points[index][it].y1; i2 <= l2; i2++)
			copy[index][i1][i2] = true;
	return 0;
}

int isBlack(int i, int j, int p, int q) {
	int l, m;
	for (l = i; l <= p; l++)
		for (m = j; m <= q; m++)
			if (painting[l][m] != 'B')
				return 0;
	return 1;
}
int good (int i1, int j1, int i2, int j2, int x1, int y1, int x2, int y2)
{
	int it1, it2;
	for (it1 = i1; it1 <= i2; it1++)
		for (it2 = j1; it2 <= j2; it2++)
			if (it1 >= x1 && it1 <= x2 && it2 >= y1 && it2 <= y2) {
				if (painting[it1][it2] != 'W')
					return 0;
			}
			else {
				if (painting[it1][it2] != 'B')
					return 0;
			}
}
int blackfill(int x1, int y1, int x2, int y2, int m)
{
	int i1, i2, j1, j2;
	startpoint[m].x1 = x1;
	startpoint[m].y1 = y1;
	startpoint[m].x2 = x2;
	startpoint[m].y2 = y2;
	for (i1 = 0; i1 < N; i1++)
		for (i2 = 0; i2 < N; i2++)
			copy[m][i1][i2] = false;
	int iterator = 0;
	for (i1 = 0; i1 < N; i1++)
		for (j1 = 0; j1 < N; j1++)
			for (i2 = i1; i2 < N; i2++)
				for (j2 = j1; j2 < N; j2++)
					if (good(i1,j1,i2,j2,x1,y1,x2,y2)) {
						points[m][iterator].x1 = i1;
						points[m][iterator].y1 = j1;
						points[m][iterator].x2 = i2;
						points[m][iterator].y2 = j2;
						points[m][iterator].prod = (i2-i1+1)*(j2-j1+1);
						iterator++;
					}
	sort(iterator, m);
	int it2, k = 0;
	for (it2 = iterator-1; it2 >= 0; it2--)
		if (!alreadypainted(it2, m))
			seq[m][k++] = it2;
	limit[m] = k+1;
	return limit[m];
}
main()
{
	int i, j;
	scanf("%d\n", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			painting[i][j] = getchar();
		getchar();
	}
	int x1,y1,x2,y2;
	int iterator = 0;
	for (x1 = 0; x1 < N; x1++)
		for (y1 = 0; y1 < N; y1++)
			for (x2 = x1; x2 < N; x2++)
				for (y2 = y1; y2 < N; y2++)
					if (isBlack(x1,y1,x2,y2)) {
						points[0][iterator].x1 = x1;
						points[0][iterator].y1 = y1;
						points[0][iterator].x2 = x2;
						points[0][iterator].y2 = y2;
						points[0][iterator].prod = (x2-x1+1)*(y2-y1+1);
						iterator++;
					}
	sort(iterator, 0);
	int it2, k = 0, m = 1, it3;
	for (it2 = iterator-1; it2 >= 0; it2--)
		if (!alreadypainted(it2, 0))
			seq[0][k++] = it2;
	limit[0] = k;
	
	for (x1 = 0; x1 < N; x1++)
		for (y1 = 0; y1 < N; y1++)
			for (x2 = x1; x2 < N; x2++)
				for (y2 = y1; y2 < N; y2++)
					if (blackfill(x1,y1,x2,y2,m) < limit[0])
						m++;
	/*int min = 2501;
	int min_index = -1;
	for (it2 = 0; it2 < m; it2++)
		if (limit[it2] < min) {
			min = limit[it2];
			min_index = it2;
		}
	if (min_index == 0) {
		printf("%d\n", limit[0]);
		for (it2 = 0; it2 < limit[0]; it2++) {
			int t = seq[0][it2];
			printf("%d %d %d %d B\n", points[0][t].x1, points[0][t].y1, points[0][t].x2, points[0][t].y2);
		}
	}
	else {
		printf("%d\n", limit[min_index]);
		printf("%d %d %d %d B\n", startpoint[min_index].x1, startpoint[min_index].y1, startpoint[min_index].x2, startpoint[min_index].y2);
		for (it2 = 0; it2 < limit[min_index]-1; it2++) {
			int t = seq[min_index][it2];
			printf("%d %d %d %d F\n", points[min_index][t].x1, points[min_index][t].y1, points[min_index][t].x2, points[min_index][t].y2);
		}
	}*/
	for (it3 = 1; it3 < m; it3++) {
		printf("%d\n", limit[it3]);
		printf("%d %d %d %d B\n", startpoint[it3].x1, startpoint[it3].y1, startpoint[it3].x2, startpoint[it3].y2);
		for (it2 = 0; it2 < limit[it3]-1; it2++) {
			int t = seq[it3][it2];
			printf("%d %d %d %d F\n", points[it3][t].x1, points[it3][t].y1, points[it3][t].x2, points[it3][t].y2);
		}
	}
	return 0;
}
