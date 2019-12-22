#include <stdio.h>
#define MAXN	100000
struct node {
	int p;
	int rank;
} nodes[MAXN+10];

void makeset(void) {
	int i;
	for (i = 0; i < MAXN+10; i++) {
		nodes[i].p = i;
		nodes[i].rank = 0;
	}
}

int findset(int x)
{
	if (x != nodes[x].p)
		nodes[x].p = findset(nodes[x].p);
	return nodes[x].p;
}

void Union(int x, int y) {
	int t1, t2;
	t1 = findset(x);
	t2 = findset(y);
	if (nodes[t1].rank > nodes[t2].rank)
		nodes[t2].p = t1;
	else {
		nodes[t1].p = t2;
		if (nodes[t1].rank == nodes[t2].rank)
			nodes[t2].rank++;
	}
}

int count[MAXN+10], found[MAXN+10];
main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		int k;
		for (k = 0; k < MAXN+10; k++) {
			count[k] = 0;
			found[k] = 0;
		}
		makeset();
		while (m--) {
			int i, j;
			scanf("%d %d", &i, &j);
			Union(i, j);
		}
		int c = 0;
		for (k = 1; k <= n; k++) {
			int t = findset(k);
			if (found[t] == 0) {
				found[t] = 1;
				c++;
			}
			count[t]++;
		}
		long long int ans = 1;
		for (k = 1; k <= n; k++)
			if (count[k])
				ans = (ans * count[k]) % 1000000007;
		printf("%d %lld\n", c, ans);
	}
	return 0;
}
