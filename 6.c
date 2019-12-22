#include <stdio.h>

int K;
int p[200001];
int equals(int A, int n) {
	int i;
	for (i = 0; i < n; i++)
		if (p[i] == A)
			return 1;
	return 0;
}
void fun(int A, int B, int *c, int n) {
	if (A == 0)
		return;
	if (equals(A, n)) {
		*c = -1;
		return;
	}
	if (A-K >= 0) {
		int newB = B + K;
		int newA = B+A-newB;
		(*c)++;
		p[n++] = newA;
		fun(newA, newB, c, n);
	}
	else {
		int newB = B+2*A-K;
		int newA = B+A-newB;
		(*c)++;
		p[n++] = newA;
		fun(newA, newB, c, n);
	}
}
main()
{
	int T, A, B;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &A, &B, &K);
		int s = 0;
		fun(A,B,&s,0);
		printf("%d\n", s);
	}
	return 0;
}
