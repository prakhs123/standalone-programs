#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *link;
};

struct node *delete_alternate_nodes(struct node *s) {
	if (s == NULL) 
		return NULL;
	struct node *curr = s->link;
	struct node *prev = s;
	while (curr != NULL && prev != NULL) {
		prev->link = curr->link;
		free(curr);
		prev = prev->link;
		if (prev != NULL)
			curr = prev->link;
	
	}
	return s;
}

void append (int data, struct node **s) {
	struct node *p, *q;
	if (*s == NULL) {
		p = (struct node *) malloc (sizeof (struct node));
		p->data = data;
		p->link = NULL;
		*s = p;
		return;
	}
	q = *s;
	p = (*s)->link;
	while (p != NULL) {
		q = p;
		p = p->link;
	}

	q->link = (struct node *) malloc (sizeof (struct node));
	q->link->data = data;
	q->link->link = NULL;
	return;
}
void display (struct node *p) {
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}
main()
{
	struct node *list1 = NULL;
	append(1, &list1);
	append(2, &list1);
	append(3, &list1);
	append(4, &list1);
	append(5, &list1);
	append(6, &list1);
	append(7, &list1);

	display(list1);

	list1 = delete_alternate_nodes(list1);
	display(list1);
}
		
