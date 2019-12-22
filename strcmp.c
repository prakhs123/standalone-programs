#include <stdio.h>

#define MAXSIZE 20

int strcmp(char *s1, char *s2)
{
	for ( ; *s1 == *s2; s1++, s2++)
		if (*s1 == '\0')
			return 0;
	return *s1 - *s2;
}

main()
{
	char s1[MAXSIZE], s2[MAXSIZE];
	
	printf("Enter String 1 :");
	scanf("%s", s1);
	printf("Enter String 2 :");
	scanf("%s", s2);
	printf("%d\n", strcmp(s1, s2));
}
