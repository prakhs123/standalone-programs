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
	int t;
	scan(&t);
	int num;
	while (t--) {
		scan(&num);
		printf("%d\n", num/2 + 1);
	}
	
	return 0;
}
