#include <stdio.h>
#include <string.h>

main()
{
	char s[2015];
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		int i, j, l;
		l = strlen(s);
		if (l < 4) {
			for (i = 0; i < l; i++)
				if (s[i] == '?')
					s[i] = 'A';
			printf("%s\n", s);
			continue;
		}
		for (i = l-1; i >= 3; ) {
			if ((s[i] == 'F' || s[i] == '?') && (s[i-1] == 'E' || s[i-1] == '?') && (s[i-2] == 'H' || s[i-2] == '?') && (s[i-3] == 'C' || s[i-3] == '?')) {
			if (s[i] == '?')
				s[i] = 'F';
			if (s[i-1] == '?')
				s[i-1] = 'E';
			if (s[i-2] == '?')
				s[i-2] = 'H';
			if (s[i-3] == '?')
				s[i-3] = 'C';
			i = i-4;
			continue;
			}
			if (s[i] == '?')
				s[i] = 'A';
			i--;
		}
		for (i = 0; i <= 2; i++)
			if(s[i] == '?')
				s[i] = 'A';
		printf("%s\n", s);
	}
	return 0;
}
