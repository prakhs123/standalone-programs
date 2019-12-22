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



/** ||||||||||||||||||||||||||||||||||||||||||||||| **/
/** *********** BEGIN FAST I/O ******************** **/
/** ||||||||||||||||||||||||||||||||||||||||||||||| **/
#define BUFSIZE 6000000
char inbuf[BUFSIZE],outbuf[BUFSIZE],c,*in,*out;
int nbuf[10],nbs,bi;
int neg,num;

void io_init(){
    fread(inbuf,1,BUFSIZE,stdin);
    in = inbuf;
    out = outbuf;
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


/** ORDER STATISTIC AVL TREE **/


struct node{
    int c;
    int height;
    int key;
    struct node *left;
    struct node *right;
};

struct node *NodeAlloc(int key){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->c = 1;
    ptr->left = ptr->right = NULL;
    ptr->height = 1;
    ptr->key = key;
    return ptr;
}

struct node *MinValue(struct node *node){
    struct node *curr = node;
    assert(curr != NULL);
    while(curr->left != NULL) curr = curr->left;
    return curr;
}

int getCount(struct node *node){
    if(node == NULL) return 0;
    return node->c;
}

int getHeight(struct node *node){
    if(node == NULL)  return 0;
    return node->height;
}

int getBalance(struct node *node){
    if(node == NULL ) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

struct node *Left_Rotate(struct node *node){
    struct node *y = node->right , *T2 = y->left;
    y->left = node;
    node->right = T2;
    ///Update Parameters !
    node->height = max(getHeight(node->left),getHeight(node->right)) + 1;
    node->c = getCount(node->left) + getCount(node->right) + 1;
    y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
    y->c = getCount(y->left) + getCount(y->right) + 1;
    return y;
}

struct node *Right_Rotate(struct node *node){
    struct node *y = node->left , *T2 = y->right;
    y->right = node;
    node->left = T2;
    ///Update Parameters !
    node->height = max(getHeight(node->left),getHeight(node->right)) + 1;
    node->c = getCount(node->left) + getCount(node->right) + 1;
    y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
    y->c = getCount(y->left) + getCount(y->right) + 1;
    return y;
}

struct node *insert(struct node *node , int key){
    if(node == NULL) return NodeAlloc(key) ;
    if(key < node->key) node->left = insert(node->left,key) ;
    if(key > node->key) node->right = insert(node->right,key);
    node->height = max(getHeight(node->left) ,getHeight(node->right)) + 1;
    node->c = getCount(node->left) + getCount(node->right) + 1;
    int balance = getBalance(node);
    if(balance > 1 && node->left->key > key) return Right_Rotate(node);
    else if(balance < -1 && node->right->key < key) return Left_Rotate(node);
    else if(balance > 1 && node->left->key < key){
        node->left = Left_Rotate(node->left);
        return Right_Rotate(node);
    }
    else if(balance < -1 && node->right->key > key){
        node->right = Right_Rotate(node->right);
        return Left_Rotate(node);
    }
    return node;
}

struct node *Delete(struct node *node,int key){
    if(node == NULL ) return node;
    if(node->key < key) node->right = Delete(node->right ,key);
    else if(node->key > key) node->left = Delete(node->left,key);
    else{
        if(node->left == NULL || node->right == NULL){
            struct node *temp = (node->left != NULL) ? node->left : node->right ;
            if(temp == NULL){
                temp = node;
                node = NULL;
            }
            else *node = *temp;
            free(temp);
        }
        else{
            struct node *temp = MinValue(node->right);
            node->key = temp->key;
            node->right = Delete(node->right , temp->key);
        }
    }
    if(node == NULL ) return node;
    node->height = max(getHeight(node->left) , getHeight(node->right)) + 1;
    node->c = getCount(node->left) + getCount(node->right) + 1;
    int balance = getBalance(node);
    if(balance > 1 && getBalance(node->left) >= 0) return Right_Rotate(node);
    else if(balance < -1 && getBalance(node->right) <= 0 ) return Left_Rotate(node);
    else if(balance > 1 && getBalance(node->left) < 0){
        node->left = Left_Rotate(node->left);
        return Right_Rotate(node);
    }
    else if(balance < -1 && getBalance(node->right) > 0){
        node->right = Right_Rotate(node->right);
        return Left_Rotate(node);
    }
    return node;
}

struct node *find(struct node* node , int key){
    if(node == NULL) return node;
    if(node->key == key) return node;
    else if(node->key < key) return find(node->right,key);
    else return find(node->left,key);
}

struct node *KthElement(struct node *node , int p){
    if(node == NULL) return NULL;
    int l = getCount(node->left);
    if(l >= p) return KthElement(node->left,p);
    else if(l == p-1) return node;
    else return KthElement(node->right,p-l-1);
}

int Count(struct node *node ,int key){
    if(node == NULL ) return 0;
    int l = getCount(node->left);
    if(node->key == key) return l;
    else if(node->key < key) return l + 1 + Count(node->right,key);
    else return Count(node->left,key);
}

void PrintIn(struct node *node){
    if(node != NULL){
        PrintIn(node->left);
        fprintf(stderr,"(%d,%d) ",node->key,node->c);
        PrintIn(node->right);
    }
}

void PrintPre(struct node *node){
    if(node != NULL){
        fprintf(stderr,"(%d,%d) ",node->key,node->c);
        PrintPre(node->left);
        PrintPre(node->right);
    }
}

void PrintPost(struct node *node){
    if(node != NULL){
        PrintPost(node->left);
        PrintPost(node->right);
        fprintf(stderr,"(%d,%d) ",node->key,node->c);

    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    io_init();
    struct node *Root = NULL,*temp = NULL;
    int Q, key , t_int = 0;
    char ch ;
    Q = ni() ;
    while(Q--){
        ch = nc();
        key = ni();
        if(ch == 'I'){
            temp = find(Root,key);
            if(temp == NULL) Root = insert(Root,key);
        }
        else if(ch == 'D'){
            temp = find(Root,key);
            if(temp != NULL) Root = Delete(Root,key);
        }
        else if(ch == 'K'){
            temp = KthElement(Root,key);
            if(temp == NULL ) os("invalid");
            else oi(temp->key);
        }
        else{
            t_int = Count(Root,key);
            oi(t_int);
        }
        /**
        fprintf(stderr,"%c %d\n",ch,key);
        fprintf(stderr,"INORDER : ");
        PrintIn(Root);
        fprintf(stderr,"\nPREORDER : ");
        PrintPre(Root);
        fprintf(stderr,"\nPOSTORDER : ");
        PrintPost(Root);
        fprintf(stderr,"\n");
        **/
    }
    io_end();
    return 0;
}
