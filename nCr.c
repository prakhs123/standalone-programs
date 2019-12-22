#include <stdio.h>

main()
{
	int r = 49;
	int n = 99;
	double ans = 1.0;
	while (r >= 1) {
		ans *= (double)r/n;
		r--;
		n--;
	}
	printf("%.15f\n", ans);
	return 0;
}
