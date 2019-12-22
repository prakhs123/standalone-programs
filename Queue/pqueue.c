#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

#define NUMNODES	500

struct nodetype {
	int info, next;
};
struct nodetype node[NUMNODES];
int avail;

void init(void) 
{
	avail = 0;
	int i;
	for (i = 0; i < NUMNODES-1; i++)
		node[i].next = i + 1;
	node[NUMNODES-1].next = -1;
}

int getnode(void)
{
	int p;
	if (avail == -1) {
		printf("overflow\n");
		exit(1);
	}
	p = avail;
	avail = node[avail].next;
	return p;
}

void freenode(int p)
{
	node[p].next = avail;
	avail = p;
	return;
}

struct pqueue {
	int front, rear;
};

void pqinit(struct pqueue *pq)
{
	pq->front = -1;
	pq->rear = -1;
}

int empty(struct pqueue *pq)
{
	return ((pq->front == -1) ? TRUE: FALSE);
}

void pqinsert(struct pqueue *pq, int x)
{
	int p;
	p = getnode();
	node[p].info = x;
	if (pq->rear == -1) {
		pq->front = p;
		pq->rear = p;
		node[p].next = -1;
	}
	else {
		if (x < node[pq->front].info) {
			node[p].next = pq->front;
			pq->front = p;
		}
		else {
			int i, j;
			i = node[pq->front].next;
			j = pq->front;
			while (i != -1 && node[i].info < x) {
				j = i;
				i = node[i].next;
			}
			node[j].next = p;
			node[p].next = i;
			if (i == -1)
				pq->rear = p;
		}
	}
}

int pqmindelete(struct pqueue *pq)
{
	int p, x;
	
	if (empty(pq)) {
		printf("pqueue underflow\n");
		exit(1);
	}
	
	p = pq->front;
	x = node[p].info;
	pq->front = node[p].next;
	if (pq->front == -1)
		pq->rear = -1;
	freenode(p);
	return x;
}

main()
{
	init();
	struct pqueue pq;
	pqinit(&pq);
	pqinsert(&pq, 3);
	pqinsert(&pq, 2);
	pqinsert(&pq, 17);
	pqinsert(&pq, 36);
	pqinsert(&pq, 11);
	pqinsert(&pq, 18);
	int i = 1;
	while (i++ <= 6)
		printf("%d\n", pqmindelete(&pq));
	
	return 0;
}
