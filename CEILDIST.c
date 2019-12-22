#include <stdio.h>
#include <math.h>

main()
{
	int T;
	int DS, DT, D;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &DS, &DT, &D);
		if (DS+DT >= D) {
			if (DS >= D+DT)
				printf("%f\n", (double)(DS-D-DT));
			else if (DT >= DS+D)
				printf("%f\n", (double)(DT-D-DS));
			else
				printf("%f\n", 0.0);
		}
		else
			printf("%f\n", (double)(D-DS-DT));
	}
	return 0;
}
