#include <stdio.h>
#include <ctype.h>
int minimum_of_cols(int n, int M, int matrix[8][7][50]) {
	int q = n / 7;
	int r = n % 7;
	int max[50] = {0};
	int j, i;
	for (j = 0; j <= q; j++)
		for (i = 0; i < M; i++)
			max[i] += matrix[j][r][i];
	int min = max[0];
	for (i = 1; i < M; i++)
		if (min > max[i])
			min = max[i];

	return min;
} 
main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int M, N, B;
		scanf("%d %d %d", &N, &M, &B);
		int matrix[8][7][50] = {0};
		int i, j;
		scanf("\n");
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				int c, value;
				c = getchar();
				if (isdigit(c))
					value = c - '0';
				else if (isupper(c))
					value = c - 'A' + 10;
				else
					value = c - 'a' + 36;
				int q = i/7;
				int r = i%7;
				matrix[q][r][j] = value;
			}
			getchar();					/* ignore space */
		}
		int cost[50];
		cost[0] = minimum_of_cols(0,M,matrix);
		for (i = 1; i < N; i++) {
			if (i < 7)
				cost[i] = cost[i-1] + minimum_of_cols(i,M,matrix);
			else 
				cost[i] = cost[i-1] + minimum_of_cols(i,M,matrix) - minimum_of_cols(i-7,M,matrix);
		}

		for (i = 0; i < N; i++)
			if (cost[i] > B)
				break;
		printf("%d\n", i);
	}
}


