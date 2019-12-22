#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

main()
{
	int t;
	int horses[5000];
	int n;
	int i;
	int diff;
	int newdiff;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &horses[i]);
		qsort(horses, n, sizeof(int), compare);
		diff = horses[1] - horses[0];
		for (i = 2; i < n; i++)
			if ((newdiff = horses[i] - horses[i-1]) < diff)
				diff = newdiff;
		printf("%d\n", diff);
		
	}
	return 0;
}
