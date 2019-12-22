#include <stdio.h>

#define	MAXLINE	50
/* getline2: read a line into s, return length */
int getline2(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

main()
{
	int test;
	scanf("%d\n", &test);
	while (test--) {
		char s[MAXLINE];
		int len;
		int count;
		int flag1, flag2, flag3;
		flag1 = flag2 = flag3 = 1;
		while ((len = getline2(s, MAXLINE)) > 0) {
			int i, j;
			for (j = 0; j < len - 1; j++) {
				flag1 = flag2 = flag3 = 1;
				for (i = j, count = 0; i < len - 1; i++) { 
					if (flag1 && s[i] == 'A') {
						++count;
						flag1 = 0;
					}
					if (flag2 && s[i] == 'B') {
						++count;
						flag2 = 0;
					}
					if (flag3 && s[i] == 'C') {
						++count;
						flag3 = 0;
					}
				}
				printf("%d ", count);
			}
			printf("\n");
		}
	}
}
