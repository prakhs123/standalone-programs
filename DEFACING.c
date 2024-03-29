#include <stdio.h>
#include <string.h>

int d[10][11] = { {8,0,-1}, {9,8,7,4,3,1,0,-1}, {8,2,-1}, {9,8,3,-1}, {9,8,4,-1}, {9,8,6,5,-1}, {8,6,-1}, {9,8,7,3,0,-1}, {8,-1}, {9, 8, -1} };
char score[10], m[10];
void solve(int *s, int flag, int i, int change)
{
	if (i > strlen(m) - 1)
		return;
	if (flag) {
		int j;
		for (j = i; m[j] != '\0'; j++) {
			if (score[j] != '-') {
				int p = d[score[j]-'0'][0];
				*s = *s * 10 + p;
			}
			else
				*s = *s * 10 + 9;
		}
		return;
	}
	else {
		if (change) {
			if (score[i] == '-') {
				if (m[i] != '0') {
					*s = *s * 10 + (m[i] - '0' - 1);
					flag = 1;
					solve(s,flag,i+1,change);
				}
				else {
					*s = *s / 10;
					solve(s,flag,i-1,change);
				}
			}
			else {
				int j, f = 0;
				for (j = 0; d[score[i]-'0'][j] != -1; j++) {
					if (d[score[i]-'0'][j] < m[i]-'0') {
						*s = *s * 10 + d[score[i]-'0'][j];
						flag = 1;
						f = 1;
						solve(s,flag,i+1,change);
						break;
					}
				}
				if (f == 0) {
					*s = *s / 10;
					solve(s,flag,i-1,change);
				}
			}
		}
		else {
			if (score[i] == '-') {
				*s = *s * 10 + (m[i] - '0');
				solve(s, flag, i+1, change);
			}
			else {
				int j, f = 0;
				for (j = 0; d[score[i]-'0'][j] != -1; j++) {
					if (d[score[i]-'0'][j] == m[i] - '0') {
						*s = *s * 10 + d[score[i]-'0'][j];
						f = 1;
						solve(s,flag,i+1,change);
						break;
					}
					else if (d[score[i]-'0'][j] < m[i] - '0') {
						*s = *s * 10 + d[score[i]-'0'][j];
						f = 1;
						flag = 1;
						solve(s,flag,i+1,change);
						break;
					}
				}
				if (f == 0) {
					*s = *s / 10;
					change = 1;
					solve(s,flag,i-1,change);
				}
			}
		}
	}
}

main()
{
	int T;
	int i, j, k, l, p, max, sc;
	char temp[10];
	scanf("%d", &T);
	while (T--) {
		scanf("%s %s", temp, m);
		int Ls = strlen(temp);
		int Lm = strlen(m);
		for (i = 0, j = Lm-Ls, max = -1; i < Lm-Ls+1; i++, j--) {
			for (k = 0; k < i; k++)
				score[k] = '-';
			score[k] = '\0';
			strcat(score,temp);
			l = strlen(score);
			for (k = 0, p = l; k < j; k++, p++)
				score[p] = '-';
			score[p] = '\0';
			sc = 0;
			solve(&sc, 0, 0, 0);
			if (sc > max)
				max = sc;
		}
		printf("%d\n", max);
	}
			
	return 0;
}
