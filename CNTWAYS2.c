#include <stdio.h>

#define	ll long long
#define	MOD	1000000007ll

ll fact[800001], fact_inv[800001];

ll modPow(ll a, ll x, ll p)
{
	ll res = 1;
	while (x > 0ll) {
		if (x % 2 != 0) {
			res = (res * a) % p;
		}
		a = (a * a) % p;
		x /= 2;
	}
	
	return res;
}

ll modInverse(ll a, ll p) {
	return modPow(a, p-2, p);
}

ll comb(int a,int b){
  return (((fact[a] * fact_inv[b]) % MOD) * fact_inv[a-b]) % MOD;
}

ll ways(int a, int b){
  return comb(a+b, a);
}

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
	int i;
	fact[0] = fact[1] = fact_inv[0] = fact_inv[1] = 1;
	for (i = 2; i <= 800000; i++) {
		fact[i] = (i * fact[i-1]) % MOD;
		fact_inv[i] = modInverse(fact[i], MOD);
	}
	int N, M, A, B;
	int p;
	int t;
	ll result;
	scan(&t);
	while(t--) {
		scan(&N);
		scan(&M);
		scan(&A);
		scan(&B);
		result = 0;
		for (p = 0; p <= N-A; p++) {
			result += ways(p, B-1) * ways(N-p, M-B);
			result %= MOD;
		}
			
		printf("%lld\n", result);
	}
	
	return 0;
}
