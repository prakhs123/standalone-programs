#include <stdio.h>
#include <math.h>
/* find lowest i such that 2^(i+1) > 1000000000 */
main()
{
	int i = 0;
	while (pow(2, i) < 1000000000ul)
		i++;
	printf("%d\n", i);
}
