#include <stdio.h>

#define	N	31

int pies[101], rackslimit[101];

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
	int t, i, j, n, num, count;
	scan(&t);
	while (t--) {
		for (i = 0; i < 101; i++) {
			pies[i] = 0;
			rackslimit[i] = 0;
		}
		scan(&n);
		for (i = 0; i < n; i++) {
			scan(&num);
			pies[num]++;
		}
		for (i = 0; i < n; i++) {
			scan(&num);
			rackslimit[num]++;
		}
		for (i = 0, j = 0, count = 0; i < 101; i++)
			if (pies[i] != 0)
				while (pies[i] != 0 && j <= 100)
					if (i <= j && rackslimit[j] != 0) {
						pies[i]--;
						rackslimit[j]--;
						count++;
					}
					else
						j++;
		
		printf("%d\n", count);
	}
	
	return 0;
}
