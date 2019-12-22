#include<iostream>
#include<cstdio>
#include<vector>
#define MOD 1000000007
using namespace std;
char color[100005];
void dfs_visit(vector<int> V[],int i,int &cnt)
{
    color[i]='g';
    int sz = V[i].size();
    for(int j=0;j<sz;++j)
    {
        if(color[V[i][j]]=='w')dfs_visit(V,V[i][j],cnt);
    }
    color[i] = 'b';
    ++cnt;
}
void dfs(vector<int> V[],int n,long long &f,long long &s)
{
    for(int i=1;i<=n;++i)
    {
        if(color[i]=='w')
        {
            ++f;
            int cnt = 0;
            dfs_visit(V,i,cnt);
            s = s*cnt;
            s %= MOD;
        }
    }
}
int main()
{
    int t,i,n,m,a,b;
    scanf("%d",&t);
    while(t--)
    {
        long long first = 0,second = 1;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;++i)color[i] = 'w';
        vector<int> V[n+1];
        while(m--)
        {
            scanf("%d %d",&a,&b);
            V[a].push_back(b);
            V[b].push_back(a);
        }
        dfs(V,n,first,second);
        printf("%lld %lld\n",first,second);
    }
    return 0;
}
