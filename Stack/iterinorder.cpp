#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

struct node {
	int data;
	struct node *left, *right;
};

typedef struct node *NODEPTR;

void inorder(NODEPTR root) {
	stack<NODEPTR> mystack;
	NODEPTR p = root;
	while (p != NULL || !mystack.empty()) {
		if (p == NULL) {
			p = mystack.top();
			mystack.pop();
			printf("%d ", p->data);
			p = p->right;
		}
		else {
			mystack.push(p);
			p = p->left;
		}
	}
}

void insert(NODEPTR *treeroot, int z) {
	NODEPTR y = NULL;
	NODEPTR x = *treeroot;
	while (x != NULL) {
		y = x;
		if (z < x->data)
			x = x->left;
		else
			x = x->right;
	}
	NODEPTR temp = (NODEPTR) malloc (sizeof(struct node));
	temp->data = z;
	temp->left = NULL;
	temp->right = NULL;
	if (y == NULL)
		*treeroot = temp;
	else if (z < y->data)
		y->left = temp;
	else
		y->right = temp;
}

main() {
	int n;
	NODEPTR tree = NULL;
	while (1) {
		printf("1.Insert\n2.Inorder Walk\n3.Exit\n");
		scanf("%d", &n);
		if (n == 1) {
			printf("Enter any number:\n");
			int num;
			scanf("%d", &num);
			insert(&tree, num);
		}
		else if (n == 2) {
			inorder(tree);
			printf("\n");
		}
		else 
			break;
	}
	return 0;
}
