#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define	MAXLEN	15
struct node {
	char name[MAXLEN];
	struct node *link;
};
typedef struct node *NODEPTR;

int empty(NODEPTR *p) {
	return *p == NULL ? 1 : 0;
}

void insert(NODEPTR *pq, char s[]) {
	NODEPTR p;
	p = (NODEPTR) malloc(sizeof(struct node));
	strcpy(p->name,s);
	if (empty(pq))
		*pq = p;
	else
		p->link = (*pq)->link;
	(*pq)->link = p;
	*pq = p;
}

void delafter(NODEPTR p, char px[])
{
	NODEPTR q;
	if (p == NULL || p == p->link) {
		printf("void deletion\n");
		return;
	}
	q = p->link;
	strcpy(px,q->name);
	p->link = q->link;
	free(q);
}

void josephus(void) {
	char *end = "end";
	char name[MAXLEN];
	int i, n;
	NODEPTR list = NULL;
	printf("enter n\n");
	scanf("%d", &n);
	printf("enter names\n");
	scanf("%s", name);
	while (strcmp(name,end) != 0) {
		insert(&list, name);
		scanf("%s", name);
	}
	printf("the order in which soldiers are eliminated is:\n");
	
	while (list != list->link) {
		for (i = 1; i < n; i++)
			list = list->link;
		delafter(list, name);
		printf("%s\n", name);
	}
	printf("the soldier who escapes is: %s\n", list->name);
	free(list);
}

main()
{
	josephus();
	return 0;
}
