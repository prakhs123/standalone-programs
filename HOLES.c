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
	int t, count;
	char c;
	scan(&t);
	while (t--) {
		count = 0;
		while ((c = getchar()) != '\n') {
			if (c == 'A' || c == 'D' || c == 'O' || c == 'P' || c == 'R' || c == 'Q')
				count++;
			else if (c == 'B')
				count += 2;
		}
		printf("%d\n", count);
	}
	
	return 0;
}
