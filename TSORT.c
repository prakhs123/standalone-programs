#include <stdio.h>

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

#define	N	1000001

int num[N];

void shellsort(int a[], int n) {
	unsigned int gaps[] = { 1, 5, 19, 41, 109, 209, 505, 929, 2161, 3905, 8929, 
        16001, 36289, 64769, 146305, 260609, 587521, 1045505};
	
	int i, j, k, temp;
	int gap;
	
	for (k = 17; k >= 0; k --) {
		gap = gaps[k];
		for (i = gap; i < n; i++) {
			temp = a[i];
			for (j = i; j >= gap && a[j-gap] > temp; j -= gap)
				a[j] = a[j-gap];
			a[j] = temp;
		}
	}
	
	return;
}

main()
{
	int t, i = 0, count;
	scan(&t);
	count = t;
	while(t--)
		scan(&num[i++]);
	shellsort(num, count);
	i = 0;
	while(count--)
		printf("%d\n", num[i++]);
	
	return 0;
}
