#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE	100
struct queue {
	int items[MAXQUEUE];
	int front, rear;
};

void initqueue(struct queue *s) {
	s->front = 0;
	s->rear = -1;
}

void insert(struct queue *s, int x) {
	if (s->rear == MAXQUEUE - 1) {
		printf("Queue overflow\n");
		exit(1);
	}
	else
		s->items[++s->rear] = x;
}

int remove1(struct queue *s) {
	if (s->rear < s->front) {
		printf("Queue underflow\n");
		exit(1);
	}
	else
		return s->items[s->front++];
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
