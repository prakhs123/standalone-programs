#include <stdio.h>

main()
{
	int n, i, j;
	char s[100];
	scanf("%d", &n);
	scanf("%s", s);
	int count = 0;
	for (i = 0; i < n;) {
		for (j = i+1; j < n; j++) {
			if (s[j] == s[i]) {
				count++;
			}
			else
				break;
		}
		i = j;
	}
	printf("%d\n", count);
	return 0;
}
