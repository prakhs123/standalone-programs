 /*
    Catagory:Dynamic Programming
    Author:Khadar Basha
    Execution Time:1 sec
    */
    #include<stdio.h>
    #include<string.h>
    #define inf 9999
    #define FOR(i,n) for(i=0;i<n;i++)
    #define FORI(i,a,n) for(i=a;i<=n;i++)
    int main()
    {
		int res = 0, dp[1001], hash[501], h[501], s[501], t, n, m=-1, i, j, k, z;
		scanf("%d",&t);
		while(t--)
		{
			m=-1;
			scanf("%d",&n);
			FOR(i,n)
			{
				scanf("%d",&h[i]);
				if(h[i] > m)
					m=h[i];
			}
			memset(dp,inf,sizeof(dp));
			memset(hash,0,sizeof(hash));
			z=0;
			FOR(i,n)
			{
				scanf("%d",&k);
				if(hash[k]==0)	/*used to remove duplicates*/
				{
					s[z++]=k;
					hash[k]=1;
				}
			}
			dp[0]=0;
			FOR(i,z)
				FORI(j,0,2*m-s[i])
				/*This calculation can be done directly whenever we found an unique-element*/
					{
					if(dp[j] + 1 < dp[j+s[i]])
						dp[j+s[i]] = dp[j] + 1;
					/*Here we are adding the coin value and in the Dp table we are updating the total denominations for the resultant sum value*/
					}
			res=0;
			FOR(i,n)
				res += dp[2*h[i]];
			printf("%d\n",res);

		}
		return 0;
    }

