#include <cstdio>

int main()
{
	int X = 1;
	int Y = 1;
	if (Y || X++)
		printf("%d\n", Y);
	printf("%d\n", X);
}