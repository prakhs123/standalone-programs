#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node *newNode(int data)
{
    struct node *temp = (struct node *) malloc (sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
 
    return (temp);
}

int arr[10] = {0};
int i = 0;
void storeInorder(struct node *root)
{

if(root == NULL)
return ;
storeInorder(root->left);
arr[i++] = root->data;
storeInorder(root->right);
}

main() {
	struct node *n1 = newNode(1);
    n1->left        = newNode(2);
    n1->right       = newNode(3);
    n1->left->left  = newNode(4);
    n1->left->right = newNode(5);
    n1->right->left  = newNode(6);
    n1->left->right->left = newNode(7);
    n1->left->right->right = newNode(8);
    storeInorder(n1);
    int j;
    for (j = 0; j < i; j++)
    	printf("%d,", arr[j]);
    return 0;
}    	
