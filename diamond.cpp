#include<stdio.h>
double c[2001][2001]={0,0};
inline int inp()
{
    int noRead=0;
    char p=getchar_unlocked();
    for(;p<33;)
    {
     p=getchar_unlocked();
    };
    while(p>32)
    {
     noRead = (noRead << 3) + (noRead << 1) + (p - '0');
     p=getchar_unlocked();
    }
    return noRead;
};
void compute()
{
 int i,j;
 for(i=1;i<=2000;i++)
 {
  for(j=1;j<=i;j++)
  {
      c[i][j]=1-(c[i-1][j-1]+c[i-1][j])/2;
  }
 }
}
int main()
{
    int t,n,v,i;
    double s;
    scanf("%d",&t);
    compute();
    while(t--)
    {
        scanf("%d",&n);
        s=0.0;
        for(i=1;i<=n;i++)
        {
           // scanf("%d",&v);
            v=inp();
            s+=(c[n][i]*v);
        }
        printf("%.3lf\n",s);
    }
    return 0;
}
 