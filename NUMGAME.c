#include <stdio.h>

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

main()
{
	int t, N;
	char s1[] = "ALICE";
	char s2[] = "BOB";
	
	scan(&t);
	while (t--) {
		scan(&N);
		printf("%s\n", N%2 == 0 ? s1 : s2);
	}
	
	return 0;
}
