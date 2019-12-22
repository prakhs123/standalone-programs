#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

void push(struct node **s, int data)
{
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	temp->data = data;
	temp->link = *s;
	*s = temp;
}

int pop(struct node **s)
{
	if (*s == NULL)
		return -1;
	int temp = (*s)->data;
	*s = (*s)->link;
	return temp;
}

int empty(struct node *s) {
	if (s == NULL)
		return 1;
	else
		return 0;
}

void insert_at_bottom(struct node **s, int data) {
	if (empty(*s)) {
		push(s, data);
		return;
	}
	int temp = pop (s);
	insert_at_bottom(s, data);
	push(s, temp);
}

void rev_stack(struct node **s) {
	if (empty(*s))
		return;
	int temp = pop(s);
	rev_stack(s);
	insert_at_bottom(s, temp);
}

main()
{
	struct node *stacktop = NULL;
	push(&stacktop, 5);
	push(&stacktop, 4);
	push(&stacktop, 3);
	push(&stacktop, 2);
	push(&stacktop, 1);
	
	rev_stack(&stacktop);
	while (!empty(stacktop)) {
		printf("%d-", pop(&stacktop));
	}
	
	return 0;
}
