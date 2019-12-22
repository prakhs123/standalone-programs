#include <stdio.h>
#include <stdbool.h>
#define MAXB	1250
struct node {
	int x,y;
	int p,q;
} points[MAXB+2];
int c[MAXB+2];
int smallest;
int smallest_index;
int N;
char painting[51][51];
int count (int x1, int y1, int x2, int y2)
{
	int i, j, k;
	k = 0;
	bool copy[51][51];
	for (i = x1; i <= x2; i++)
		for (j = y1; j <= y2; j++)
			copy[i][j] = false;
	if (x1-1 >= 0)
		for (j = y1; j <= y2; j++)
			if (painting[x1][j] == 'W' && copy[x1][j] == false && painting[x1-1][j] == 'B') {
				copy[x1][j] = true;
				k++;
			}
	if (y1-1 >= 0)
		for (i = x1; i <= x2; i++)
			if (painting[i][y1] == 'W' && copy[i][y1] == false && painting[i][y1-1] == 'B') {
				copy[i][y1] = true;
				k++;
			}
	if (x2+1 < N)
		for (j = y1; j <= y2; j++)
			if (painting[x2][j] == 'W' && copy[x2][j] == false && painting[x2+1][j] == 'B') {
				copy[x2][j] = true;
				k++;
			}
	if (y2+1 < N)
		for (i = x1; i <= x2; i++)
			if (painting[i][y2] == 'W' && copy[i][y2] == false && painting[i][y2+1] == 'B') {
				copy[i][y2] = true;
				k++;
			}
	return k;
}
main()
{
	scanf("%d\n", &N);
	int i, j, k;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			painting[i][j] = getchar();
		getchar();
	}
	int x1,y1,x2,y2;
	i = 0;
	for (x1 = 0; x1 < N; x1++)
		for (y1 = 0; y1 < N; y1++)
			for (x2 = x1; x2 < N; x2++)
				for (y2 = y1; y2 < N; y2++)
					if ((k = count(x1,y1,x2,y2)) > 0) {
						if (i < MAXB) {
							points[i].x = x1;
							points[i].y = y1;
							points[i].p = x2;
							points[i].q = y2;
							if (smallest > k) {
								smallest = k;
								smallest_index = i;
							}
							c[i] = k;
							i++;
						}
						else if (k > smallest) {
							points[smallest_index].x = x1;
							points[smallest_index].y = y1;
							points[smallest_index].p = x2;
							points[smallest_index].q = y2;
							smallest = k;
							for (j = 0; j < MAXB; j++)
								if (smallest > c[j]) {
									smallest = c[j];
									smallest_index = j;
								}
						}
					}
	for (i = 0; i < MAXB; i++)
		printf("%d %d %d %d - %d\n", points[i].x, points[i].y, points[i].p, points[i].q, c[i]);
	return 0;
}
