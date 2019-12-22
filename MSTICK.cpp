#include<cstdio>
#include<iostream>

using namespace std;

#define MAX 100000
#define left( i ) ( 2*(i) + 1 )
#define right( i ) ( 2*(i) + 2 )
#define INF -1000000000
int tree_max[3*MAX+10];
int tree_min[3*MAX+10];
int A[MAX+10];
int N;

void build( int idx, int start, int end ){
	if( start == end ) {
		tree_max[idx] = tree_min[idx] = start;
		return;
	}
	build( left( idx ), start, ( start + end )/2 );
	build( right( idx ), ( start + end )/2 + 1, end );
	if( A[ tree_max[ left(idx) ] ] > A[ tree_max[ right(idx) ] ] )
		tree_max[idx] = tree_max[ left(idx) ];
	else
		tree_max[idx] = tree_max[ right(idx) ];
	if( A[ tree_min[ left(idx) ] ] < A[ tree_min[ right(idx) ] ] )
		tree_min[idx] = tree_min[ left(idx) ];
	else
		tree_min[idx] = tree_min[ right(idx) ];
}

int find_max( int idx, int start, int end, int i, int j ){
	if( i > end || j < start )
		return -1;
	if( start >= i && end <= j )
		return tree_max[idx];
	int L = find_max( left(idx), start, (start + end)/2, i, j ), R = find_max( right(idx), (start + end)/2 + 1, end, i, j ) ;
	if( L == -1 )
		return R;
	if( R == -1 )
		return L;
	return A[L] > A[R] ? L : R;
}

int find_min( int idx, int start, int end, int i, int j ){
	if( i > end || j < start )
		return -1;
	if( start >= i && end <= j )
		return tree_min[idx];
	int L = find_min( left(idx), start, (start + end)/2, i, j ), R = find_min( right(idx), (start + end)/2 + 1, end, i, j ) ;
	if( L == -1 )
		return R;
	if( R == -1 )
		return L;
	return A[L] < A[R] ? L : R;
}

int main()
{
	int L,R,Q;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",A+i);
	scanf("%d",&Q);
	build(0,0,N-1);
	float res,left,right,mid;
	while(Q--)
	{
		scanf("%d%d",&L,&R);
		int x=find_min(0,0,N-1,L,R);
		int y=find_max(0,0,N-1,0,L-1);
		int z=find_max(0,0,N-1,R+1,N-1);
		int u=find_max(0,0,N-1,L,R);
		float left=((y!=-1)?A[y]:INF);
		float right=((z!=-1)?A[z]:INF);
		left+=A[x];
		right+=A[x];
		//printf("%d %d\n",u,x);
		float mid=(float)(A[u]+A[x])/2.0;
		res=max(left,right);
		//printf("%f %f %f",left,right,mid);
		if(res<mid)
		res=mid;
		printf("%.1f\n",res);
	}
}
