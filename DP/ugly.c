#include <stdio.h>

int isUgly(int num)
{
	while (num % 2 == 0)
		num /= 2;
	while (num % 3 == 0)
		num /= 3;
	while (num % 5 == 0)
		num /= 5;
	
	if (num == 1)
		return 1;
	else
		return 0;
}

main()
{
	int i, n;
	n = 0;
	i = 1;
	
	for (i = 1; n != 150; i++)
		if (isUgly(i))
			n++;
	
	printf("150th ugly number is %d\n", i-1);
	
	return 0;
}
