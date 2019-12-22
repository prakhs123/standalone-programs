#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
map<string,string> M1;
map<string,int> M2;//countries
map<string,int> M3;//chefs
map<string,int>:: iterator it;
int main()
{
    int n,m;string first,second;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i)
    {
        cin>>first>>second;
        M1[first] = second;
    }
    for(int i=0;i<m;++i)
    {
        cin>>first;
        ++M2[M1[first]];
        ++M3[first];
    }
    string answer;int maxel = -1;
    for(it=M2.begin();it!=M2.end();++it)
    {
        if(it->second>maxel){maxel = it->second;answer = it->first;}
        else if(it->second==maxel){if(it->first<answer)answer = it->first;}
    }
    cout<<answer<<endl;
    maxel = -1;
    for(it=M3.begin();it!=M3.end();++it)
    {
        if(it->second>maxel){maxel = it->second;answer = it->first;}
        else if(it->second==maxel){if(it->first<answer)answer = it->first;}
    }
    cout<<answer<<endl;
    return 0;
}
