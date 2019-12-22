#include <cstdio>
 
#define MOD 1000000007
 
int fact[5001], invfact[5001];
 
int powmod(int base, int expo){
	if(expo==0)
		return 1;
	else if(expo&1)
		return (long long)base*powmod(base, expo-1)%MOD;
	else{
		int root=powmod(base, expo>>1);
		return (long long)root*root%MOD;
	}
}
 
int inverse(int x){
	return powmod(x, MOD-2);
}
 
void init(){
	fact[0]=1;
	for(int i=1; i<=5000; i++)
		fact[i]=(long long)i*fact[i-1]%MOD;
	invfact[5000]=inverse(fact[5000]);
	for(int i=5000; i>0; i--)
		invfact[i-1]=(long long)i*invfact[i]%MOD;
}
 
int nCr(int n, int r){
	if(r>n || r<0)
		return 0;
	return (long long)((long long)fact[n]*invfact[r]%MOD)*invfact[n-r]%MOD;
}

int main()
{
	init();
	for(int i = 1; i <= 1000; i++) {
		int count = 0;
		for(int j = i/2+1; j <= i; j++)
			count = (count + nCr(i,j))%MOD;
		printf("%d,", count);
	}
	return 0;
}
