#include <stdio.h>

main()
{
	int a[100];
	int t, n;
	int i, j;
	int local_inver, inver;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		
		local_inver = inver = 0;
		for (i = 0; i < n-1; i++) {
			if (a[i] > a[i+1])
				local_inver++;
			for (j = i+1; j < n; j++)
				if (a[i] > a[j])
					inver++;
		}
		
		if (inver == local_inver)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}
