// BIT or Fenwick
#include<stdio.h>
#define get getchar_unlocked
#define moD 3046201
 
inline int scan32()
{
    register int n=0,s=1;
    char p=get();
    if(p=='-')  s=-1;
    while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
    if(p=='-') s=-1,p=get();
    while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
    return n*s;
}
 
int segTree[100001];
 
int querySum(int idx)
{
    int sum = 0;
    while (idx > 0)
    {
        sum += segTree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
 
void updateTree(int idx ,int val)
{
    while (idx <= 100001)
    {
        segTree[idx] += val;
        idx += (idx & -idx);
    }
}
 
int modPow(int X, int Y)
{
    long long Temp,Ans;
    if(!Y) return 1;
    Temp = modPow(X,Y/2);
    Ans = (Temp*Temp)%moD;
    if(!(Y&1)) return Ans;
    else return (X*Ans)%moD;
}
 
long long fact[3000001], ifact[100001], modInverse[100001];
 
int factorials()
{
    int i;
    fact[0] = fact[1] = ifact[0] = ifact[1] = modInverse[1] = 1;
    for(i=2; i<=3000000; i++)  fact[i] = (fact[i-1]*i)%moD;
    for(i=2; i<=100000; i++)  modInverse[i] = (-(moD/i) * modInverse[moD%i])%moD + moD;
    for(i=2; i<=100000; i++)  ifact[i] = (modInverse[i] * ifact[i-1])%moD;
}
 
long long Query(int sum, int k)
{
    long long Ans;
    printf("--- %d %lld %lld %d\n", sum, fact[sum], ifact[sum/k + 1], modPow(ifact[sum/k +1], sum%k));
    Ans = ( fact[sum]*modPow(ifact[sum/k + 1], sum%k) )%moD;
    printf("%lld ", Ans);
    Ans = ( Ans*modPow(ifact[sum/k], k-sum%k) )%moD;
    printf("%lld ", Ans);
    Ans = ( Ans*fact[k] )%moD;
    printf("%lld ", Ans);
    Ans = ( Ans*ifact[sum%k] )%moD;
    printf("%lld ", Ans);
    Ans = ( Ans*ifact[k-sum%k] )%moD;
    return Ans;
}
 
int main()
{
    factorials();
    char S[8];
    int i,N,Q,L,R,sum;
    N = scan32();
    int A[N+1];
    for(i=1; i<=N; i++)  { A[i] = scan32();  updateTree(i,A[i]); }
    Q = scan32();
    while(Q--)
    {
        scanf("%s",S);  L = scan32();  R = scan32();
        if(S[0]=='q')
        {
            sum = (L!=1) ? querySum(R) - querySum(L-1) : querySum(R);  // L-1-1 =0 not defined.
            if(sum==0) { printf("1\n"); continue; }
            printf("%lld\n",Query(sum, R-L+1));
        }
        else if(S[0]=='c')
        {
            updateTree(L,(R-A[L]));
            A[L] = R;
        }
    }
    return 0;
} 