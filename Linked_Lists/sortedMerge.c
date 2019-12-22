#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node *NODEPTR;

void push(NODEPTR *list, int data) {
	NODEPTR temp = (NODEPTR) malloc (sizeof(struct node));
	temp->data = data;
	temp->next = *list;
	*list = temp;
}

NODEPTR sortedMerge(NODEPTR a, NODEPTR b) {
	NODEPTR result = NULL;
	NODEPTR last = NULL;
	while (1) {
		if (a == NULL) {
			if (result == NULL)
				result = b;
			else
				last->next = b;
			return result;
		}
		else if (b == NULL) {
			if (result == NULL)
				result = a;
			else
				last->next = a;
			return result;
		}
		if (a->data <= b->data) {
			if (result == NULL) {
				result = a;
				last = a;
				a = a->next;
				last->next = NULL;
			}
			else {
				last->next = a;
				last = a;
				a = a->next;
				last->next = NULL;
			}
		}
		else {
			if (result == NULL) {
				result = b;
				last = b;
				b = b->next;
				last->next = NULL;
			}
			else {
				last->next = b;
				last = b;
				b = b->next;
				last->next = NULL;
			}
		}
	}
}

void printList(NODEPTR list) {
	while (list != NULL) {
		printf("%d,", list->data);
		list = list->next;
	}
	putchar('\n');
}

int main() {
	printf("Enter no. of elements in list1 and list2\n");
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	printf("Enter list1\n");
	int num;
	NODEPTR list1, list2;
	while (n1--) {
		scanf("%d", &num);
		push(&list1, num);
	}
	printf("Enter list2\n");
	while (n2--) {
		scanf("%d", &num);
		push(&list2, num);
	}
	printList(list1);
	printList(list2);
	NODEPTR result = sortedMerge(list1, list2);
	printf("Sorted List\n");
	printList(result);
	return 0;
}