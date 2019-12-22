#include <stdio.h>

main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	int c, prevc, samec;
	int i, j;
	int flag = 1;
	for (i = 0; i < N && flag; i++) {
		for (j = 0; j < M && flag; j++) {
			if (j == 0) {
				scanf("%d", &c);
				samec = c;
			}
			if (j != 0) {
				scanf("%d", &c);
				if (c != samec) {
					flag = 0;
					break;
				}
			}
			if (i != 0)
				if (c == prevc) {
					flag = 0;
					break;
				}
		}
		prevc = c;
	}
	if (flag)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
