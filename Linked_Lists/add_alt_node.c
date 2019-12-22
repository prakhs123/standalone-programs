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
void display (struct node *p) {
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}
struct node *add_alt_node(struct node *l1, struct node *l2) {
	int flag = 1;
	struct node *result = NULL, *temp;
	while (l1 != NULL && l2 != NULL) {
		if (flag) {
			flag = 0;
			if (result == NULL) {
				result = l1;
				temp = result;
			}
			else {
				result->link = l1;
				result = result->link;
			}
			l1 = l1->link;
		}
		else {
			flag = 1;
			if (result == NULL) {
				result = l2;
				temp = result;
			}
			else {
				result->link = l2;
				result = result->link;
			}
			l2 = l2->link;
		}
	}
	if (l1 == NULL)
		result->link = l2;
	else if (l2 == NULL)
		result->link = l1;

	return temp;
}
main()
{
	struct node *list1 = NULL, *list2 = NULL;

	append(7, &list1);
	append(5, &list1);
	append(3, &list1);
	append(1, &list1);
	append(20, &list1);
	display(list1);
	append(6, &list2);
	append(25, &list2);
	append(32, &list2);
	append(11, &list2);
	append(9, &list2);
	display(list2);
	struct node *result;
	result = add_alt_node(list1, list2);
	display(result);
}
