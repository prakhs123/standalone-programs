#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		char board[4][4];
		int i, j;
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				scanf("%c", &board[i][j]);
			
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++)
				printf("%c", board[i][j]);
			putchar('\n');
		}
	}
	
	return 0;
}
