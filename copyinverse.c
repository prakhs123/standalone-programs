#include <stdio.h>

/* convert input to output such that lowercase characters are turned to uppercase and vice-versa */
main()
{
	int c;
	
	while ((c = getchar()) != EOF)
		if (c <= 'Z' && c >= 'A')
			putchar((int)(c - 'A' + 'a'));
		else if (c <= 'z' && c >= 'a')
			putchar((int)(c - 'a' + 'A'));
		else
			putchar(c);
}
