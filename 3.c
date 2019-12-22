#include <stdio.h>
#include <math.h>
#define MAXB	100005

int a[MAXB];
int b[1001];

main()
{
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int i;
		for (i = 1; i < MAXB; i++)
			a[i] = -1;
		a[0] = 0;
		int sum = 0, j;
		for (j = 0; j < n; j++) {
			scanf("%d", &b[j]);
			sum += b[j];
		}
		int skew = sum;
		int temp = 0;
		int last = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j <= last; j++) {
				if (a[j] == 0) {
					a[j+b[i]] = 0;
					if (j+b[i] > temp)
						temp = j+b[i];
					if (abs(sum-2*j-2*b[i]) < skew)
						skew = abs(sum-2*j-2*b[i]);
				}
			}
			last = temp;
		}
		printf("%d\n", skew);
	}
	return 0;
}
