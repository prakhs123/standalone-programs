#include <stdio.h>
#include <string.h>

void substr(char s[], char t[], int i, int j)
{
	int k = 0;
	for ( ; i <= j; i++, k++)
		t[k] = s[i];
	t[k] = '\0';
}
void strrev(char s[])
{
	int i = 0;
	int j = strlen(s)-1;
	char t;
	while (i < j) {
		t = s[i];
		s[i] = s[j];
		s[j] = t;
		i++;
		j--;
	}
}
main() {
	char s[11], temp[11];
	int T, l, i, j, flag;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		l = strlen(s);
		flag = 1;
		for (i = 0; i < l && flag; i++) {
			for (j = i; j < l && flag; j++) {
				substr(s,temp,i,j);
				strrev(temp);
				if (strstr(s,temp) == NULL)
					flag = 0;
			}
		}
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}		
