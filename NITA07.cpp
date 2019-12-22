#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#define In first
#define out second
using namespace std;
int answer[105][105];
char arr[105][105];
char color[105][105];
void BFS(int r,int c)
{
    int i=0,j=0;answer[i][j] = 0;
    queue< pair<int,int> > Q;
    pair<int,int> P;
    P.In = i;P.out = j;
    color[i][j] = 'g';
    Q.push(P);
    while(!Q.empty())
    {
        pair<int,int> p = Q.front();
        int x = p.In,y = p.out;
        if(x+1<r && y+1<c && color[x+1][y+1]=='w' && arr[x+1][y+1]=='0'){
		    answer[x+1][y+1] = answer[x][y]+1;
		    color[x+1][y+1]='g';
		    P.In = x+1;
		    P.out = y+1;
		    Q.push(P);
        }
        if(x+1<r && color[x+1][y]=='w' && arr[x+1][y]=='0'){answer[x+1][y] = answer[x][y]+1;color[x+1][y]='g';P.In = x+1;P.out = y;Q.push(P);}
        if(x+1<r && y-1>=0 && color[x+1][y-1]=='w' && arr[x+1][y-1]=='0'){answer[x+1][y-1] = answer[x][y]+1;color[x+1][y-1]='g';P.In = x+1;P.out = y-1;Q.push(P);}
        if(y+1<c && color[x][y+1]=='w' && arr[x][y+1]=='0'){answer[x][y+1] = answer[x][y]+1;color[x][y+1]='g';P.In = x;P.out = y+1;Q.push(P);}
        if(y-1>=0 && color[x][y-1]=='w' && arr[x][y-1]=='0'){answer[x][y-1] = answer[x][y]+1;color[x][y-1]='g';P.In = x;P.out = y-1;Q.push(P);}
        if(x-1>=0 && y+1<c && color[x-1][y+1]=='w' && arr[x-1][y+1]=='0'){answer[x-1][y+1] = answer[x][y]+1;color[x-1][y+1]='g';P.In = x-1;P.out = y+1;Q.push(P);}
        if(x-1>=0 && color[x-1][y]=='w' && arr[x-1][y]=='0'){answer[x-1][y] = answer[x][y]+1;color[x-1][y]='g';P.In = x-1;P.out = y;Q.push(P);}
        if(x-1>=0 && y-1>=0 && color[x-1][y-1]=='w' && arr[x-1][y-1]=='0'){answer[x-1][y-1] = answer[x][y]+1;color[x-1][y-1]='g';P.In = x-1;P.out = y-1;Q.push(P);}
        color[x][y] = 'b';
        Q.pop();
    }
}
int main()
{
    int r,c;scanf("%d",&r);
    for(int i=0;i<r;++i)
    {
        scanf("%s",arr[i]);
        c = strlen(arr[i]);
        for(int j=0;j<c;++j)
        {
            color[i][j] = 'w';
        }
    }
    BFS(r,c);
    printf("%d\n",answer[r-1][c-1]+1);
    return 0;
}
