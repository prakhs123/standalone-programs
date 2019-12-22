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
int equals (struct node *p, struct node *q) {
	while (p->data == q->data) {
		p = p->link;
		q = q->link;
		if (p == NULL && q == NULL)
			return 1;
		else if (p == NULL || q == NULL)
			return 0;
	}
	return 0;
}

main()
{
	struct node *list1 = NULL, *list2 = NULL;
	append (45, &list1);
	append (55, &list1);
	append (65, &list1);
	append (75, &list1);
	append (85, &list1);

	append (45, &list2);
	append (55, &list2);
	append (65, &list2);
	append (75, &list2);

	printf("%d\n", equals(list1, list2));
}
