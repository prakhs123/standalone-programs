#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN	15

struct node {
	char name[MAXLEN];
	int n;
	struct node *link;
};
typedef struct node *NODEPTR;

void insert(NODEPTR *list, char name[], int no) {
	NODEPTR temp = (NODEPTR) malloc(sizeof(struct node));
	strcpy(temp->name, name);
	temp->n = no;
	if (*list == NULL)
		*list = temp;
	else
		temp->link = (*list)->link;
	(*list)->link = temp;
	*list = temp;
}

void delafter(NODEPTR list, char n[], int *no) {
	if (list == NULL) {
		printf("list empty\n");
		return;
	}
	NODEPTR q = list->link;
	strcpy(n, q->name);
	*no = q->n;
	list->link = q->link;
	free(q);
}

josephus() {
	int n;
	char name[MAXLEN];
	int no;
	int initialcount, i;
	NODEPTR list = NULL;
	scanf("%d", &n);
	while (n--) {
		scanf("%s", name);
		scanf("%d", &no);
		insert(&list, name, no);
	}
	scanf("%d", &initialcount);
	for (i = 1; i < initialcount; i++)
		list = list->link;
	printf("The order in which the people are eliminated from the circle:\n");
	while (list != list->link) {
		delafter(list, name, &no);
		printf("%s\n", name);
		for (i = 1; i < no; i++)
			list = list->link;
	}
	printf("The person who escapes %s\n", list->name);
}

main()
{
	josephus();
	return 0;
}
