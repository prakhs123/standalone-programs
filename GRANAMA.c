#include <stdio.h>
#include <ctype.h>
#define	SIZE	26

struct recipe {
	int present[SIZE];
	int freq[SIZE];
} r1, r2;

int equals(int a[], int b[])
{
	int i;
	for (i = 0; i < SIZE; i++)
		if (a[i] != b[i])
			return 0;
	
	return 1;
}
main()
{
	int t, c, flag1, flag2, i;
	scanf("%d\n", &t);
	while (t--) {
		flag1 = flag2 = 0;
		for (i = 0; i < SIZE; i++) {
			r1.present[i] = 0;
			r1.freq[i] = 0;
			r2.present[i] = 0;
			r2.freq[i] = 0;
		}
		
		while (isalpha(c = getchar())) {
			c = c -'a';
			if (!(r1.present[c])) {
				r1.present[c] = 1;
				r1.freq[c] = 1;
			}
			else
				r1.freq[c]++;
		}
		while (isalpha(c = getchar())) {
			c = c - 'a';
			if (!(r2.present[c])) {
				r2.present[c] = 1;
				r2.freq[c] = 1;
			}
			else
				r2.freq[c]++;
		}
		
		if (equals(r1.present, r2.present))
			flag1 = 1;
		if (equals(r1.freq, r2.freq))
			flag2 = 1;
		
		if (flag1 && flag2)
			printf("YES\n");
		else if (flag1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	
	return 0;
}
