#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *link;
};

void print_middle(struct node *s)
{
	int N = 0;
	struct node *current = s;
	while (current != NULL) {
		N++;
		current = current->link;
	}
	
	current = s;
	int i = 0;
	while (current != NULL) {
		if (i == N/2)
			printf("%d", current->data);
		i++;
		current = current->link;
	}
}
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->link = (*head_ref);   
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
 
     push(&head, 20);
     push(&head, 4);
     push(&head, 15);
     push(&head, 77);
 
     print_middle(head);
     getchar();
}
