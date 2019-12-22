#include <stdio.h>

#define MAXN	100005
#define MAXIND	400100
#define INF -1000000000
int A[MAXN];
int M1[MAXIND], M2[MAXIND];

void initialize1(int node, int b, int e)
{
	if (b == e)
		M1[node] = b;
	else
	{
		initialize1(2 * node, b, (b + e) / 2);
		initialize1(2 * node + 1, (b + e) / 2 + 1, e);
		//search for the minimum value in the first and 
		//second half of the interval
		if (A[M1[2 * node]] < A[M1[2 * node + 1]])
			M1[node] = M1[2 * node];
		else
			M1[node] = M1[2 * node + 1]; 
	}
}

int query1(int node, int b, int e, int i, int j)
{
	int p1, p2;

	//if the current interval doesn't intersect 
	//the query interval return -1
	if (i > e || j < b)
		return -1;

	//if the current interval is included in 
	//the query interval return M[node]
	if (b >= i && e <= j)
		return M1[node];
   
	//compute the minimum position in the 
	//left and right part of the interval
	p1 = query1(2 * node, b, (b + e) / 2, i, j);
	p2 = query1(2 * node + 1, (b + e) / 2 + 1, e, i, j);

	//return the position where the overall 
	//minimum is
	if (p1 == -1)
		return p2;
	if (p2 == -1)
		return p1;
	return A[p1] < A[p2] ? p1 : p2;
}

void initialize2(int node, int b, int e)
{
	if (b == e)
		M2[node] = b;
	else
	{
		initialize2(2 * node, b, (b + e) / 2);
		initialize2(2 * node + 1, (b + e) / 2 + 1, e);
		//search for the minimum value in the first and 
		//second half of the interval
		if (A[M2[2 * node]] > A[M2[2 * node + 1]])
			M2[node] = M2[2 * node];
		else
			M2[node] = M2[2 * node + 1]; 
	}
}

int query2(int node, int b, int e, int i, int j)
{
	int p1, p2;

	//if the current interval doesn't intersect 
	//the query interval return -1
	if (i > e || j < b)
		return -1;

	//if the current interval is included in 
	//the query interval return M[node]
	if (b >= i && e <= j)
		return M2[node];
   
	//compute the minimum position in the 
	//left and right part of the interval
	p1 = query2(2 * node, b, (b + e) / 2, i, j);
	p2 = query2(2 * node + 1, (b + e) / 2 + 1, e, i, j);

	//return the position where the overall 
	//minimum is
	if (p1 == -1)
		return p2;
	if (p2 == -1)
		return p1;
	return A[p1] > A[p2] ? p1 : p2;
}

main()
{
	int N, Q, L, R, i;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);
	for (i = 0; i < MAXIND; i++)
		M1[i] = M2[i] = -1;
	initialize1(1,0,N-1);
	initialize2(1,0,N-1);
	scanf("%d", &Q);
	for (i = 0; i < Q; i++) {
		scanf("%d %d", &L, &R);
		int x, p, q, y;
		x = query1(1,0,N-1,L,R);
		p = query2(1,0,N-1,0,L-1);
		q = query2(1,0,N-1,R+1,N-1);
		y = query2(1,0,N-1,L,R);
		double a, b, c;
		a = (p != -1) ? A[p] : INF;
		b = (q != -1) ? A[q] : INF;
		a += A[x];
		b += A[x];
		c = (double)(A[x]+A[y]) / 2.0;
		double res;
		res = a > b ? a: b;
		if (res < c)
			res = c;
		printf("%.1f\n", res);
	}
	return 0;
}
