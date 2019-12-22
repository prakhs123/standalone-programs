#include <stdio.h>
#include <stdlib.h>

#define MAXN	100000

struct adj {
	int id;
	struct adj *next;
};

struct ids {
	struct adj *adj;
} nodes[MAXN+10];

main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int i, n, m;
		scanf("%d %d", &n, &m);
		for (i = 0; i < MAXN+10; i++)
			nodes[i].adj = NULL;
		while (m--) {
			int x, y;
			scanf("
