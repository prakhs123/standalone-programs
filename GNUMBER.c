#include <stdio.h>
#include <string.h>
#define MAXL	100000

char removechar(char s[], char c)
{
	int l = strlen(s);
	int i = 0;
	char a;
	for ( ; i < l; i++)
		if (s[i] > c)
		{
			a = s[i];
			break;
		}
	for ( ;i < l-1; i++)
		s[i] = s[i+1];
	s[i] = '\0';
	return a;
}
void insertchar(char s[], char c)
{
	int i = 0, l = strlen(s);
	for (; i < l; i++)
		if (c < s[i])
			break;
	int j = i, k = l-1;
	s[k+2] = '\0';
	for (; k >= j; k--)
		s[k+1] = s[k];
	s[j] = c;
}
void strcopy(char a[], char b[], int i, int j)
{
	for (; i <= j; i++)
		b[i] = a[i];
	b[i] = '\0';
}		
main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		char num[MAXL+10], temp[MAXL+10], temp2[MAXL+10];
		scanf("%s", num);
		int l = strlen(num);
		if (l == 1) {
			printf("-1\n");
			continue;
		}
		int i, j, flag;
		int prevdig = num[l-1] - '0', dig;
		char s[2], c;
		s[0] = prevdig+'0';
		s[1] ='\0';
		strcpy(temp, s);
		strcpy(temp2, "");
		for (i = l-2, flag = 0, j = 1; i >= 0; i--) {
			dig = num[i] - '0';
			if (dig < prevdig) {
				flag = 1;
				c = removechar(temp, (char)(dig+'0'));
				//printf("%c-", c);
				insertchar(temp, (char)(dig+'0'));
				//printf("%s-", temp);
				//printf("%s-", temp2);
				//printf("%d-", i-1);
				strcopy(num,temp2,0,i-1);
				//printf("%s-", temp2);
				s[0] = c;
				s[1] ='\0';
				strcat(temp2,s);
				//printf("%s-", temp2);
				strcat(temp2, temp);
				//printf("%s\n", temp2);
				break;
			}
			s[0] = dig + '0';
			s[1] = '\0';
			strcat(temp, s);
			prevdig = dig;
		}
		if (flag)
			printf("%s\n", temp2);
		else
			printf("-1\n");
	}
	
	return 0;
}
