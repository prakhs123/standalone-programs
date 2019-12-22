#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

#define MAXL	1000

int compress(char s[], int l) {
	int i = 0;
	while (i < l) {
		if (s[i] != '0')
			break;
		i++;
	}
	return i;
}

bool compare(char ans[], char num[], int i, int j) {
	int aL = strlen(ans);
	if (aL > j-i)
		return true;
	else if (j-i > aL)
		return false;
	else {
		int l1, l2;
		for (l1 = 0, l2 = i; l1 < aL; l1++, l2++)
			if (ans[l1] > num[l2])
				return true;
			else if (ans[l1] < num[l2])
				return false;
		return true;
	}
}

void copy(char dest[], char src[], int i, int j) {
	int p = 0;
	int q = i;
	while (q < j)
		dest[p++] = src[q++];
	dest[p] = '\0';
}

void findBest(char s[], char ans[]) {
	int i, l, j;
	l = strlen(s);
	char num[MAXL + 10];
	bool flag = false;
	for (i = 0, j = 0; i < l; i++) {
		if (isalpha(s[i]) && flag) {
			int first = compress(num, j);
			if (!compare(ans, num, first, j))
				copy(ans, num, first, j);
			j = 0;
			flag = false;
		}
		else if (isdigit(s[i])) {
			num[j++] = s[i];
			flag = true;
		}
	}
	if (flag) {
		int first = compress(num, j);
		if (!compare(ans, num, first, j))
			copy(ans, num, first, j);
	}
}
int main() {
	char s[MAXL + 10];
	gets(s);
	char ans[MAXL + 10] = "";
	char num[MAXL + 10] = "";
	findBest(s,ans);
	int i, l;
	l = strlen(s);
	for (i = 0; i < l; i++) {
		if (isalpha(s[i])) {
			char temp = s[i];
			s[i] = '9';
			findBest(s, num);
			if (!compare(ans, num, 0, strlen(num)))
				strcpy(ans, num);
			strcpy(num, "");
			s[i] = temp;
		}
	}
	if (strlen(ans) == 0)
		printf("0\n");
	else
		printf("%s\n", ans);
	return 0;
}