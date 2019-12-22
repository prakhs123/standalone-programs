#include <stdio.h>
#include <string.h>

#define MAXS	10000
int a[MAXS+10][26];
int b[MAXS+10][26];
int c[MAXS+10][26];
int m1[MAXS+10];
int m2[MAXS+10];
int m3[MAXS+10];

main() {
	int T;
	scanf("%d\n", &T);
	while (T--) {
		memset(a,0,sizeof(a[0][0])*(MAXS+10)*26);
		memset(b,0,sizeof(b[0][0])*(MAXS+10)*26);
		memset(c,0,sizeof(c[0][0])*(MAXS+10)*26);
		memset(m1,0,sizeof(m1));
		memset(m2,0,sizeof(m2));
		memset(m3,0,sizeof(m3));
		char s[2*MAXS+10];
		scanf("%s", s);
		int i, j, l, n;
		l = strlen(s);
		n = 0;
		int flag;
		for (i = 0; i < l; i++)
			if (s[i] == '#')
				n++;
			else {
				a[n][s[i]-'a']++;
				if (a[n][s[i]-'a'] > m1[n])
					m1[n] = a[n][s[i]-'a'];
			}
		if (n < 3) {
			printf("0\n");
			continue;
		}
		for (j = 0; j < 26; j++) {
			b[0][j] = a[0][j];
			c[n][j] = a[n][j];
		}
		m2[0] = m1[0];
		m3[n] = m1[n];
		for (i = 1; i <= n-3; i++)
			for (j = 0; j < 26; j++) {
				b[i][j] = b[i-1][j] + a[i][j];
				if (b[i][j] > m2[i])
					m2[i] = b[i][j];
			}
		for (i = n-1; i >= 3; i--)
			for (j = 0; j < 26; j++) {
				c[i][j] = c[i+1][j] + a[i][j];
				if (c[i][j] > m3[i])
					m3[i] = c[i][j];
			}
		int ans = 0;
		for (i = 3; i <= n; i++)
			if (m2[i-3] > 0 && m1[i-2] > 0 && m1[i-1] > 0 && m3[i] > 0)
				if (m2[i-3] + m1[i-2] + m1[i-1] + m3[i] > ans)
					ans = m2[i-3] + m1[i-2] + m1[i-1] + m3[i];
		if (ans == 0)
			printf("0\n");
		else
			printf("%d\n", ans+3);
	}
	return 0;
}
