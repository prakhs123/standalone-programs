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
main()
{
	struct node *mainlist = NULL;
	append(34, &mainlist);
	append(-17, &mainlist);
	append(22, &mainlist);
	append(-43, &mainlist);
	append(-34, &mainlist);
	append(33, &mainlist);

	display(mainlist);
	
	struct node *listpos = NULL, *listneg = NULL;
	struct node *temp1, *temp2;
	while (mainlist != NULL) {
		if (mainlist->data >= 0) {
			if (listpos == NULL) {
				listpos = mainlist;
				temp1 = listpos;
			}
			else {
				listpos->link = mainlist;
				listpos = listpos->link;
			}
		}
		else {
			if (listneg == NULL) {
				listneg = mainlist;
				temp2 = listneg;
			}
			else {
				listneg->link = mainlist;
				listneg = listneg->link;
			}
		}		
		mainlist = mainlist->link;
	}
	listpos->link = NULL;
	listneg->link = NULL;
	display(temp1);
	display(temp2);
}
