#include <stdio.h>

main()
{
	int T;
	char s[500];
	int as[500];
	scanf("%d\n", &T);
	while (T--) {
		gets(s);
		int i, ch, j;
		int flag = 0;
		for (i = 0; i <= 128; i++)
			as[i] = 0;
		for (i = 0; s[i] != '\0'; i++)
		{
			as[s[i]]++;
		}
		for (i = 65, j = 97; !flag && i <= 90; i++, j++)
			if (as[i] == 0 && as[j] == 0) {
				flag = 1;
				ch = i;
				break;
			}
		
		if (flag)
			putchar((char)ch);
		else
			putchar('~');
		putchar('\n');
	}
	return 0;
}
