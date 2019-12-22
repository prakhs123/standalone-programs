#include <stdio.h>
#include <string.h>

#define MAXP	1000000

int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) {
		char passage[MAXP + 10];
		gets(passage);
		int days = 0;
		int limit = 1;
		int i, l;
		l = strlen(passage);
		for (i = 0; i < l; i++) {
			char c = passage[i];
			int newlimit = 1;
			while (i < l && c == '.') {
				newlimit++;
				i++;
				c = passage[i];
			}
			if (newlimit > limit) {
				days++;
				limit = newlimit;
			}
		}
		printf("%d\n", days);
	}
	return 0;
}