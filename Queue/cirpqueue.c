#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE	5
struct data {
	int item;
	int prno;
};
struct PQueue {
	struct data items[MAXQUEUE];
	int front, rear;
};

void initPQueue(struct PQueue *s) {
	s->front = s->rear = MAXQUEUE-1;
	int i;
	for (i = 0; i < MAXQUEUE; i++) {
		s->items[i].item = 0;
		s->items[i].prno = 0;
	}
}

void insert(struct PQueue *s, int x, int p) {
	int temp = s->rear;
	if (s->rear == MAXQUEUE-1)
		s->rear = 0;
	else
		s->rear++;
	if (s->rear == s->front) {
		printf("Queue overflow\n");
		exit(1);
	}
	if (temp == s->front) {
		s->items[s->rear].item = x;
		s->items[s->rear].prno = p;
		return;
	}
	else if (temp > s->front) {
		int i = temp;
		if (temp == MAXQUEUE-1) {
			if (s->items[temp].prno > p) {
				s->items[0] = s->items[temp];
				i--;
			}
		}
		while (s->items[i].prno > p && i > s->front) {
			s->items[i+1] = s->items[i];
			i--;
		}
		if (i == MAXQUEUE-1) {
			s->items[0].item = x;
			s->items[0].prno = p;
			return;
		}
		else {
			s->items[i+1].item = x;
			s->items[i+1].prno = p;
			return;
		}
	}
	else {
		int i, flag = 1;
		for (i = temp; i >= 0 && flag;) {
			if (s->items[i].prno > p) {
				s->items[i+1] = s->items[i];
				i--;
			}
			else
				flag = 0;
		}
		if (flag == 0) {
			s->items[i+1].item = x;
			s->items[i+1].prno = p;
			return;
		}
		else {
			int flag2 = 1;
			for (i = MAXQUEUE-1; i > s->front && flag2;) {
				if (i == MAXQUEUE-1 && s->items[i].prno > p) {
					s->items[0] = s->items[i];
					i--;
				}
				else if (s->items[i].prno > p) {
					s->items[i+1] = s->items[i];
					i--;
				}
				else 
					flag2 = 0;
			}
			if (flag2 == 0) {
				if (i == MAXQUEUE-1) {
					s->items[0].item = x;
					s->items[0].prno = p;
					return;
				}
				else {
					s->items[i+1].item = x;
					s->items[i+1].prno = p;
					return;
				}
			}
			else {
				s->items[i+1].item = x;
				s->items[i+1].prno = p;
				return;
			}
		}
	}
}

int remove1(struct PQueue *s) {
	if (s->front == s->rear) {
		printf("Queue underflow\n");
		exit(1);
	}
	if (s->front == MAXQUEUE-1)
		s->front = 0;
	else
		s->front++;
	
	return s->items[s->front].item;
}

main()
{
	struct PQueue a;
	initPQueue(&a);
	insert(&a, 1, 3);
	insert(&a, 17, 1);
	insert(&a, 3, 5);
	printf("%d\n", remove1(&a));
	printf("%d\n", remove1(&a));
	insert(&a, 12, 2);
	insert(&a, 4, 1);
	printf("%d\n", remove1(&a));
	printf("%d\n", remove1(&a));
	
	return 0;
}
