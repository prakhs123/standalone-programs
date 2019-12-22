#include <stdio.h>
#include <string.h>

main()
{
	int N, K, i, j, flag;
	scanf("%d %d", &K, &N);
	char s[51][51], t[51];
	i = 0;
	while (K--)
		scanf("%s\n", s[i++]);
	while (N--) {
		scanf("%s", t);
		if (strlen(t) >= 47) {
			printf("Good\n");
			continue;
		}
		for (j = 0, flag = 0; j < i; j++)
			if (strstr(t,s[j]) != NULL)	{
				printf("Good\n");
				flag = 1;
				break;
			}
		if (flag == 0)
			printf("Bad\n");
	}
	return 0;
}
