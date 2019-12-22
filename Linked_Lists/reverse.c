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
void addatbeg(struct node **s, int num) {
	struct node *temp;
	temp = (struct node *) malloc (sizeof (struct node));
	temp->data = num;
	temp->link = *s;
	*s = temp;
}
void addatloc(struct node *s, int loc, int num) {
	int i;
	struct node *prev = s;
	/* Avoiding the case of loc = 0 */
	for (i = 0; i < loc - 1; ++i) {
		prev = prev->link;
	}
	struct node *temp = (struct node *) malloc (sizeof (struct node));
	temp->data = num;
	temp->link = prev->link;
	prev->link = temp;
}
void delete (struct node **s, int data) {
	struct node *temp;
	if ((*s)->data == data) {
		temp = (*s)->link;
		free (*s);
		*s = temp;
	}
	else {
		struct node *p, *q;
		p = *s, q = (*s)->link;
		while (1) {
			if (q == NULL) {
				printf("There are no elements with value data\n");
				return;
			}
			else if (q->data == data) {
				p->link = q->link;
				free(q);
				return;
			}
			p = q;
			q = q->link;
		}
	}
}
void reverse (struct node **s) {
	struct node *list, *old, *new;
	list = *s;	
	new = NULL;
	while (list != NULL) {
		old = new;
		new = list;
		list = list->link;
		new->link = old;
	}
	*s = new;
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
	struct node *start;
	
	append (38, &start);
	append (45, &start);
	append (54, &start);
	append (76, &start);
	addatbeg (&start, 17);
	delete(&start, 54);
	addatloc(start, 1, 18);

	display(start);
	reverse(&start);
	display(start);
}
