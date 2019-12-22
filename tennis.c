#include<stdio.h>
     
int compare (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
     
int main()
{
	int t;
	int n, m, i, j, k;
	double p;
	int arr[10000];
	double pr[10000];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %lf", &n, &m, &p);
		for(i=0;i<m;i++)
		{
			scanf("%d",&arr[i]);
			pr[i] = 100;
		}
		j = m;
		qsort(arr, m, sizeof(int), compare);
		while(n/2)
		{
			i=0;
			for(k=0;i<j;k++)
			{
				if(i+1 < j && arr[i+1]-arr[i] == 1 && arr[i]%2)
				{
					arr[k]=(arr[i]+arr[i]%2)/2;
					pr[k]=pr[i]*(100-pr[i+1])*p/10000 + pr[i+1]*(100-pr[i])*p/10000 + pr[i]*pr[i+1]/100;
					i=i+2;
				}
				else
				{
					arr[k]=(arr[i]+arr[i]%2)/2;
					pr[k]=pr[i]*p/100.0;
					i++;
				}
			}
			j=k;
			n=n/2;
		}
		printf("%.7lf\n",pr[0]);
    }
	return 0;
} 
