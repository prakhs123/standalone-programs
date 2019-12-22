#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
 
#define MOD 3046201
#define MAXN 100000
#define ll long long
 
ll fact[MAXN * 30 + 1], invfact[MAXN + 1];
 
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
	for(i=1; i<=MAXN*30+1; i++)
		fact[i]=i*fact[i-1]%MOD;
	invfact[MAXN+1]=inverse(fact[MAXN+1]);
	for(i=MAXN+1; i>0; i--)
		invfact[i-1]=i*invfact[i]%MOD;
}

int BIT[MAXN+1];

int read(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += BIT[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val) {
    while (idx <= MAXN) {
        BIT[idx] += val;
        idx += (idx & -idx);
    }
}


ll Query(int K, int sum, int i, int x) {
    ll ans;
    ans = ( fact[sum]*powmod(invfact[x + 1], i) )%MOD;
    ans = ( ans*powmod(invfact[x], K-i) )%MOD;
    ans = ( ans*fact[K] )%MOD;
    ans = ( ans*invfact[i] )%MOD;
    ans = ( ans*invfact[K-i] )%MOD;
    return ans;
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

int main()
{
	int N, Q, L, R, A, C;
	int B[MAXN+1];
	char s, c;
	scan(&N);
	int j;
	int K, sum, x, i;
	init();
	for (j = 1; j <= N; j++) {
		scan(&B[j]);
        update(j, B[j]);
    }
	scan(&Q);
	while (Q--) {
		s = getchar_unlocked();
        while(!isspace(getchar_unlocked()));
		if (s == 'c') {
			scan(&A);
            scan(&C);
			update(A,C-B[A]);
            B[A] = C;
		}
		else {
			scan(&L);
            scan(&R);
			K = R - L + 1;
			sum = (L!=1) ? read(R) - read(L-1) : read(R);
			i = sum % K;
			x = sum / K;
			printf("%lld\n", Query(K, sum, i, x));
		}
	}
	return 0;
}
