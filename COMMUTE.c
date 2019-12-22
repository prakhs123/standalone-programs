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
int main()
{
	int t, n, x, l, f, s;
	scan(&t);
	while (t--){
		scan(&n);
		s = 0;
		while (n--) {
			scan(&x);
			scan(&l);
			scan(&f);
			if (s<=x)
				s = x + l;
			else
				s += f - (s - x - 1)%f - 1 + l;
		}
		printf("%d\n", s);
	}
	return 0;
}
