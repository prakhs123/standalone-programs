#include <stdio.h>

int Add(int x, int y)
{
    if (y == 0)
        return x;
    else
        return Add( x ^ y, (x & y) << 1);
}

main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d + %d = %d\n", a, b, Add(a, b));
	
	return 0;
}
