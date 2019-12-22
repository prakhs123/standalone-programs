#include <stdio.h>

main()
{
	int A, B;
	scanf("%d %d", &A, &B);
	int s = (A - B) >> 31;
	printf("%d %d\n", s, (A & ~s) | (B & s));
	return 0;
}
