#include <stdio.h>
#define LL long long
#define MOD	1000000007
LL modPow(LL a, LL x) {
	LL res = 1;
	while(x > 0) {
		if( x&1 ) {
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		x >>= 1;
	}
	return res;
}
 
LL modInverse(LL a) {
//calculates the modular multiplicative of a mod m.
//(assuming p is prime).
	return modPow(a, MOD-2);
}
LL modBinomial(LL n, LL k) {
// calculates C(n,k) mod p (assuming p is prime).
 
	LL numerator = 1,i; // n * (n-1) * ... * (n-k+1)
	for (i=0; i<k; ++i) {
		numerator = (numerator * (n-i) ) % MOD;
	}	
 
	LL denominator = 1; // k!
	for (i=1; i<=k; ++i) {
		denominator = (denominator * i) % MOD;
	}
 
	// numerator / denominator mod p.
	return ( numerator* modInverse(denominator) ) % MOD;
}

int main()
{
	
}