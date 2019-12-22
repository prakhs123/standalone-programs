#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *left, *right, *p;
};

typedef struct node *NODEPTR;

void inorder(NODEPTR x) {
	if (x != NULL) {
		inorder(x->left);
		printf("%d ", x->key);
		inorder(x->right);
	}
}

NODEPTR search(NODEPTR root, int k) {
	if (root == NULL || root->key == k)
		return root;
	if (k < root->key)
		return search(root->left, k);
	else
		return search(root->right, k);
}

NODEPTR minimum(NODEPTR root) {
	while (root->left != NULL)
		root = root->left;
	return root;
}

NODEPTR maximum(NODEPTR root) {
	while (root->right != NULL)
		root = root->right;
	return root;
}

NODEPTR successor(NODEPTR root, int x) {
	NODEPTR temp = search(root, x);
	if (temp == NULL) {
		printf("%d not in tree\n", x);
		return temp;
	}
	if (temp->right != NULL)
		return minimum(temp->right);
	NODEPTR y = temp->p;
	while (y != NULL && temp == y->right) {
		temp = y;
		y = y->p;
	}
	return y;
}

NODEPTR predecessor(NODEPTR root, int x) {
	NODEPTR temp = search(root, x);
	if (temp == NULL) {
		printf("%d not in tree\n", x);
		return temp;
	}
	if (temp->left != NULL)
		return maximum(temp->left);
	NODEPTR y = temp->p;
	while (y != NULL && temp == y->left) {
		temp = y;
		y = y->p;
	}
	return y;
}

void insert(NODEPTR *treeroot, int z) {
	NODEPTR y = NULL;
	NODEPTR x = *treeroot;
	while (x != NULL) {
		y = x;
		if (z < x->key)
			x = x->left;
		else
			x = x->right;
	}
	NODEPTR temp = (NODEPTR) malloc (sizeof(struct node));
	temp->key = z;
	temp->left = NULL;
	temp->right = NULL;
	temp->p = y;
	if (y == NULL)
		*treeroot = temp;
	else if (z < y->key)
		y->left = temp;
	else
		y->right = temp;
}

void transplant(NODEPTR *treeroot, NODEPTR u, NODEPTR v) {
	if (u->p == NULL)
		*treeroot = v;
	else if (u == u->p->left)
		u->p->left = v;
	else
		u->p->right = v;
	if (v != NULL)
		v->p = u->p;
}

void delete(NODEPTR *treeroot, int z) {
	NODEPTR temp = search(*treeroot, z);
	if (temp == NULL) {
		printf("Node to be deleted not found\n");
		return;
	}
	if (temp->left == NULL)
		transplant(treeroot,temp,temp->right);
	else if (temp->right == NULL)
		transplant(treeroot,temp,temp->left);
	else {
		NODEPTR y = minimum(temp->right);
		if (y->p != temp) {
			transplant(treeroot,y,y->right);
			y->right = temp->right;
			y->right->p = y;
		}
		transplant(treeroot,temp,y);
		y->left = temp->left;
		y->left->p = y;
	}
}

main() {
	int n;
	NODEPTR tree = NULL;
	while (1) {
		printf("1.Insert\n2.Search\n3.Inorder Walk\n4.Minimum\n5.Maximum\n6.Successor\n7.Predecessor\n8.Delete\n9.Exit\n");
		scanf("%d", &n);
		if (n == 1) {
			printf("Enter any number:\n");
			int num;
			scanf("%d", &num);
			insert(&tree, num);
		}
		else if (n == 2) {
			printf("Enter the number to be search\n");
			int num;
			scanf("%d", &num);
			if (search(tree, num) == NULL)
				printf("%d not found\n", num);
			else
				printf("%d found\n", num);
		}
		else if (n == 3) {
			inorder(tree);
			printf("\n");
		}
		else if (n == 4)
			printf("%d\n", minimum(tree)->key);
		else if (n == 5)
			printf("%d\n", maximum(tree)->key);
		else if (n == 6) {
			printf("Enter the number whose successor needs to be found\n");
			int num;
			scanf("%d", &num);
			NODEPTR t = successor(tree, num);
			if (t != NULL)
				printf("%d\n", t->key);
		}
		else if (n == 7) {
			printf("Enter the number whose predecessor needs to be found\n");
			int num;
			scanf("%d", &num);
			NODEPTR t = predecessor(tree, num);
			if (t != NULL)
				printf("%d\n", t->key);
		}
		else if (n == 8) {
			printf("Enter the number to be deleted\n");
			int num;
			scanf("%d", &num);
			delete(&tree, num);
		}
		else 
			break;
	}
	return 0;
}
