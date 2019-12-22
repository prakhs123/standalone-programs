#include <stdio.h>

#define FOR(i, n)	for((i)=0;(i)<(n);(i)++)
#define	MAXN	501

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

void shellsort(int a[][2], int n) {
	unsigned int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
	int i, j, k, temp;
	int gap;
	
	for (k = 0; k < 8; k++) {
		gap = gaps[k];
		for (i = gap; i < n; i++) {
			temp = a[i][0];
			for (j = i; j >= gap && a[j-gap][0] > temp; j -= gap)
				a[j][0] = a[j-gap][0];
			a[j][0] = temp;
		}
	}
	return;
}

int binsearch(int a[][2], int low, int high, int x)
{
	int mid;
	while (low <= high) {
		mid = (low+high) / 2;
		if (x > a[mid][0])
			low = mid + 1;
		else if (x < a[mid][0])
			high = mid - 1;
		else
			return mid;
	}
	return -1;
}

int search(int a[][2], int n)
{
	int i, count = 0;
	for (i = 0; i < n; i++) {
		if (a[i][1] == 0)
			return 0;
		count += a[i][1];
	}
	return count;
}

main()
{
	int t, n, i, j, k, l, m, found, index;
	int H[MAXN][2], K[MAXN];
	scan(&t);
	while (t--) {
		scan(&n);
		FOR(i, n) {
			scan(&H[i][0]);
			H[i][0] = 2 * H[i][0];
			H[i][1] = 0;
		}
		FOR(i, n)
			scan(&K[i]);
		shellsort(H, n);
		
		int sol[25][500*MAXN] = { 0 };
		int upperlimit[25] = { 0 };
		k = 0;
		int lower, upper;
		FOR(i, n) {
			sol[1][k++] = K[i];
			j = binsearch(H, 0, n-1, K[i]);
			lower = j;
			upper = j;
			while (H[--lower][0] == K[i])
				;
			while (H[++upper][0] == K[i])
				;
			for (l = lower+1; l < upper; l++)
				H[l][1] = 1;
		}
		upperlimit[1] = k;
		found = search(H, n);
		for (j = 2; found == 0; j++) {
			l = 0;
			FOR(i, n) {
				for (k = 0; k < upperlimit[j-1]; k++) {
					sol[j][l++] = K[i] + sol[j-1][k];
					m = binsearch(H, 0, n-1, K[i] + sol[j-1][k]);
					lower = m;
					upper = m;
					while (H[--lower][0] == K[i] + sol[j-1][k])
						;
					while (H[++upper][0] == K[i] + sol[j-1][k])
						;
					for (index = lower+1; index < upper && H[index][1] == 0; index++)
						H[index][1] = j;
				}
			}
			upperlimit[j] = l;
			found = search(H, n);
		}
		
		printf("%d\n", found);
	}
	
	return 0;
}
