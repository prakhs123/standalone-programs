#include <stdio.h>

int T[130];
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
	int t, i, c;
	char M[105];
	scan(&t);
	i = 'a';
	while ((c = getchar_unlocked()) != '\n') {
		T[i] = c;
		T[i-32] = c-32;
		i++;
	}
	T['_'] = ' ';
	T['.'] = '.';
	T[','] = ',';
	T['!'] = '!';
	T['?'] = '?';
	while (t--) {
		while ((c = getchar_unlocked()) != '\n') {
			putchar_unlocked(T[c]);
		}
		putchar_unlocked('\n');
	}
	
	return 0;
}
