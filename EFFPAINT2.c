#include <stdio.h>
#include <stdbool.h>

struct node {
	int x,y;
	int p,q;
	int product;
} points[6250][6000];

int N;
char painting[51][51];
bool copy[6250][51][51];
int seq[6250][6000];
int seq_it[6250];

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
			temp = points[index][i].product;
			x = points[index][i].x;
			y = points[index][i].y;
			p = points[index][i].p;
			q = points[index][i].q;
			for (j = i; j >= gap && points[index][j-gap].product > temp; j -= gap) {
				points[index][j].product = points[index][j-gap].product;
				points[index][j].x = points[index][j-gap].x;
				points[index][j].y = points[index][j-gap].y;
				points[index][j].p = points[index][j-gap].p;
				points[index][j].q = points[index][j-gap].q;
			}
			points[index][j].product = temp;
			points[index][j].x = x;
			points[index][j].y = y;
			points[index][j].p = p;
			points[index][j].q = q;
		}
	}	
	return;
}

int isBlack(int i, int j, int p, int q) {
	int l, m;
	for (l = i; l <= p; l++)
		for (m = j; m <= q; m++)
			if (painting[l][m] != 'B')
				return 0;
	return 1;
}

int good (int x1, int y1, int x2, int y2, int i, int j, int p, int q, char paint[51][51])
{
	int t1, t2;
	for (t1 = x1; t1 <= x2; t1++)
		for (t2 = y1; t2 <= y2; t2++)
			if (t1 >= i && t1 <= p && t2 >= j && t2 <= q) {
				if (paint[t1][t2] != 'W')
					return 0;
			}
			else {
				if (paint[t1][t2] != 'B')
					return 0;
			}
	return 1;
}

int alreadyPainted(int iter, int index) {
	int i1, i2;
	int l1 = points[index][iter].p, l2 = points[index][iter].q;
	for (i1 = points[index][iter].x; i1 <= l1; i1++)
		for (i2 = points[index][iter].y; i2 <= l2; i2++)
			if (copy[index][i1][i2] != false)
				return 1;
	for (i1 = points[index][iter].x; i1 <= l1; i1++)
		for (i2 = points[index][iter].y; i2 <= l2; i2++)
			copy[index][i1][i2] = true;
	return 0;
}

int Blackfill(int i, int j, int p, int q, int m) 
{
	int i1, i2, j1, j2, it = 0, iter, k;
	char paint[51][51];
	for (i1 = 0; i1 < N; i1++)
		for (i2 = 0; i2 < N; i2++)
			if (i1 >= i && i1 <= p && i2 >= j && i2 <= q)
				paint[i1][i2] = 'B';
			else
				paint[i1][i2] = painting[i1][i2];
	for (i1 = 0; i1 < N; i1++)
		for (j1 = 0; j1 < N; j1++)
			for (i2 = i1; i2 < N; i2++)
				for (j2 = j1; j2 < N; j2++)
					if (good(i1,j1,i2,j2,i,j,p,q,paint)) {
						points[m][it].x = i1;
						points[m][it].y = j1;
						points[m][it].p = i2;
						points[m][it].q = j2;
						points[m][it].product = (i2-i1+1) * (j2-j1+1);
						it++;
					}
	sort(it, m);
	for (i1 = 0; i1 < N; i1++)
		for (i2 = 0; i2 < N; i2++)
			copy[m][i1][i2] = false;
	for (iter = it-1, k = 0; iter >= 0; iter--)
		if (!alreadyPainted(iter, m))
			seq[m][k++] = iter;
	seq_it[m] = k;
	if (k+1 < 6) {
		printf("%d\n", k+1);
		printf("%d %d %d %d B\n", i, j, p ,q);
		for (iter = 0; iter < k; iter++) {
			int t = seq[m][iter];
			printf("%d %d %d %d F\n", points[m][t].x, points[m][t].y, points[m][t].p, points[m][t].q);
		}
	}
	return k;
}
int main()
{
	scanf("%d\n", &N);
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			painting[i][j] = getchar();
		getchar();
	}
	int p, q, it = 0, l ,m = 1;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			for (p = i; p < N; p++)
				for (q = j; q < N; q++)
					if (isBlack(i,j,p,q)) {
						points[0][it].x = i;
						points[0][it].y = j;
						points[0][it].p = p;
						points[0][it].q = q;
						points[0][it].product = (p-i+1)*(q-j+1);
						it++;
					}
	int iter, k, t;
	sort(it, 0);
	for (iter = it-1, k = 0; iter >= 0; iter--)
		if (!alreadyPainted(iter, 0))
			seq[0][k++] = iter;
	seq_it[0] = k;
	int fill = k;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			for (p = i; p < N; p++)
				for (q = j; q < N; q++)
					if (Blackfill(i,j,p,q,m) < fill)
						m++;
	
	/*int ite;
	for (ite = 0; ite < m; ite++) {
		printf("%d\n", seq_it[ite]);
		for (iter = 0; iter < seq_it[ite]; iter++) {
			t = seq[m][iter];
			if (ite > 0)
				printf("%d %d %d %d F\n", points[m][t].x, points[m][t].y, points[m][t].p, points[m][t].q);
			else
				printf("%d %d %d %d B\n", points[m][t].x, points[m][t].y, points[m][t].p, points[m][t].q);
		}
	}*/
	return 0;
}
