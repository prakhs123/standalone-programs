#include <stdio.h>

int f(int num)
{
	int a[10] = {0};
	while (num > 0)
	{
		a[num%10]++;
		num = num/10;
	}
	int i, max;
	for (i = 0, max = 0; i < 10; i++)
		if (max < a[i])
			max = a[i];
	return max;
}
main()
{
	int i, count = 0;
	for (i = 1000; i <= 9999; i++)
		if (f(i) == 2) {
			//printf("%d ", i);
			count++;
		}
	printf("\n");
	printf("%d\n", count);
}
