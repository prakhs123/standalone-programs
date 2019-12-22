#include	<stdio.h>

#define	TRUE	1
#define	FALSE	0

int try(int, int);
void drawboard(void);
int good(void);
int checkallpaths(int, int);

static short int board [8][8];

void main()
{
	int i, j, k;
	for (k = 0; k < 8; k++) {
		for (i = 0; i < 8; i++)
			for (j = 0; j < 8; j++)
				board[i][j] = FALSE;
		if (try(0,k) == TRUE)
			drawboard();
		putchar('\n');
	}
}

int try(int n, int k)
{
	int i;
	
	for (i = 0; i < 8; i++) {
		if (n == 0 && i <= k-1)
			continue;
		board[n][i] = TRUE;
		if (n == 7 && good() == TRUE)
			return TRUE;
		if (n < 7 && good() == TRUE && try(n+1, k) == TRUE)
			return TRUE;
		board[n][i] = FALSE;
	}
	return FALSE;
}

void drawboard(void)
{
	int i, j;
	
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++)
			if (board[i][j] == TRUE)
				putchar('*');
			else
				putchar('#');
		putchar('\n');
	}
}

int good(void)
{
	int i, j;
	int flag;
	
	for (i = 0, flag = TRUE; i < 8 && flag; i++)
		for (j = 0; j < 8 && flag; j++)
			if (board[i][j] == TRUE)
				flag = checkallpaths(i, j);
	
	return flag;
}

int checkallpaths(int i, int j)
{
	int k;
	
	for (k = 0; k < 8; k++) {
		if (k != i && board[k][j] == TRUE)
			return FALSE;
		if (k != j && board[i][k] == TRUE)
			return FALSE;
	}
	
	int temp1 = i-1, temp2 = j-1;
	
	while (temp1 >= 0 && temp2 >= 0)
		if (board[temp1--][temp2--] == TRUE)
			return FALSE;
	
	temp1 = i+1, temp2 = j+1;
	
	while (temp1 <= 7 && temp2 <= 7)
		if (board[temp1++][temp2++] == TRUE)
			return FALSE;
	
	temp1 = i+1, temp2 = j-1;
	
	while (temp1 <= 7 && temp2 >= 0)
		if (board[temp1++][temp2--] == TRUE)
			return FALSE;
	
	temp1 = i-1, temp2 = j+1;
	
	while (temp1 >= 0 && temp2 <= 7)
		if (board[temp1--][temp2++] == TRUE)
			return FALSE;
	
	return TRUE;
}
