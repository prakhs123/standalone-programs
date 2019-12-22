#include <stdio.h>

main()
{
	int a;
	int b;
	int T;
	int k;
	int limit, t;
	scanf("%d", &T);
	while (T--) {
		k = 0;
		a = 103993;
		b = 33102;
		scanf("%d", &limit);
		while (k <= limit) {
			if (k == 1)
				putchar('.');
			t = a/b;
			printf("%d", t);
			a -= t*b;
			a *= 10;
			k++;
		}
		putchar('\n');
	}
	return 0;
}
