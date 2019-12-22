#include<iostream>
#include<cstdio>
#define SIZE 10000000
using namespace std;
long long int answer = 0;int counter = 0;
bool isprime[SIZE]={1,1};
int pi[SIZE]={};
int mat[351][351];
char color[351][351];
void precompute()
{
    for(long long int i=2;i<SIZE;++i)
    {
        if(isprime[i]==0)
        {
            ++counter;
            pi[i] = counter;
            for(long long int j = i*i;j<SIZE;j += i)
            {
                isprime[j] = 1;
            }
        }
    }
}
void dfs_visit(int i,int j,int n)
{
    color[i][j] = 'g';
    if(mat[i][j]&1)
        {
            //cout<<"debug      : "<<i<<" "<<j<<" "<<answer<<endl;
            if(i+1<n && isprime[mat[i+1][j]] && mat[i+1][j]&1 && color[i+1][j]=='w')
            {
            	dfs_visit(i+1,j,n);
            }
            if(i-1>=0 && isprime[mat[i-1][j]] && mat[i-1][j]&1 && color[i-1][j]=='w')
            {
            	dfs_visit(i-1,j,n);
            }
            if(j+1<n && isprime[mat[i][j+1]] && mat[i][j+1]&1 && color[i][j+1]=='w')
            {
            	dfs_visit(i,j+1,n);
            }
            if(j-1>=0 && isprime[mat[i][j-1]] && mat[i][j-1]&1 && color[i][j-1]=='w')
            {
            	dfs_visit(i,j-1,n);
            }
        }
    else
        {
            //cout<<"debug      : "<<i<<" "<<j<<" "<<answer<<endl;
            if(i+1<n && isprime[mat[i+1][j]] && !(mat[i+1][j]&1) && color[i+1][j]=='w')
            {	
            	dfs_visit(i+1,j,n);
            }
            if(i-1>=0 && isprime[mat[i-1][j]] && !(mat[i-1][j]&1) && color[i-1][j]=='w')
            {
            	dfs_visit(i-1,j,n);
            }
            if(j+1<n && isprime[mat[i][j+1]] && !(mat[i][j+1]&1) && color[i][j+1]=='w')
            {
            	dfs_visit(i,j+1,n);
            }
            if(j-1>=0 && isprime[mat[i][j-1]] && !(mat[i][j-1]&1) && color[i][j-1]=='w')
            {
            	dfs_visit(i,j-1,n);
            }
        }
}
void dfs(int n)
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(color[i][j]=='w')
                {
                    if(!isprime[mat[i][j]])
                    {
                        answer += (pi[mat[i][j]]-1);
                        //cout<<"debug  : "<<i<<" "<<j<<" "<<answer<<endl;
                        color[i][j] = 'g';
                    }
                    else if(isprime[mat[i][j]] && color[i][j]=='w')
                    {
                        if(!(mat[i][j]&1))
                        	answer += (mat[i][j]>>1);
                        else 
                        	answer += ((mat[i][j]+1)>>1)+1;
                        dfs_visit(i,j,n);
                        color[i][j] = 'g';
                    }
                }
        }
    }
}
int main()
{
    precompute();
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                scanf("%d",&mat[i][j]);
                color[i][j] = 'w';
            }
        }
        dfs(n);
        printf("%lld\n",answer);
        answer = 0;
    }
    return 0;
}
