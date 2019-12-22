#include <stdio.h>
#include <math.h>

#define LIMIT	100000
#define PRIMES	10000
int is_prime[LIMIT+10];
int prime[PRIMES];
int KPRIME[LIMIT+10][6];

void solve() {
	long long i, j;
	for (i = 0; i < LIMIT; i++)
		is_prime[i] = 1;
	is_prime[0] = is_prime[1] = 0;
	for (i = 0; i < LIMIT; i++)
		if (is_prime[i])
			for (j = i*i; j < LIMIT; j += i)
				is_prime[j] = 0;
	
	j = 0;
	for (i = 0; i < LIMIT && j < PRIMES; i++)
		if (is_prime[i])
			prime[j++] = i;
}

int main() {
	solve();
	int A, B, T, K;
	int i, j;
	for (i = 2; i <= LIMIT; i++) {
		int sqrt_i = (int)sqrt(i);
		int num = i;
		int k = 0;
		int f = 1;
		for (j = 0; f && num != 1 && prime[j] <= sqrt_i; j++) {
			int flag = 1;
			while (f && num % prime[j] == 0) {
				if (flag) {
					k++;
					if (k > 5)
						f = 0;
					flag = 0;
				}
				num = num / prime[j];
			}
		}
		if (num != 1)
			k++;
		KPRIME[i][1] = KPRIME[i-1][1] + (k == 1 ? 1 : 0);
		KPRIME[i][2] = KPRIME[i-1][2] + (k == 2 ? 1 : 0);
		KPRIME[i][3] = KPRIME[i-1][3] + (k == 3 ? 1 : 0);
		KPRIME[i][4] = KPRIME[i-1][4] + (k == 4 ? 1 : 0);
		KPRIME[i][5] = KPRIME[i-1][5] + (k == 5 ? 1 : 0);
	}
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &A, &B, &K);
		printf("%d\n", KPRIME[B][K]-KPRIME[A-1][K]);
	}
	return 0;
}