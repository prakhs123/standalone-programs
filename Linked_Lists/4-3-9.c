#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	char info;
	struct node *next;
};
struct charstr {
	int length;
	struct node *firstchar;
};
typedef struct node *NODEPTR;
typedef struct charstr *HEADPTR;

NODEPTR getnode() {
	NODEPTR temp = (NODEPTR) malloc (sizeof(struct node));
	if (temp != NULL)
		return temp;
	else {
		printf("Overflow\n");
		exit(1);
	}
}

HEADPTR gethead() {
	HEADPTR temp = (HEADPTR) malloc (sizeof(struct charstr));
	if (temp != NULL)
		return temp;
	else {
		printf("Overflow\n");
		exit(1);
	}
}
HEADPTR strcnvcl(char s[]) {
	int l = strlen(s);
	HEADPTR head = gethead();
	head->length = l;
	if (l == 0) {
		head->firstchar = NULL;
		return head;
	}
	else {
		int i;
		NODEPTR temp = getnode();
		temp->info = s[0];
		temp->next = NULL;
		for (i = 1; s[i] != NULL; i++) {
			NODEPTR t = getnode();
			t->info = s[i];
			
