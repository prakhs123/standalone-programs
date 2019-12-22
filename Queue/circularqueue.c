#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE	100
struct queue {
	int items[MAXQUEUE];
	int front, rear;
};

void initqueue (struct queue *s) {
	s->front = s->rear = MAXQUEUE-1;
}

int empty(struct queue *s) {
	return ((s->front == s->rear) ? 1 : 0);
}

int remove1(struct queue *s)
{
	if (empty(s)) {
		printf("queue underflow\n");
		exit(1);
	}
	if (s->front == MAXQUEUE-1)
		s->front = 0;
	else
		s->front++;
	return s->items[s->front];
}

void insert(struct queue *s, int x) {
	if (s->rear == MAXQUEUE-1)
		s->rear = 0;
	else
		s->rear++;
	if (s->rear == s->front) {
		printf("queue overflow\n");
		exit(1);
	}
	s->items[s->rear] = x;
	return;
}

main()
{
	struct queue a;
	initqueue(&a);
	insert(&a, 1);
	insert(&a, 17);
	insert(&a, 3);
	printf("%d\n", remove1(&a));
	printf("%d\n", remove1(&a));
	insert(&a, 12);
	insert(&a, 4);
	printf("%d\n", remove1(&a));
	printf("%d\n", remove1(&a));
	
	return 0;
}
