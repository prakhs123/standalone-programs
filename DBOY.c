#include <stdio.h>

int K[501];
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

void shellsort(int a[], int n) {
	unsigned int gaps[] = {301, 132, 57, 23, 10, 4, 1};
  
	
	int i, j, k, temp;
	int gap;
	
	for (k = 0; k < 7; k++) {
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

int binsearch(int v[], int low, int high, int x, int *flag)
{
	int mid;
	while (low <= high) {
		mid = (low+high) / 2;
		if (x == v[mid])
			return mid;
		else if (x > v[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}
	*flag = 0;
	return high;
}

int binsearch2(int v[], int low, int high, int x)
{
	int mid;
	while (low <= high) {
		mid = (low+high) / 2;
		if (x == v[mid])
			return mid;
		else if (x > v[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}
	return high;
}

int possible(int j, int starting_index, int sum, int max_sum, int p)
{
	if (sum > max_sum)
		return 0;
	if (j == 2) {
		int flag = 1;
		binsearch(K, 0, p, max_sum - sum, &flag);
		if (flag)
			return 1;
		else
			return 0;
	}
	int index;
	for (index = p; index >= starting_index; index--) {
		if (sum + K[index] > max_sum)
			continue;
		if (possible(j - 1, starting_index, sum + K[index], max_sum, p) == 1)
			return 1;
	}
	return 0;
}

main()
{
	int t, n, i, j, k, l, found, flag, count, p, m;
	int H[501];
	scan(&t);
	while (t--) {
		scan(&n);
		for (i = 0; i < n; i++)
			scan(&H[i]);
		for (i = 0; i < n; i++)
			scan(&K[i]);

		shellsort(K, n);
		
		for (i = 0, count = 0; i < n; i++) {
			found = 0;
			flag = 1;
			p = binsearch(K, 0, n - 1, 2 * H[i], &flag);
			if (flag) {
				count++;
				found = 1;
			}
			for (j = 2; found == 0; j++) {
				m = binsearch2(K, 0, p, (2 * H[i]) / j);
				for (k = 0; k <= m && found == 0; k++)
					found = possible(j, k, K[k], 2 * H[i], p);
				if (found != 0)
					count += j;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
