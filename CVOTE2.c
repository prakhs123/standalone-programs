#include <stdio.h>
#include <string.h>

inline void scan(int *a) {
	register char c=0;
	while (c < 33)
		c = getchar_unlocked();
	*a = 0;	
	while (c > 33) {
		*a = *a * 10 + c - '0';
		c = getchar_unlocked();
	}
}

void shellsort(char s[][10001][14], int n) {
	unsigned int gaps[] = {1, 5, 19, 41, 109, 209, 505, 929, 2161, 3905, 8929};
	
	int i, j, k;
	int gap;
	char temp[14];
	for (k = 10; k >= 0; k --) {
		gap = gaps[k];
		for (i = gap; i < n; i++) {
			strcpy(temp,s[0][i]);
			for (j = i; j >= gap && strcmp(s[0][j-gap], temp) > 0; j -= gap)
				strcpy(s[0][j], s[0][j-gap]);
			strcpy(s[0][j], temp);
		}
	}
	
	return;
}
void shellsort2(char s[10001][14], int n) {
	unsigned int gaps[] = {1, 5, 19, 41, 109, 209, 505, 929, 2161, 3905, 8929};
	
	int i, j, k;
	int gap;
	char temp[14];
	for (k = 10; k >= 0; k --) {
		gap = gaps[k];
		for (i = gap; i < n; i++) {
			strcpy(temp,s[i]);
			for (j = i; j >= gap && strcmp(s[j-gap], temp) > 0; j -= gap)
				strcpy(s[j], s[j-gap]);
			strcpy(s[j], temp);
		}
	}
	
	return;
}
int binsearch(char s[][10001][14], char x[], int low, int high) {
	int mid;
	while (low <= high) {
		mid = (low+high) / 2;
		if (strcmp(x, s[0][mid]) < 0)
			high = mid - 1;
		else if (strcmp(x, s[0][mid]) > 0)
			low = mid + 1;
		else 
			return mid;
	}
}
int binsearch2(char s[10001][14], char x[], int low, int high) {
	int mid;
	while (low <= high) {
		mid = (low+high) / 2;
		if (strcmp(x, s[mid]) < 0)
			high = mid - 1;
		else if (strcmp(x, s[mid]) > 0)
			low = mid + 1;
		else 
			return mid;
	}
}
char a[2][10001][14];
char b[10001][14];
int v1[10001], v2[10001];
main()
{
	int n, m;
	int c, i, j, k, l;
	char temp[14];
	int maxchef = 0, maxcountry = 0;
	char CHEF[14], COUNTRY[14];
	scan(&n);
	scan(&m);
	j = 0;
	while (n--) {
		i = 0;
		while ((c = getchar()) != ' ')
			a[0][j][i++] = c;
		a[0][j][i] = '\0';
		i = 0;
		while ((c = getchar()) != '\n')
			a[1][j][i++] = c;
		a[1][j][i] = '\0';
		strcpy(b[j], a[1][j]);
		j++;
	}
	shellsort(a, j);
	shellsort2(b, j);
	while (m--) {
		i = 0;
		while ((c = getchar()) != '\n' && c != EOF)
			temp[i++] = c;
		temp[i] = '\0';
		k = binsearch(a, temp, 0, j-1);
		v1[k]++;
		l = binsearch2(b, a[1][k], 0, j-1);
		v2[l]++;
	}
	maxchef = v1[0];
	strcpy(CHEF, a[0][0]);
	maxcountry = v2[0];
	strcpy(COUNTRY, b[0]);
	for (i = 1; i < j; i++) {
		if (maxchef == v1[i]) {
			if (strcmp(a[0][i], CHEF) < 0) {
				strcpy(CHEF, a[0][i]);
			}
		}
		else if (maxchef < v1[i]) {
			strcpy(CHEF, a[0][i]);
			maxchef = v1[i];
		}
		if (maxcountry == v2[i]) {
			if (strcmp(b[i], COUNTRY) < 0) {
				strcpy(COUNTRY, b[i]);
			}
		}
		else if (maxcountry < v2[i]) {
			strcpy(COUNTRY, b[i]);
			maxcountry = v2[i];
		}
	}
	printf("%s\n%s\n", COUNTRY, CHEF);
	return 0;
}
