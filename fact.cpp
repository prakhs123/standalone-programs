#include <stdio.h>
#define MOD 1000000007
long long fact[2013];
int main() {
	fact[0] = 1;
	fact[1] = 1;
	for	(int i = 2; i <= 2012; i++)
		fact[i] = (i*fact[i-1])%MOD;
	printf("%lld\n", ((fact[1000] * 1013) % MOD + 2014)%MOD);
}