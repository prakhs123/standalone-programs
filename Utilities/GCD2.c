#include <stdio.h>

int gcd(int a, int b)
{
	int t;
	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
	}
	
	return a;
}

int gcd2(int a, int b) {
    int r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    
    return b;
}
main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", gcd(a, b));
    printf("%d\n", gcd2(a,b));
	
	return 0;
}
