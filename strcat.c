#include <stdio.h>

#define MAXSIZE 100

char *strcat(char *s, char *ct)
{
	int i = 0;
	while(*(s+i))
		i++;
	while (*(s+i) = *ct++)
		i++;
	return s;
}
/* test function strcat */
main()
{
	char s1[MAXSIZE], s2[MAXSIZE];

	printf("Enter String 1 :");
	scanf("%s", s1);
	printf("Enter String 2 :");
	scanf("%s", s2);

	printf("%s\n", strcat(s1, s2));
	return 0;
}
