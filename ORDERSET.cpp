#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<cstdio>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<iterator>
#include<string>
#include<sstream>
#include<cassert>
using namespace std;
#define RED		1
#define BLACK	2

/** ||||||||||||||||||||||||||||||||||||||||||||||| **/
/** *********** BEGIN FAST I/O ******************** **/
/** ||||||||||||||||||||||||||||||||||||||||||||||| **/
#define BUFSIZE 6000000
char inbuf[BUFSIZE],outbuf[BUFSIZE],c,*in,*out;
int nbuf[10],nbs,bi;
int neg,num;
 
void io_init(){
	//printf("2\n");
    fread(inbuf,1,BUFSIZE,stdin);
    in = inbuf;
    out = outbuf;
    //printf("3\n");
}
 
int ni(){
    c = *in++;neg = num = 0;
    while(!(c >= '0' && c <= '9' || c == '-') ) c = *in++;
    if(c == '-') neg = 1, c = *in++;
    while(c >= '0' && c <= '9'){
        num = (num << 3) + (num << 1) + c - '0';
        c = *in++;
    }
    --in;
    return neg ? -num : num;
}
 
char nc(){
    c = *in++;
    while(!(c == 'I' || c == 'D' || c == 'K' || c == 'C')) c = *in++;
    --in;
    return c;
}
 
void oi(int num){
    if(num < 0) *out++ = '-' , num = -num;
    nbs = bi = 0;
    if(num == 0) nbuf[nbs++] = 0;
    while(num) nbuf[nbs++] = num%10 , num /= 10;
    bi = nbs - 1;
    while(bi >= 0) *out++ = nbuf[bi--] + '0';
    *out++ = '\n';
}
 
void os(char *s){
    while(*s) *out++ = *s++;
    *out++ = '\n';
}
 
void io_end(){
    *out = '\0';
    assert(out  - outbuf <= BUFSIZE && out - outbuf >= 0);
    fwrite(outbuf,1,out - outbuf,stdout);
}
/** ||||||||||||||||||||||||||||||||||||||||||||||| **/
/** *********** END FAST I/O ********************** **/
/** ||||||||||||||||||||||||||||||||||||||||||||||| **/
struct node {
	int key;
	struct node *left, *right, *p;
	int color;
	int size;
};

typedef struct node *NODEPTR;
struct node NIL;
NODEPTR NILPTR = &NIL;

void inorder(NODEPTR x) {
	if (x != NILPTR) {
		inorder(x->left);
		printf("(%d,%d) ", x->key, x->size);
		inorder(x->right);
	}
	//putchar('\n');
}

void preorder(NODEPTR x) {
	if (x != NILPTR) {
		printf("%d ", x->key);
		preorder(x->left);
		preorder(x->right);
	}
	//putchar('\n');
}

NODEPTR search(NODEPTR root, int k) {
	if (root == NILPTR || root->key == k)
		return root;
	if (k < root->key)
		return search(root->left, k);
	else
		return search(root->right, k);
}

NODEPTR minimum(NODEPTR root) {
	while (root->left != NILPTR)
		root = root->left;
	return root;
}

NODEPTR maximum(NODEPTR root) {
	while (root->right != NILPTR)
		root = root->right;
	return root;
}

NODEPTR successor(NODEPTR root, int x) {
	NODEPTR temp = search(root, x);
	if (temp == NILPTR) {
		printf("%d not in tree\n", x);
		return temp;
	}
	if (temp->right != NILPTR)
		return minimum(temp->right);
	NODEPTR y = temp->p;
	while (y != NILPTR && temp == y->right) {
		temp = y;
		y = y->p;
	}
	return y;
}

NODEPTR predecessor(NODEPTR root, int x) {
	NODEPTR temp = search(root, x);
	if (temp == NILPTR) {
		printf("%d not in tree\n", x);
		return temp;
	}
	if (temp->left != NILPTR)
		return maximum(temp->left);
	NODEPTR y = temp->p;
	while (y != NILPTR && temp == y->left) {
		temp = y;
		y = y->p;
	}
	return y;
}
void leftrotate(NODEPTR *treeroot, NODEPTR x) {
	NODEPTR y = x->right;
	x->right = y->left;
	if (y->left != NILPTR)
		y->left->p = x;
	y->p = x->p;
	if (x->p == NILPTR)
		*treeroot = y;
	else if (x->p->left == x)
		x->p->left = y;
	else
		x->p->right = y;
	y->left = x;
	x->p = y;
	y->size = x->size;
	x->size = x->left->size + x->right->size +1;
}

void rightrotate(NODEPTR *treeroot, NODEPTR y) {
	NODEPTR x = y->left;
	y->left = x->right;
	if (x->right != NILPTR)
		x->right->p = y;
	x->p = y->p;
	if (y->p == NILPTR)
		*treeroot = x;
	else if (y->p->left == y)
		y->p->left = x;
	else
		y->p->right = x;
	x->right = y;
	y->p = x;
	x->size = y->size;
	y->size = y->left->size + y->right->size + 1;
}

void rbinsertfixup(NODEPTR *treeroot, NODEPTR z) {
	while (z->p->color == RED) {
		if (z->p == z->p->p->left) {
			NODEPTR y = z->p->p->right;
			if (y->color == RED) {
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else {
				if (z == z->p->right) {
					z = z->p;
					leftrotate(treeroot,z);
				}
				z->p->color = BLACK;
				z->p->p->color = RED;
				rightrotate(treeroot,z->p->p);
			}
		}
		else {
			NODEPTR y = z->p->p->left;
			if (y->color == RED) {
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else {
				if (z == z->p->left) {
					z = z->p;
					rightrotate(treeroot,z);
				}
				z->p->color = BLACK;
				z->p->p->color = RED;
				leftrotate(treeroot,z->p->p);
			}
		}
	}
	(*treeroot)->color = BLACK;
}

void rbinsert(NODEPTR *treeroot, int z) {
	NODEPTR Z = (NODEPTR) malloc(sizeof(struct node));
	Z->key = z;
	NODEPTR y = NILPTR;
	NODEPTR x = *treeroot;
	while (x != NILPTR) {
		y = x;
		y->size++;
		if (Z->key < x->key)
			x = x->left;
		else if (Z->key > x->key)
			x = x->right;
		else {
			NODEPTR temp = x;
			while (x != *treeroot) {
				x->size--;
				x = x->p;
			}
			x->size--;
			free(Z);
			return;
		}
	}
	Z->p = y;
	if (y == NILPTR)
		*treeroot = Z;
	else if (Z->key < y->key)
		y->left = Z;
	else
		y->right = Z;
	Z->left = NILPTR;
	Z->right = NILPTR;
	Z->color = RED;
	Z->size = 1;
	rbinsertfixup(treeroot,Z);
}

void rbtransplant(NODEPTR *treeroot, NODEPTR u, NODEPTR v) {
	if (u->p == NILPTR)
		*treeroot = v;
	else if (u == u->p->left)
		u->p->left = v;
	else
		u->p->right = v;
	v->p = u->p;
}

void rbdeletefixup(NODEPTR *treeroot, NODEPTR x) {
	while (x != *treeroot && x->color == BLACK) {
		if (x == x->p->left) {
			NODEPTR w = x->p->right;
			if (w->color == RED) {
				w->color = BLACK;
				x->p->color = RED;
				leftrotate(treeroot,x->p);
				w = x->p->right;
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->p;
			}
			else {
			 	if (w->right->color == BLACK) {
					w->left->color = BLACK;
					w->color = RED;
					rightrotate(treeroot,w);
					w = x->p->right;
				}
				w->color = x->p->color;
				x->p->color = BLACK;
				w->right->color = BLACK;
				leftrotate(treeroot,x->p);
				x = *treeroot;
			}
		}
		else {
			NODEPTR w = x->p->left;
			if (w->color == RED) {
				w->color = BLACK;
				x->p->color = RED;
				rightrotate(treeroot,x->p);
				w = x->p->left;
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->p;
			}
			else {
				if (w->left->color == BLACK) {
					w->right->color = BLACK;
					w->color = RED;
					leftrotate(treeroot,w);
					w = x->p->left;
				}
				w->color = x->p->color;
				x->p->color = BLACK;
				w->left->color = BLACK;
				rightrotate(treeroot,x->p);
				x = *treeroot;
			}
		}
	}
	x->color = BLACK;
}

void rbdelete(NODEPTR *treeroot, int z) {
	NODEPTR Z = search(*treeroot, z);

	if (Z == NILPTR) {
		return;
	}
	if (Z != *treeroot) {
		NODEPTR tmp = Z->p;
		while (tmp != *treeroot) {
			tmp->size--;
			tmp = tmp->p;
		}
		(*treeroot)->size--;
	}
	NODEPTR y = Z;
	int yoc = y->color;
	NODEPTR x;
	if (Z->left == NILPTR) {
		x = Z->right;
		rbtransplant(treeroot,Z,Z->right);
	}
	else if (Z->right == NILPTR) {
		x = Z->left;
		rbtransplant(treeroot,Z,Z->left);
	}
	else {
		y = minimum(Z->right);
		yoc = y->color;
		x = y->right;
		if (y->p == Z) {
			x->p = y;
		}
		else {
			rbtransplant(treeroot,y,y->right);
			y->right = Z->right;
			y->right->p = y;
			NODEPTR tmp = x->p;
			while (tmp != y) {
				tmp->size--;
				tmp = tmp->p;
			}
			y->size = y->left->size + 1;
		}
		rbtransplant(treeroot,Z,y);
		y->left = Z->left;
		y->left->p = y;
		y->color = Z->color;
		y->size = y->left->size + y->right->size + 1;
	}
	if (yoc == BLACK)
		rbdeletefixup(treeroot,x);
}
NODEPTR kth(NODEPTR treeroot, int K) {
	int currrank = treeroot->left->size + 1;
	NODEPTR y = treeroot;
	while (y != NILPTR && currrank != K) {
		if (K < currrank)
			y = y->left;
		else {
			K = K - currrank;
			y = y->right;
		}
		if (y == NILPTR)
			return NILPTR;
		currrank = y->left->size + 1;
	}
	return y;
}	

int cnt(NODEPTR treeroot, int x) {
	int ans = 0;
	NODEPTR y = treeroot;
	while (y != NILPTR) {
		if (y->key > x)
			y = y->left;
		else if (y->key < x) {
			ans += y->left->size + 1;
			y = y->right;
		}
		else 
			return ans + y->left->size;
	}
	return ans;
}

int main()
{
	NIL.left = NIL.right = NIL.p = NILPTR;
	NIL.color = BLACK;
	NIL.size = 0;
	NODEPTR tree = NILPTR;
	//printf("1\n");
	io_init();
	int Q;
	int x, k;
	int t_int = 0;
	NODEPTR temp;
	char c;
	Q = ni();
	//printf("%d\n", Q);
	while (Q--) {
		c = nc();
		switch (c) {
			case 'I':
				x = ni();
				rbinsert(&tree, x);
				break;
			case 'D':
				x = ni();
				rbdelete(&tree, x);
				break;
			case 'K':
				k = ni();
				temp = kth(tree, k);
				if (temp != NILPTR)
					oi(temp->key);
				else
					os("invalid");
				break;
			case 'C':
				x = ni();
				t_int = cnt(tree, x);
				oi(x);
				break;
			default:
				break;
		}
	}
	io_end();
	return 0;
}
