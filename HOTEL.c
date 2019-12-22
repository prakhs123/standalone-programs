#include <stdio.h>

int a[101], d[101];

main()
{
	int t, n, i, j, max, count, p, q;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (i = 0; i < n; i++)
			scanf("%d", &d[i]);
		for (i = 0, max = 0; i < n; i++) {
			for (j = 0, count = 0, p = a[i], q = d[i]; j < n; j++)
				if (a[j] < q && d[j] > p) {
					if (a[j] > p)
						p = a[j];
					if (d[j] < q)
						q = d[j];
					count++;
				}
			if (max < count)
				max = count;
		}
		printf("%d\n", max);
	}
	
	return 0;
}
