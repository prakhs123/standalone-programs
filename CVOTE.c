#include <stdio.h>
#include <malloc.h>
#include <string.h>

inline void scan(int *a) {
	register char c=0;
	while (c < 33)
		c = getchar_unlocked();
	*a = 0;	
	while (c > 33) {
		*a = *a * 10 + c - '0';
		c = getchar_unlocked();
	}
}

struct node1 {
	char name[14];
	int votes;
	char country[14];
	struct node1 *left;
	struct node1 *right;
};
typedef struct node1 *NODEPTR1;

NODEPTR1 maketree1(char n[], char cn[])
{
	NODEPTR1 p;
	
	p = (NODEPTR1) malloc(sizeof(struct node1));
	strcpy(p->name, n);
	p->votes = 0;
	strcpy(p->country, cn);
	p->left = NULL;
	p->right = NULL;
	return p;
}
void setleft1(NODEPTR1 p, char n[], char cn[]) {
	p->left = maketree1(n,cn);
}
void setright1(NODEPTR1 p, char n[], char cn[]) {
	p->right = maketree1(n, cn);
}

struct node2 {
	char name[14];
	int votes;
	struct node2 *left;
	struct node2 *right;
};
typedef struct node2 *NODEPTR2;

NODEPTR2 maketree2(char n[])
{
	NODEPTR2 p;
	p = (NODEPTR2) malloc(sizeof(struct node2));
	strcpy(p->name, n);
	p->votes = 0;
	p->left = NULL;
	p->right = NULL;
	return p;
}
void setleft2(NODEPTR2 p, char n[]) {
	p->left = maketree2(n);
}
void setright2(NODEPTR2 p, char n[]) {
	p->right = maketree2(n);
}
NODEPTR1 search1(NODEPTR1 tree, char n[]) {
	NODEPTR1 root = tree;
	while (root != NULL) {
		if (strcmp(root->name, n) == 0)
			return root;
		else if (strcmp(n, root->name) < 0)
			root = root->left;
		else
			root = root->right;
	}
}
NODEPTR2 search2(NODEPTR2 tree, char n[]) {
	NODEPTR2 root = tree;
	while (root != NULL) {
		if (strcmp(root->name, n) == 0)
			return root;
		else if (strcmp(n, root->name) < 0)
			root = root->left;
		else
			root = root->right;
	}
}
char CHEF[14], COUNTRY[14];
int maxchef = 0, maxcountry = 0;

void intrav1(NODEPTR1 tree) {
	if (tree != NULL) {
		intrav1(tree->left);
		if (maxchef == tree->votes) {
			if (strcmp(tree->name, CHEF) < 0) {
				strcpy(CHEF, tree->name);
			}
		}
		else if (maxchef < tree->votes) {
			strcpy(CHEF, tree->name);
			maxchef = tree->votes;
		}
		intrav1(tree->right);
	}
}
void intrav2(NODEPTR2 tree) {
	if (tree != NULL) {
		intrav2(tree->left);
		if (maxcountry == tree->votes) {
			if (strcmp(tree->name, COUNTRY) < 0) {
				strcpy(COUNTRY, tree->name);
			}
		}
		else if (maxcountry < tree->votes) {
			strcpy(COUNTRY, tree->name);
			maxcountry = tree->votes;
		}
		intrav2(tree->right);
	}
}
main()
{
	NODEPTR1 ptree1;
	NODEPTR1 p1, q1;
	NODEPTR2 ptree2;
	NODEPTR2 p2, q2;
	int N, M, i, c;
	char temp1[14], temp2[14];
	
	scan(&N);
	scan(&M);
	//create 1st node
	i = 0;
	while ((c = getchar()) != ' ')
		temp1[i++] = c;
	temp1[i] = '\0';
	i = 0;
	while ((c = getchar()) != '\n')
		temp2[i++] = c;
	temp2[i] = '\0';
	ptree1 = maketree1(temp1, temp2);
	ptree2 = maketree2(temp2);
	//---
	N -= 1;
	while (N--) {
		i = 0;
		while ((c = getchar()) != ' ')
			temp1[i++] = c;
		temp1[i] = '\0';
		i = 0;
		while ((c = getchar()) != '\n')
			temp2[i++] = c;
		temp2[i] = '\0';
		// type1 node
		p1 = q1 = ptree1;
		while (strcmp(temp1, p1->name) != 0 && q1 != NULL) {
			p1 = q1;
			if (strcmp(temp1, p1->name) < 0)
				q1 = p1->left;
			else
				q1 = p1->right;
		}
		if (strcmp(temp1, p1->name) < 0)
			setleft1(p1,temp1,temp2);
		else
			setright1(p1,temp1,temp2);
		//---
		//type2 node
		p2 = q2 = ptree2;
		while (strcmp(temp2, p2->name) != 0 && q2 != NULL) {
			p2 = q2;
			if (strcmp(temp2, p2->name) < 0)
				q2 = p2->left;
			else
				q2 = p2->right;
		}
		if (strcmp(temp2, p2->name) < 0)
			setleft2(p2,temp2);
		else if (strcmp(temp2, p2->name) > 0)
			setright2(p2,temp2);
		//---
	}
	while (M--) {
		i = 0;
		while ((c = getchar()) != '\n' && c != EOF)
			temp1[i++] = c;
		temp1[i] = '\0';
		
		p1 = search1(ptree1, temp1);
		p1->votes++;
		p2 = search2(ptree2, p1->country);
		p2->votes++;
	}
	intrav1(ptree1);
	intrav2(ptree2);
	printf("%s\n%s\n", COUNTRY, CHEF);
	return 0;
}
