#include <stdio.h>
#include <string.h>
#include <set>

#define MAXN	100000
#define INF	1000000000

using namespace std;

struct node {
	int p;
	int rank;
} nodes[MAXN + 10];

void makeset(int n) {
	int i;
	for (i = 0; i <= n; i++) {
		nodes[i].p = i;
		nodes[i].rank = 0;
	}
}

int findset(int x) {
	if (x != nodes[x].p)
		nodes[x].p = findset(nodes[x].p);
	return nodes[x].p;
}

void makeunion(int x, int y) {
	int p1, p2;
	p1 = findset(x);
	p2 = findset(y);
	if (nodes[p1].rank > nodes[p2].rank)
		nodes[p2].p = p1;
	else {
		nodes[p1].p = p2;
		if (nodes[p1].rank == nodes[p2].rank)
			nodes[p2].rank++;
	}
}

int mincost[MAXN + 10];

int main() {
	int N, M, A, B, C;
	scanf("%d %d", &N, &M);
	makeset(N);
	memset(mincost, -1, sizeof(mincost));
	int i;
	int minc;
	for (i = 0; i < M; i++) {
		scanf("%d %d", &A, &B);
		makeunion(A, B);
	}
	minc = INF;
	set<int> component;
	for (i = 1; i <= N; i++) {
		scanf("%d", &C);
		int root = findset(i);
		component.insert(root);
		if (mincost[root] == -1)
			mincost[root] = INF;
		if (C >= 0) {
			if (C < mincost[root])
				mincost[root] = C;
			if (C < minc)
				minc = C;
		}
	}
	if (component.size() == 1) {
		printf("0\n");
		return 0;
	}
	int sum = 0;
	int f = 0;
	
	for (set<int> :: iterator it = component.begin(); it != component.end(); it++) {
		if (mincost[*it] == INF) {
			f = 1;
			break;
		}
		sum += mincost[*it];
	}
	if (f)
		printf("-1\n");
	else
		printf("%d\n", sum + (component.size() - 2) * minc);

	return 0;
}