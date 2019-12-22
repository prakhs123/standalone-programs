#include <stdio.h>

main() {
	int T, K, N, i, flag, count, count2;
	char s[20001], c;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &K);
		scanf("%s", s);
		flag = 0;
		count = 0;
		for (i = 0; i < N;) {
			c = s[i];
			count++;
			count2 = 1;
			i++;
			while (i < N && s[i] == c) {
				i++;
				count2++;
			}
			if (count2 >= K)
				flag = 1;
		}
		if (flag)
			printf("%d\n", count);
		else
			printf("-1\n");
	}
	return 0;
}
