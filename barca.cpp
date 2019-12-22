#include<iostream>
#include<cstdio>
#define MOD 1000000007
using namespace std;
long long buffer[11][1001];
int t,n,k;
void precomp()
{
for(int i=1;i<=10;++i)
{
buffer[i][2] = i;
buffer[i][3] = i*(i-1);
for(int j=4;j<=1000;++j)
{
buffer[i][j] = ((i*buffer[i][j-2])%MOD+((i-1)*buffer[i][j-1])%MOD)%MOD;
}
}
}
void solve()
{
scanf("%d",&t);
while(t--)
{
scanf("%d %d",&n,&k);
printf("%lld\n",buffer[k][n]);
}
}
long long answer;
int main()
{
precomp();
solve();
return 0;
}
