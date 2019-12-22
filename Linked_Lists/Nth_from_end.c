#include <stdio.h>
#include <assert.h>
#include <malloc.h>

struct node {
	int data;
	struct node *link;
};

struct node *Nth_from_end(struct node *start, int N)
{
	struct node *current = start;
	struct node *current2;
	
	int i = 1;
	while (i <= N) {
		if (current == NULL) {
			printf("there are fewer nodes than N\n");
			assert(0);
		}
		current = current->link;
		i++;
	}
	
	current2 = start;
	while (current != NULL) {
		current = current->link;
		current2 = current2->link;
	}
	
	return current2;
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
void printNthFromLast(struct node* head, int n)
{
    static int i = 0;
    if(head == NULL)
       return;
    printNthFromLast(head->link, n);
    if(++i == n)
       printf("%d", head->data);
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
	struct node *list = NULL;
	push(&list, 17);
	push(&list, 27);
	push(&list, 14);
	push(&list, 25);
	push(&list, 33);
	push(&list, 57);
	push(&list, 47);
	int n = 3;
	display(list);
	printf("%d\n", Nth_from_end(list, n)->data);
	printNthFromLast(list, n);
	return 0;
}
