#include <stdio.h>
#include <stdbool.h>

struct node {
	int x,y;
	int p,q;
	int product;
} points[6000];

char painting[51][51];
bool copy[51][51];
int seq[6000];
int isBlack(int i, int j, int p, int q) {
	int l, m;
	for (l = i; l <= p; l++)
		for (m = j; m <= q; m++)
			if (painting[l][m] != 'B')
				return 0;
	return 1;
}
void sort(int n) {
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
			temp = points[i].product;
			x = points[i].x;
			y = points[i].y;
			p = points[i].p;
			q = points[i].q;
			for (j = i; j >= gap && points[j-gap].product > temp; j -= gap) {
				points[j].product = points[j-gap].product;
				points[j].x = points[j-gap].x;
				points[j].y = points[j-gap].y;
				points[j].p = points[j-gap].p;
				points[j].q = points[j-gap].q;
			}
			points[j].product = temp;
			points[j].x = x;
			points[j].y = y;
			points[j].p = p;
			points[j].q = q;
		}
	}	
	return;
}

int alreadyPainted(int iter) {
	int i1, i2;
	int l1 = points[iter].p, l2 = points[iter].q;
	for (i1 = points[iter].x; i1 <= l1; i1++)
		for (i2 = points[iter].y; i2 <= l2; i2++)
			if (copy[i1][i2] != false)
				return 1;
	for (i1 = points[iter].x; i1 <= l1; i1++)
		for (i2 = points[iter].y; i2 <= l2; i2++)
			copy[i1][i2] = true;
	return 0;
}
int main()
{
	int N;
	scanf("%d\n", &N);
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			painting[i][j] = getchar();
			copy[i][j] = false;
		}
		getchar();
	}
	int p, q, it = 0;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			for (p = i; p < N; p++)
				for (q = j; q < N; q++)
					if (isBlack(i,j,p,q)) {
						points[it].x = i;
						points[it].y = j;
						points[it].p = p;
						points[it].q = q;
						points[it].product = (p-i+1)*(q-j+1);
						it++;
					}
	int iter, k, t;
	sort(it);
	for (iter = it-1, k = 0; iter >= 0; iter--)
		if (!alreadyPainted(iter))
			seq[k++] = iter;
	
	printf("%d\n", k);
	for (iter = 0; iter < k; iter++) {
		t = seq[iter];
		printf("%d %d %d %d B\n", points[t].x, points[t].y, points[t].p, points[t].q);
	}
	return 0;
}
