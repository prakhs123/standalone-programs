#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<stack>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#define CLRM(x) memset(x,-1,sizeof(x))
#define CLR(x) memset(x,0,sizeof(x))
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define VI vector<int>
#define VVI vector<vector<int> >
#define PII pair<int,int>
#define SZ(x) (int)x.size()
#define LL long long
#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a,b) (a)>(b)?(a):(b)
#define LMAX 1000000000000000000LL
#define IMAX 100000000
using namespace std;
bool primes[510000];
int pr[510000];
int sq[510000];
int npr;
int n;
int flag=0;
#define MOD 10000
inline int fastpow (int a, int b)
{
int p = 1;
//cout<<a<<" "<<b<<endl;
while (b > 0)
{
if(a>=MOD)
flag=1;
a=a%MOD;
if (b & 1) p = p * a;
p%=MOD;
a = a * a;
b >>= 1;
}
return p;
}
int solve(int _t)
{
int i,j,k;
int div=1;
int t=_t;
for(i=0;t>1 && i<npr;i++)
{
int tp=0;
while(t%pr[i]==0)
{
tp++;
t/=pr[i];
}
div*=(tp+1);
if(primes[t]==0)
break;
}
if(t!=1)
{
div*=2;
}
//cout<<div<<" "<<t<<endl;
int ft=0;
if(sq[_t]!=0)
{
_t=sq[_t];
return fastpow(_t,div-2);
}
else
{
return fastpow(_t,div/2-1);
}
return 0;
}
int main()
{
CLR(primes);
CLR(sq);
primes[1]=1;
primes[0]=1;
int i,j,k;
npr=0;
for(i=1;i*i<=500100;i++)
sq[i*i]=i;
for(i=2;i<=500100;i++)
{
if(primes[i]==1)
continue;
pr[npr++]=i;
for(j=i*i;j<=500100 && j>0;j+=i)
{
primes[j]=1;
}
}
//cout<<npr<<endl;
scanf("%d",&n);
for(i=0;i<n;i++)
{
int t;
scanf("%d",&t);
flag=0;
int ans = solve(t);
if(flag==1)
{
int t1=1000;
while(t1!=0 && ans/t1==0)
{
t1/=10;
printf("0");
}
}
if(ans!=0)
{
printf("%d\n",ans);
}
else
{
printf("\n");
}
}
return 0;
}
