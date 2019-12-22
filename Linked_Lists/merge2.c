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
struct node *merge2(struct node *p, struct node *q) {
	struct node *s, *start;
	int flag = 1;
	while (p != NULL) {
		if (flag) {
			flag = 0;
			s = (struct node *) malloc (sizeof (struct node));
			start = s;
			s->data = p->data;
			s->link = NULL;
			p = p->link;
		}
		else {
			s->link = (struct node *) malloc (sizeof (struct node));
			s = s->link;
			s->data = p->data;
			s->link = NULL;
			p = p->link;
		}
	}
	while (q != NULL) {
		s->link = (struct node *) malloc (sizeof (struct node));
		s = s->link;
		s->data = q->data;
		s->link = NULL;
		q = q->link;
	}
	return start;
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
	append(23, &list1);
	append(89, &list1);
	append(56, &list1);
	append(23, &list1);
	append(44, &list1);
	display(list1);
	append(42, &list2);
	append(77, &list2);
	append(63, &list2);
	append(41, &list2);
	append(88, &list2);
	display(list2);
	list3 = merge2(list1, list2);
	display(list3);
	return 0;
}
