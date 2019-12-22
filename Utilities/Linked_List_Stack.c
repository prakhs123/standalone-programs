#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *link;
};

void push(struct node **s, int data)
{
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	temp->data = data;
	temp->link = *s;
	*s = temp;
}

int pop(struct node **s)
{
	if (*s == NULL)
		return -1;
	int temp = (*s)->data;
	*s = (*s)->link;
	return temp;
}
main()
{
    /* Start with the empty list */
    struct node* head = NULL;
   
    /* Use push() to construct below list
     1->12->1->4->1  */
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);
    
    int c;
    while ((c = pop(&head)) != -1)
    	printf("%d ", c);
    printf("\n");
    
    return 0;
  }
