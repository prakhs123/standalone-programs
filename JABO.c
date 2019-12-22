#include <stdio.h>
#include <ctype.h>

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

int board[2501][2501];

void getcord(int *x, int *y) {
	char b;
	
	b = getchar();
	if (isupper(b))
		*x = (b - 'A') * 52;
	else
		*x = (b - 'a' + 26) * 52;
	b = getchar();
	if (isupper(b))
		*x += b - 'A';
	else
		*x += b - 'a' + 26;
	
	b = getchar();
	if (isupper(b))
		*y = (b - 'A') * 52;
	else
		*y = (b - 'a' + 26) * 52;
	b = getchar();
	if (isupper(b))
		*y += b - 'A';
	else
		*y += b - 'a' + 26;
}
main()
{
	int N, R, C;
	char c, b;
	int x1, y1, x2, y2;
	scan(&N);
	scan(&R);
	scan(&C);
	while (N--) {
		c = getchar();
		switch (c) {
			case 'W':
				getcord(&x1, &y1);
				getcord(&x2, &y2);
				getchar();
				break;
			case 'V':
				getcord(&x1, &y1);
				getchar();
				break;
			case 'L':
				getcord(&x1, &y1);
				getcord(&x2, &y2);
				getchar();
				break;
			case 'R':
				getcord(&x1, &y1);
				getchar();
				break;
		}
	}
	
	return 0;
}
