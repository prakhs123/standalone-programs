#include <stdio.h>

#define	N	100001

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

int four[N], seven[N], sum4[N], sum7[N], save[N], finalcount[N];
main()
{
	int i, count, temp, t, n;
	
	save[0] = 1;
	finalcount[0] = 0;
	four[0] = seven[0] = sum4[0] = sum7[0] = 0;
	for (i = 1; i < N; i++) {
		four[i] = four[i/10] + (i % 10 == 4);
		seven[i] = seven[i/10] + (i % 10 == 7);
		sum4[i] = sum4[i-1] + four[i];
		sum7[i] = sum7[i-1] + seven[i];
		temp = sum4[i] - sum7[i];
		count = save[temp];
		save[temp]++;
		finalcount[i] = finalcount[i-1] + count;
	}

	scan(&t);
	while(t--) {
		scan(&n);
		printf("%d\n", finalcount[n]);
	}
	
	return 0;
}
