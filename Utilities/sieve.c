#include <stdio.h>

#define LIMIT	100000
#define PRIMES	70000
int is_prime[LIMIT];
int prime[PRIMES];

int LI;
int PR;
void solve() {
	long long i, j, ans;
	for (i = 0; i < LI; i++)
		is_prime[i] = 1;
	is_prime[0] = is_prime[1] = 0;
	for (i = 0; i < LI; i++)
		if (is_prime[i])
			for (j = i*i; j < LI; j += i) {
				if (is_prime[j] == 1)
					ans = j;
				is_prime[j] = 0;
			}
	printf("%d\n", ans);
	/*j = 0;
	for (i = 0; i < LI && j < PR; i++)
		if (is_prime[i])
			prime[j++] = i;*/
}

int main()
{
	LI = 4;
	for ( ; LI <= 3000; LI++)
		solve();
	return 0;
}
