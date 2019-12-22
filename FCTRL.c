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
	int num;
	scan(&t);
	while (t--) {
		scan(&num);
		printf("%d\n", num/5 + num/25 + num/125 + num/625 + num/3125 + num/15625 + num/78125 + num/390625 + num/1953125 + num/9765625 + num/48828125 + num/244140625);
	}
	
	return 0;
}
