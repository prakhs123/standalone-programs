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

void split(NODEPTR ref, NODEPTR *front, NODEPTR *back) {
	if (ref == NULL || ref->next == NULL) {
		*front = ref;
		*back = NULL;
		return;
	}
	NODEPTR fast, slow;
	slow = ref;
	fast = ref->next;
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front = ref;
	*back = slow->next;
	slow->next = NULL;
}

void mergeSort(NODEPTR *list) {
	NODEPTR a, b;
	if (*list == NULL || (*list)->next == NULL)
		return;
	split(*list, &a, &b);
	mergeSort(&a);
	mergeSort(&b);
	*list = sortedMerge(a, b);
}
void printList(NODEPTR list) {
	while (list != NULL) {
		printf("%d,", list->data);
		list = list->next;
	}
	putchar('\n');
}

int main() {
	printf("Enter no. of elements in list\n");
	int n;
	scanf("%d", &n);
	printf("Enter list\n");
	int num;
	NODEPTR list;
	while (n--) {
		scanf("%d", &num);
		push(&list, num);
	}
	printList(list);
	mergeSort(&list);
	printf("Sorted List\n");
	printList(list);
	return 0;
}