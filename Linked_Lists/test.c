#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *link;
};
void append (int data, struct node **s) {
	struct node *p, *q;
	if (*s == NULL) {
		p = (struct node *) malloc (sizeof (struct node));
		p->data = data;
		p->link = NULL;
		*s = p;
		return;
	}
	p = *s;
	while (p->link != NULL)
		p = p->link;

	q = (struct node *) malloc (sizeof (struct node));
	q->data = data;
	q->link = NULL;
	p->link = q;
	return;
}
void display (struct node *p) {
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}
void change(struct node *s) {
	*s->link = *s->link->link;
	return;
}
main()
{
	struct node *list = NULL;
	append(14, &list);
	append(12, &list);
	append(52, &list);
	append(32, &list);

	display(list);
	change(list);
	display(list);

	return 0;
}
