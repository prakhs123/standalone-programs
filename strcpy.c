#include <stdio.h>

#define MAXSIZE 100

void strcpy(char *s, char *t)
{
	while(*s++ = *t++)
		;
}
main()
{
	char s1[MAXSIZE], s2[MAXSIZE];
	printf("Enter String 1 :");
	scanf("%s\n", s1);
	printf("Enter String 2 :");
	scanf("%s", s2);

	strcpy(s1, s2);
	printf("%s\n%s\n", s1, s2);
	return 0;
}
