#include <stdio.h>

#define	N	501

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

int search(int H[], int n, int sol[])
{
	int i, count = 0;
	for (i = 0; i < n; i++) {
		if (sol[2*H[i]] == 0)
			return 0;
		count += sol[2*H[i]];
	}
	return count;
}


main()
{
	int t, n, H[N], K[N];
	int i, j, k;
	int found;
	
	scan(&t);
	while (t--) {
		int sol[2 * N - 1] = { 0 };
		scan(&n);
		for (i = 0; i < n; i++)
			scan(&H[i]);
		for (i = 0; i < n; i++) {
			scan(&K[i]);
			sol[K[i]] = 1;
		}
		found = search(H, n, sol);
		for (j = 2; !found; j++) {
			for (i = 1; i < 2 * N - 1; i++) {
				if (sol[i] == j-1) {
					for (k = 0; k < n; k++) {
						if (i + K[k] < 2 * N - 1 && sol[i+K[k]] == 0)
							sol[i+K[k]] = j;
					}
				}
			}
			found = search(H, n, sol);
		}
		printf("%d\n", found);
	}
	return 0;
}
