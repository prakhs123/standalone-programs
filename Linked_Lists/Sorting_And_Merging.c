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

void insertion_sort (struct node *s) {
	int i, j;
	struct node *temp = s, *r;
	for (i = 0; temp != NULL; i++, temp = temp->link)
		;
	int n = i;
	for (i = 0; i < n; i++) {
		r = s->link;
		for (j = i + 1; j < n ; j++)  {
			if (s->data > r->data) {
				int temp = s->data;
				s->data = r->data;
				r->data = temp;
			}
			r = r->link;
		}
		s = s->link;
	}
}

void bubble_sort (struct node *s) {
	struct node *temp = s, *r;
	int i, j;
	for (i = 0; temp != NULL; i++, temp = temp->link)
		;
	int n = i;
	temp = s;
	for (i = 0; i < n - 1; i++) {
		s = temp;
		r = s->link;
		for (j = 1; j < n - i; j++) {
			if (s->data > r->data) {
				int temp = s->data;
				s->data = r->data;
				r->data = temp;
			}
			r = r->link;
			s = s->link;
		}
	}
}
struct node *merge (struct node *p, struct node *q) {
	struct node *s, *temp;
	int flag = 1;
	while (p != NULL && q != NULL) {
		if (flag) {
			flag = 0;
			s = (struct node *) malloc (sizeof (struct node));
			temp = s;
			if (p->data < q->data) {
				s->data = p->data;
				p = p->link;
			}
			else {
				s->data = q->data;
				q = q->link;
			}
			s->link = NULL;
		}
		else {
			s->link = (struct node *) malloc (sizeof (struct node));
			s = s->link;
			if (p->data < q->data) {
				s->data = p->data;
				p = p->link;
			}
			else {
				s->data = q->data;
				q = q->link;
			}
			s->link = NULL;
		}
	}
	if (p == NULL) {
		while (q != NULL) {
			s->link = (struct node *) malloc (sizeof (struct node));
			s = s->link;
			s->data = q->data;
			s->link = NULL;
			q = q->link;
		}
	}
	else {
		while (p != NULL) {
			s->link = (struct node *) malloc (sizeof (struct node));
			s = s->link;
			s->data = p->data;
			s->link = NULL;
			p = p->link;
		}
	}
	return temp;
}
				
void display (struct node *p) {
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}
main() {
	struct node *list1 = NULL, *list2 = NULL;
	append (5, &list1);
	append (9, &list1);
	append (2, &list1);
	append (10, &list1);
	append (4, &list1);

	display(list1);
	insertion_sort(list1);
	display(list1);

	append (44, &list2);
	append (12, &list2);
	append (57, &list2);
	append (76, &list2);
	append (89, &list2);

	display(list2);
	bubble_sort(list2);
	display(list2);

	struct node *list3;
	list3 = merge(list1, list2);
	display(list3);
}
