#include <stdio.h>

long long count;
int n, m;
int x[101], y[101];

void Dishdis(int index, int sum) {
	if (sum > n)
		return;
	int temp = n - sum;
	if (index == m-1) {	
		if (x[index] > temp)
			return;
		if (temp <= y[index])
			count++;
		return;
	}
	int i;
	for (i = x[index]; i <= y[index]; i++)
		if (i <= temp)
			Dishdis(index + 1, sum + i);
}

main()
{
	int t, i;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (i = 0; i < m; i++)
			scanf("%d %d", &x[i], &y[i]);
		count = 0ll;
		Dishdis(0, 0);
		printf("%d\n", count);
	}
	
	return 0;
}
