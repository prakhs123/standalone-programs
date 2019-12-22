#include <stdio.h>

#define g	getchar_unlocked()

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
	int T, N;
	scan(&T);
	while (T--) {
		int count[30] = {0};
		char c;
		while ((c = g) != ' ')
			count[c-'a']++;
		while ((c = g) != '\n')
			count[c-'a']++;
		scan(&N);
		int flag = 1;
		while (N--) {
			while ((c = g) != '\n')
				if (count[c-'a'] <= 0)
					flag = 0;
				else
					count[c-'a']--;
		}
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
