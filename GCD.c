#include <stdio.h>

/* compute GCD of two numbers using these properties
	1. GCD(a, b) = GCD(b, a)
	2. GCD(a, a) = a
	3. GCD(a, b) = GCD(a - b, b) if a > b
*/
main()
{
	int a, b;
	scanf("%d %d",&a ,&b);
	while (a != b)
		if (a > b)
			a-=b;
		else
			b-=a;
	printf("GCD: %d\n", a);
	return 0;
}
