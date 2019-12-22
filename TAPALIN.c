#include <stdio.h>
#include <math.h>
#define MOD 1000000007

long long a[100000000];

long modPow(long long a, long long x, long long p) {
    //calculates a^x mod p in logarithmic time.
    long res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}
void precompute(long long *j, long long *temp) {
	long long i, k, t2;
	*temp = 1;
	*j = 1;
	for (i = 1; i < 100000000; i++) {
		if (i % 2 == 0)
			t2 = i / 2;
		else
			t2 = i / 2 + 1;
		for (k = *j; k <= t2; k++)
			*temp = (*temp * 26) % MOD;
		*j = t2+1;
		a[i] = *temp;
		a[i] = (a[i] + a[i-1]) % MOD;
	}
}
int main()
{
	int t;
	long long ans, n, i, j, k, temp;
	precompute(&j, &temp);
	scanf("%d", &t);
	while(t--) {
		scanf("%lld", &n);
		ans = 0;
		if (n < 100000000) {
			printf("%lld\n", a[n]);
		}
		else {
			long long p, q;
			p = j;
			q = temp;
			ans = a[99999999];
			for (i = 100000000; i <= n; i++) {
				long long t2;
				if (i % 2 == 0)
					t2 = i / 2;
				else
					t2 = i / 2 + 1;
				for (k = p; k <= t2; k++)
					q = (q*26) % MOD;
				p = t2+1;
				ans = (ans+q)%MOD;
			}
			printf("%lld\n", ans);	
		}
	}
	return 0;
}
