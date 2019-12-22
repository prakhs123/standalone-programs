#include <stdio.h>

#define ROWS 3
#define COLS 4

void delete(int x, int y, int a[ROWS][COLS])
{
	int i, j;
	i = x;
	for (j = y; j < COLS; j++) {
			if (j == COLS - 1)
				a[i][j] = a[i+1][0];
			else
				a[i][j] = a[i][j+1];
	}
	for (i = x + 1; i < ROWS; i++)
		for (j = 0; j < COLS; j++) {
			if (j == COLS - 1)
				a[i][j] = a[i+1][0];
			else
				a[i][j] = a[i][j+1];
		}
	a[i-1][j-1] = 0;
}

void insert(int x, int y, int num, int a[ROWS][COLS])
{
	int i, j;
	for (i = ROWS - 1; i >=x; i--) {
		if (i == x)
				for (j = COLS - 1; j > y; j--)
					a[i][j] = a[i][j-1];
		else {
			for (j = COLS - 1; j >= 0; j--)
					if (j == 0)
						a[i][j] = a[i-1][COLS-1];
					else
						a[i][j] = a[i][j-1];
		}
	}
	a[x][y] = num;
}
void display(int a[ROWS][COLS])
{
	int i, j;
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}
int main()
{
	int a[ROWS][COLS] = { {1, 2, 3, 11} , {4, 5, 6, 12} , {7} };
	int i, j;
	insert(0,0,25,a);
	//insert(2,3,15,a);
	delete(0,0,a);
	//delete(1,1,a);
	display(a);
	
	return 0;
}
