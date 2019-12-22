#include <stdio.h>

#define	MAXSIZE	400001
#define	MOD	1000000007

int rectangle[MAXSIZE];

inline void scan(int *a) {
	register char c=0;
	while (c < 33)
		c = getchar_unlocked();
	*a = 0;	
	while (c > 33) {
		*a = *a * 10 + c - '0';
		c = getchar_unlocked();
	}
}

main()
{
	int R;	
	int M, N, A, B;
	int i, j;
	scan(&R);
	while (R--) {
		scan(&N);
		scan(&M);
		scan(&A);
		scan(&B);
		rectangle[N] = 0;
		for (i = 0; i <= N; i++)
			rectangle[i] = 1;
		for (i = M-1; i >= B; i--)
			for (j = N-1; j >= 0; j--)
				rectangle[j] = (rectangle[j] + rectangle[j+1]) % MOD;
		for (i = B-1; i >= 0; i--)
			for (j = N-A-1; j >= 0; j--)
				rectangle[j] = (rectangle[j] + rectangle[j+1]) % MOD;
		
		printf("%d\n", rectangle[0]);
	}
	
	return 0;
}
