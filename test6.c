#include <stdio.h>

main()
{
	int N, sum, num = 0, i;
	scanf("%d %d", &N, &sum);
	for (i = sum; i > 0 ; --i)
		num += 1 << i+1;
	printf("%d\n", num);
}
