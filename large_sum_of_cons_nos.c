#include <stdio.h>
#define N 100
int bs[N]={0};
int a[N];
int max=0;
int bestsum(int index,int n)
{
    if(bs[index]>0)// Already Stored
        return bs[index];
    if(index == n){//termination condition
        bs[index]=a[index];
        if(bs[index]>max)
            max=bs[index];
        return a[index];
    }
    int temp=bestsum(index+1,n); // recursion
    int sum=a[index];
    if(temp > 0)    // add only if its positive
        sum+=temp;
    bs[index]=sum; // store for further calls
    if(sum>max)
        max=sum;
    return sum;
}
int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    bestsum(0,n-1);
        printf("%d\n",max);
    return 0;
}
