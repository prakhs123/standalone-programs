#include <stdio.h>
#include <stdlib.h>

struct node {
	char info;
	struct node *left;
	struct node *right;
	struct node *father;
};
typedef struct node *NODEPTR;

int isleft(NODEPTR a) {
	NODEPTR q = a->father;
	if (q->left == a)
		return 1;
	else
		return 0;
}

void intrav5(NODEPTR tree) {
	NODEPTR p, q;
	p = NULL;
	q = tree;
	do {
		while (p != NULL) {
			q = p;
			p = p->left;
		}
		if (q != NULL) {
			printf("%c\n", q->info);
			p = q->right;
		}
		while (q != NULL && p == NULL) {
			do {
				p = q;
				q = p->father;
			} while (!isleft(p) && q != NULL);
			if (q != NULL) {
				printf("%d\n", q->info);
				p = q->right;
			}
		}
	} while (q != NULL);
}

main()
{
	NODEPTR tree = (NODEPTR) malloc (sizeof(struct node));
	tree->info = 'A';
	tree->father = NULL;
	NODEPTR temp = (NODEPTR) malloc (sizeof(struct node));
	temp->info = 'B';
	temp->father = tree;
	NODEPTR temp2 = (NODEPTR) malloc (sizeof(struct node));
	temp2->info = 'D';
	temp2->father = temp;
	NODEPTR temp3 = (NODEPTR) malloc (sizeof(struct node));
	temp3->info = 'G';
	temp3->father = temp2;
	temp3->left = NULL;
	temp3->right = NULL;
	temp2->right = temp3;
	temp2->left = NULL;
	temp->left = temp2;
	temp->right = NULL;
	tree->left = temp;
	tree->right = NULL;
	intrav5(tree);
	return 0;
}
