#include <stdio.h>

main()
{
	int T, i, answer;
	char S[201];
	scanf("%d", &T);
	while (T--) {
		i = 0;
		answer = 0;
		int s[200] = {0};
		scanf("%s", S);
		for (i = 0; S[i] != '\0'; i++)
			if (s[S[i]] == 0) {
				answer++;
				s[S[i]]++;
			}
			else
				s[S[i]]--;
		printf("%d\n", answer);
	}
	return 0;
}
