#include <stdio.h>

main()
{
	int test;
	scanf ("%d", &test);
	while (test--) {
		int redCount, redHeight, blueCount, blueHeight, result;
		scanf ("%d %d %d %d", &redCount, &redHeight, &blueCount, &blueHeight);
		if (redCount < blueCount)
			result = redCount;
		else
			result = blueCount;
		if (redHeight == blueHeight)
			if (redCount == blueCount)
				printf("%d\n", 2 * redCount);
			else
				printf("%d\n", 2 * result + 1);
		else
			if (redCount == blueCount)
				printf("%d\n", 3 * redCount);
			else
				printf("%d\n", 3 * result + 1);
	}
}
