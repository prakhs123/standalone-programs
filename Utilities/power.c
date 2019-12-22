#include <stdio.h>

float power(float x, int y) {
	float res = 1;
	while (y != 0) {
		if (y&1) {
			if (y < 0)
				res = res/x;
			else
				res = res*x;
		}
		x = x * x;
		y >>= 1;
	}
	return res;
}

main() {
	float a;
	int x;
	scanf("%f%d", &a, &x);
	printf("%f", power(a,x));
	return 0;
}	 
