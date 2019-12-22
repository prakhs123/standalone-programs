#include <stdio.h>
int main()
{
int n,a[100],i,j,k;
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n;i++)
{
int b[160]={0},m=1;
b[0]=1;
for(j=2;j<=a[i];j++)
{
int temp=0,x;
for(k=0;k<m;k++)
{
x=b[k]*j+temp;
b[k]=x%10;
temp=x/10;
}
while(temp>0)
{
b[k++]=temp%10;
temp/=10;
m++;
}
}
printf("%d\n", m);
for(j=m-1;j>=0;j--)
printf("%d",b[j]);
printf("\n");
}
return 0;
}
