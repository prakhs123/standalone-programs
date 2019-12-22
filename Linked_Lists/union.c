#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *link;
};

typedef struct node *NODEPTR;

int notpresent(NODEPTR l, int x) {
	while (l != NULL) {
		if (l->data == x)
			return 0;
		l = l->link;
	}
	return 1;
}
void MoveNode(NODEPTR *dest, NODEPTR *src) {
	NODEPTR temp = *src;

	*src = (*src)->link;
	temp->link = *dest;
	*dest = temp;
}		
NODEPTR Union(NODEPTR a, NODEPTR b) {
	NODEPTR result = NULL;
	NODEPTR *temp = &result;
	while (a != NULL || b != NULL) {
		if (a != NULL && notpresent(result, a->data)) {
			MoveNode(temp, &a);
			temp = &((*temp)->link);
		}
		else if (a != NULL)
			a = a->link;
		if (b != NULL && notpresent(result, b->data)) {
			MoveNode(temp, &b);
			temp = &((*temp)->link);
		}
		else if (b != NULL)
			b = b->link;
	}
	return result;
}
void delete2nd(NODEPTR l) {
	NODEPTR i = l;
	if (i == NULL)
		return;
	NODEPTR j = l->link;
	while (i != NULL && j != NULL) {
		i->link = j->link;
		i = j->link;
		free(j);
		if (i == NULL)
			break;
		else
			j = i->link;
	}
}
void move(NODEPTR *l,int p, int n) {
	int count = 1;
	NODEPTR temp2 = *l;
	if (n == 0)
		return;
	while (count < p-1) {
		if (*l == NULL) {
			printf("There are less than p nodes\n");
			return;
		}
		*l = (*l)->link;
		count++;
	}
	NODEPTR temp;
	if (p == 1) {
		temp = *l;
		if (temp == NULL) {
			printf("there are less than p nodes\n");
			return;
		}
		*l = (*l)->link;
	}
	else {
		temp = (*l)->link;
		if (temp == NULL) {
			printf("there are less than p nodes\n");
			return;
		}
		(*l)->link = temp->link;
	}
	count = 0;
	while (count <= n-1) {
		if (*l == NULL) {
			printf("there are less than n nodes after pth node\n");
			return;
		}
		*l = (*l)->link;
		count++;
	}
	temp->link = (*l)->link;
	(*l)->link = temp;
	*l = temp2;
}
		
/*NODEPTR Union(NODEPTR a, NODEPTR b) {
	NODEPTR result = NULL;
	NODEPTR *temp = &result;
	*temp = a;
	if (a == NULL) {
		*temp = b;
		return result;
	}
	while ((*temp)->link != NULL)
		*temp = (*temp)->link;
	while (b != NULL) {
		if (notpresent(result, b->data)) {
			(*temp)->link = b;
			b = b->link;
			*temp = (*temp)->link;
		}
	}
	return result;
}*/

void append(NODEPTR *l, int x) {
	NODEPTR temp = (NODEPTR) malloc(sizeof(struct node));
	temp->data = x;
	temp->link = NULL;
	if (*l == NULL) {
		*l = temp;
		return;
	}
	NODEPTR i = *l;
	while (i->link != NULL)
		i = i->link;
	i->link = temp;
}

void display (NODEPTR temp) {
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->link;
	}
}
int main()
{
	NODEPTR l1 = NULL;
	append(&l1, 3);
	append(&l1, 7);
	append(&l1, 10);
	append(&l1, 15);
	append(&l1, 16);
	append(&l1, 9);
	append(&l1, 22);
	append(&l1, 17);
	append(&l1, 32);
	NODEPTR l2 = NULL;
	append(&l2, 16);
	append(&l2, 2);
	append(&l2, 9);
	append(&l2, 13);
	append(&l2, 37);
	append(&l2, 8);
	append(&l2, 10);
	append(&l2, 1);
	append(&l2, 28);
	//display(Union(l1, l2));
	//delete2nd(l1);
	move(&l1, 2, 2);
	display(l1);
	
	return 0;
}
	
