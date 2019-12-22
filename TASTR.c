#include <stdio.h>
#include <string.h>

void substr(char a[], char c[], int i, int j) {
	int k, p;
	for (p = i, k = 0; p <= j; p++, k++)
		c[k] = a[p];
	c[k] = '\0';
}

main()
{
	char a[100005], b[100005], c[100005];
	scanf("%s %s", a, b);
	int i, j;
	long long count = 0;
	int l = strlen(a);
	for (i = 0; i < l; i++) {
		for (j = i; j < l; j++) {
			substr(a,c,i,j);
			if (strstr(b,c) == NULL) {
				count++;
			}
		}
	}
	l = strlen(b);
	for (i = 0; i < l; i++) {
		for (j = i; j < l; j++) {
			substr(b,c,i,j);
			if (strstr(a,c) == NULL) {
				count++;
			}
		}
	}
	printf("%lld\n", count);
}
