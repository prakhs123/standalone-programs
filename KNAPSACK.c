#include <stdio.h>

#define MAXC	100

int M[MAXC][2];
int N;

void IntegerKnapsackProblem(int S[N], int V[N], int C) {
	int i, j;
	M[0][0] = 0; // Knapsack of size 0 has value 0 since it doesnt contain any item
	M[0][1] = 0;
	for (i = 1; i <= C; i++) {
		M[i][0] = M[i-1][0];
		M[i][1] = i-1;
		for (j = 0; j < N; j++)
			if (i-S[j] >= 0)
				if (M[i-S[j]][0] + V[j] > M[i][0]) {
					M[i][0] = M[i-S[j]][0] + V[j];
					M[i][1] = i-S[j];
				}
}

main()
{
	scanf(
