#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *left;
	struct node *right;
	struct node *father;
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

NODEPTR maketree(NODEPTR q, int x)
{
	NODEPTR p;
	
	p = getnode();
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	p->father = q;
	return p;
}
void setleft(NODEPTR p, int x)
{
	if (p == NULL)
		printf("void insertion\n");
	else if (p->left != NULL)
		printf("invalid inserstion\n");
	else
		p->left = maketree(p,x);
}

void setright(NODEPTR p, int x)
{
	if (p == NULL)
		printf("void insertion\n");
	else if (p->right != NULL)
		printf("invalid inserstion\n");
	else
		p->right = maketree(p,x);
}
NODEPTR tree(void)
{
	NODEPTR ptree;
	NODEPTR p, q;
	int number;
	
	scanf("%d", &number);
	ptree = maketree(NULL,number);
	while (scanf("%d", &number) != EOF) {
		p = q = ptree;
		while (q != NULL) {
			p = q;
			if (number < p->info)
				q = p->left;
			else
				q = p->right;
		}
		if (number < p->info)
			setleft(p, number);
		else
			setright(p, number);
	}
	
	return ptree;
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
	NODEPTR t = tree();
	intrav(t);
	return 0;
}
