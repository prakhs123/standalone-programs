#include<stdio.h>
long long int expn[201][201];
int pwr[101];
int in[101];
int n,m;
 
void expansion()
{
	int i=0,j=0;
	expn[0][0]=1;
	for(i=1;i<200;i++)
	{
		expn[i][0]=1;
		for(j=0;j<i-1;j++)
		{
			expn[i][j+1]=(expn[i-1][j]+expn[i-1][j+1])%1000000007;
		}
		expn[i][j+1]=1;
	}
}
 
void initialize()
{
	int i;
	bzero(pwr,sizeof(pwr));
	bzero(in,sizeof(in));
	pwr[0]=1;
}
 
int main()
{
	int t;
	scanf("%d",&t);
	expansion();
	while(t--)	
	{
		initialize();
		int i=0,x=0,y=0,j=0;
		long long int sum=0;
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&x,&y);
			n=n-x;
			in[i]=y-x+1;
		}
		for(i=0;i<m;i++)
		{
			for(j=100;j>=0;j--)
			{
				if( pwr[j]!=0 )
				{
					if( j+in[i]<=n )
					{
						pwr[j+in[i]]=pwr[j+in[i]]+pwr[j]*-1;
					}
				}
			}
		}
		 
		for(i=0;i<=n;i++)
		{
			// printf("accessing ---> %d %d to get %lld\n",m+n-i-1,n-i,expn[m+n-i-1][n-i]);
			sum=(sum+expn[m+n-i-1][n-i]*((long long int)pwr[i]))%1000000007;
		}
		printf("%lld\n",(1000000007+sum)%1000000007);
	}
	return 0;
}
