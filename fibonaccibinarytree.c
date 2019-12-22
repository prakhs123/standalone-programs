#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *left;
	struct node *right;
};
typedef struct node *NODEPTR;

NODEPTR getnode(void) {
	NODEPTR temp = (NODEPTR) malloc(sizeof(struct node));
	if (temp == NULL) {
		printf("Overflow\n");
		exit(1);
	}
	else
		return temp;
}

NODEPTR maketree(int x)
{
	NODEPTR p;
	
	p = getnode();
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void setleft(NODEPTR p, int x)
{
	if (p == NULL)
		printf("void insertion\n");
	else if (p->left != NULL)
		printf("invalid inserstion\n");
	else
		p->left = maketree(x);
}

void setright(NODEPTR p, int x)
{
	if (p == NULL)
		printf("void insertion\n");
	else if (p->right != NULL)
		printf("invalid inserstion\n");
	else
		p->right = maketree(x);
}
NODEPTR tree(int n) {
	if (n <= 1)
		return maketree(n);
	else {
		NODEPTR root = maketree(n);
		root->left = tree(n-1);
		root->right = tree(n-2);
		return root;
	}
}

void intrav(NODEPTR tree)
{
	if (tree != NULL) {
		intrav(tree->left);
		printf("%d\n", tree->info);
		intrav(tree->right);
	}
}

int main()
{
	intrav(tree(4));
	return 0;
}
