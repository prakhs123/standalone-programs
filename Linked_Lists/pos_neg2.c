#include <stdio.h>
#include <assert.h>
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
void MoveNode(struct node** destRef, struct node** sourceRef)
{
  /* the front source node  */
  struct node* newNode = *sourceRef;
  assert(newNode != NULL);
 
  /* Advance the source pointer */
  *sourceRef = newNode->link;
 
  /* Link the old dest off the new node */
  newNode->link = *destRef;
 
  /* Move dest to point to the new node */
  *destRef = newNode;
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
	while (mainlist != NULL) {
		if (mainlist->data >= 0)
			MoveNode(&listpos, &mainlist);
		else
			MoveNode(&listneg, &mainlist);
	}
	display(listpos);
	display(listneg);
}
