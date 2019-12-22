#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
using namespace std;

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
void setleft(NODEPTR p, NODEPTR q)
{
	if (p == NULL)
		printf("void insertion\n");
	else if (p->left != NULL)
		printf("invalid inserstion\n");
	else {
		p->left = q;
		q->father = p;
	}
}

void setright(NODEPTR p, NODEPTR q)
{
	if (p == NULL)
		printf("void insertion\n");
	else if (p->right != NULL)
		printf("invalid inserstion\n");
	else {
		p->right = q;
		q->father = p;
	}
}
bool isleft(NODEPTR p)
{
	NODEPTR q = p->father;
	if (q == NULL)
		return false;
	if (q->left == p)
		return true;
	return false;
}
class mycomp
{
	public:
	bool operator()(const NODEPTR& p, const NODEPTR& q)
	{
		return (p->info >= q-> info);
	}
};
void Huffman(int n, int frequency[])
{
	NODEPTR position[n+1];
	priority_queue<NODEPTR, vector<NODEPTR>, mycomp> mypq;
	for (int i = 0; i < n; i++) {
		NODEPTR p = maketree(NULL,frequency[i]);
		position[i] = p;
		mypq.push(p);
	}
	while (mypq.size() > 1) {
		NODEPTR p1 = mypq.top();
		mypq.pop();
		NODEPTR p2 = mypq.top();
		mypq.pop();
		NODEPTR p = maketree(NULL, p1->info + p2->info);
		setleft(p, p1);
		setright(p, p2);
		mypq.push(p);
	}
	
	string code[n+1];
	NODEPTR root = mypq.top();
	mypq.pop();
	for (int i = 0; i < n; i++) {
		NODEPTR p = position[i];
		code[i] = "";
		while (p != root) {
			if (isleft(p))
				code[i] = "0" + code[i];
			else
				code[i] = "1" + code[i];
			p = p->father;
		}
		cout << code[i] << endl;
	}
}

int main()
{
	int f[] = {15, 6, 7, 12, 25, 4, 6, 1, 15};
	Huffman(9, f);
	return 0;
}
