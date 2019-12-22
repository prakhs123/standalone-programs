#include <stdio.h>
#include <math.h>
#define MOD 1000000007

long long modPow(long long a, long long x, long long p) {
    //calculates a^x mod p in logarithmic time.
    long long res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}

long long modInverse(long long a, long long p) {
    //calculates the modular multiplicative of a mod m.
    //(assuming p is prime).
    return modPow(a, p-2, p);
}

int main()
{
	int t;
	long long ans, n, i, j, k, p, flag;
	long long modinv25 = modInverse(25ll, MOD);
	scanf("%d", &t);
	while(t--) {
		scanf("%lld", &n);
		if (n % 2 == 0) {
			flag = 1;
			p = n/2;
		}
		else {
			flag = 0;
			p = n/2 +1;
		}
		if (flag) {
			ans = 26ll * modinv25;
			i = modPow(26ll, p, MOD);
			i = (i-1) % MOD;
			ans = (ans * i) % MOD;
			ans = (ans*2)%MOD;
		}
		else {
			ans = 26ll * modinv25;
			i = modPow(26ll, p-1, MOD);
			i = (i-1) % MOD;
			ans = (ans * i) % MOD;
			ans = (ans*2)%MOD;
			j = modPow(26,p,MOD);
			ans = (ans+j)%MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
