#include <stdio.h>
#include <string.h>

#define MAXSTR	10
#define MAXLEN	100

main()
{
	char *s[MAXSTR];
	char temp[MAXLEN];
	int n;				// no. of strings
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		gets(s[i]);
	}
	
	for(i = 0; i < n; i++)
		printf("%s\n", s[i]);

	return 0;
}
