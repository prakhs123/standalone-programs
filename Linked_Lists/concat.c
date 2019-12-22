#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *link;
};
struct node *concat (struct node *a, struct node *b) {
	struct node *result;
	if (a == NULL)
		result = b;
	else {
		result = a;
		result->link = concat (a->link, b);
	}
	return result;
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
	struct node *list1 = NULL, *list2 = NULL, *list3;
	append (37, &list1);
	append (44, &list1);
	append (53, &list1);
	display (list1);

	append (56, &list2);
	append (74, &list2);
	append (85, &list2);
	display (list2);

	list3 = concat (list1, list2);
	display (list3);
	display (list1);
	display (list2);
}
