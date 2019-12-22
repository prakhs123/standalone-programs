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
	string sym;
};
typedef struct node *NODEPTR;

NODEPTR getnode(void) {
	NODEPTR temp = new node();
	if (temp == NULL) {
		printf("Overflow\n");
		exit(1);
	}
	else
		return temp;
}

NODEPTR maketree(NODEPTR q, int x, string s)
{
	NODEPTR p;
	
	p = getnode();
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	p->father = q;
	p->sym = s;
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
void encode (char symb[], string code[], int n, string msge, string& bitcode)
{
	int l = msge.size(), i ,j;
	bitcode = "";
	for (i = 0; i < l; i++) {
		for (j = 0; j < n; j++) {
			if (symb[j] == msge[i])
				break;
		}
		bitcode.append(code[j]);
	}
}

void decode (NODEPTR root, string bitcode, string& msge)
{
	for (int i = 0; i < bitcode.size();) {
		NODEPTR p = root;
		while (p->left != NULL || p->right != NULL) {
			if (bitcode[i] == '1')
				p = p->right;
			else
				p = p->left;
			i++;
		}
		msge.append(p->sym);
	}
}
class mycomp
{
	public:
	bool operator()(const NODEPTR& p, const NODEPTR& q)
	{
		if (p->info == q->info)
			return (p->sym > q->sym);
		else
			return (p->info > q-> info);
	}
};
void Huffman(int n, int frequency[], char symb[])
{
	NODEPTR position[n+1];
	priority_queue<NODEPTR, vector<NODEPTR>, mycomp> mypq;
	for (int i = 0; i < n; i++) {
		string t;
		t.push_back(symb[i]);
		NODEPTR p = maketree(NULL,frequency[i],t);
		position[i] = p;
		mypq.push(p);
	}
	while (mypq.size() > 1) {
		NODEPTR p1 = mypq.top();
		mypq.pop();
		NODEPTR p2 = mypq.top();
		mypq.pop();
		string t;
		t.append(p1->sym);
		t.append(p2->sym);
		NODEPTR p = maketree(NULL, p1->info + p2->info, t);
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
		cout << position[i]->sym << ": " << code[i] << endl;
	}
	string bitcode;
	encode(symb,code,n,"AHEAD",bitcode);
	cout << bitcode << endl;
	bitcode = "1110100010111011";
	string msg;
	decode(root,bitcode,msg);
	cout << msg << endl;
}

int main()
{
	int f[] = {15, 6, 7, 12, 25, 4, 6, 1, 15};
	char s[] = {'A','B','C','D','E','F','G','H','I'};
	Huffman(9, f, s);
	return 0;
}
