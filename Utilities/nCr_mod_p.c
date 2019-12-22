// Use 64 bits integers to avoid overflow errors during multiplication.
long modPow(long a, long x, long p) {
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

long modInverse(long a, long p) {
    //calculates the modular multiplicative of a mod m.
    //(assuming p is prime).
    return modPow(a, p-2, p);
}
long modBinomial(long n, long k, long p) {
// calculates C(n,k) mod p (assuming p is prime).

    long numerator = 1; // n * (n-1) * ... * (n-k+1)
    for (int i=0; i<k; i++) {
        numerator = (numerator * (n-i) ) % p;
    }
    
    long denominator = 1; // k!
    for (int i=1; i<=k; i++) {
        denominator = (denominator * i) % p;
    }
    
    // numerator / denominator mod p.
    return ( numerator* modInverse(denominator,p) ) % p;
}

public int calculate(int k, int n) {
    return (int)( modBinomial(n+k,k+1, 1000000007) );
}
/*-------------------------------------*/
#include <cstdio>
#define MOD 1000000007
#define MAXN 100000
#define ll long long
 
ll fact[MAXN + 30], invfact[MAXN + 30];
 
ll powmod(ll base, ll expo){
    if(expo==0)
        return 1;
    else if(expo&1)
        return base*powmod(base, expo-1)%MOD;
    else{
        ll root=powmod(base, expo>>1);
        return root*root%MOD;
    }
}
 
ll inverse(ll x){
    return powmod(x, MOD-2);
}
 
void init(){
    fact[0]=1;
    ll i;
    for(i=1; i<MAXN+30; i++)
        fact[i]=i*fact[i-1]%MOD;
    invfact[MAXN+29]=inverse(fact[MAXN+29]);
    for(i=MAXN+29; i>0; i--)
        invfact[i-1]=i*invfact[i]%MOD;
} 
int nCr(int n, int r){
	if(r>n || r<0)
		return 0;
	return (((fact[n]*invfact[n-r])%MOD) * invfact[r]) % MOD;
}
 
