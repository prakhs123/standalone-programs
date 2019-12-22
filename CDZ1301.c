#include <stdio.h>
#include <string.h>
#define g getchar_unlocked()
main()
{
	int T;
	int power[30], i, j;
	char a[105], b[105], c;
	int b1, b2;
	scanf("%d\n", &T);
	i = 0;
	while ((c = g) != '\n') {
		power[c-'a'] = i;
		i++;
	}
	while (T--) {
		scanf("%s", a);
		scanf("%s", b);
		int l = strlen(a);
		for (i = 0; i < l; i++) {
			for (j = 0; j < l; j++) {
				if (a[
