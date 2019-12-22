#include <stdio.h>
#include <math.h>

main()
{
	int i, j, flag = 1;
	
	for (i = 2; i <= 200; i++, flag = 1) {
		for (j = 2; j <= (int)sqrt(i); j++) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}
		
		if (flag == 1) {
			printf("%d\n", i);
		}
	}
	
	return 0;
}
