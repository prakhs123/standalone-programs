#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#define MOD 1000000007
using namespace std;
int P[100005];
int R[100005];
int found[100005];
int c[100005];
void init()
{
	for(int i=0;i<100005;i++)
	{
		R[i]=0;
		P[i]=i;
	}
}
int find(int n)
{
	if(P[n]==n)
		return n;
	return P[n]=find(P[n]);
}
void join(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a==b)
		return;

	if(R[a]<R[b])
		P[a]=b;
	else
	{
		P[b]=a;
		if(R[a]==R[b])
			R[a]++;
	}
}
int main()
{
	int T,N,M,x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		int ctr=0;
		for(int i=0;i<100005;i++)
			found[i]=0,c[i]=0;
		init();
		for(int i=0;i<M;i++)
		{
			scanf("%d%d",&x,&y);
			join(x,y);
		}
		for(int i=1;i<=N;i++)
		{
			if(found[find(i)]==0)
			{
				ctr++;
				found[find(i)]=1;
			}
			c[find(i)]++;
		}
		long long int res=1;
		for(int i=1;i<=N;i++)
			if(c[i])
				res=(res*c[i])%MOD;
		printf("%d %lld\n",ctr,res);
	}
}
