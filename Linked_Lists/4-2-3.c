#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
	int data;
	struct node *link;
};

typedef struct node *NODEPTR;

NODEPTR getnode() {
	NODEPTR temp = (NODEPTR) malloc (sizeof(struct node));
	if (temp != NULL)
		return temp;
	else {
		printf("Overflow\n");
		exit(1);
	}
}
void append(NODEPTR *s, int x) {
	if (*s == NULL) {
		NODEPTR temp = getnode();
		temp->data = x;
		temp->link = NULL;
		*s = temp;
		return;
	}
	NODEPTR p = *s;
	NODEPTR q = (*s)->link;
	while (q != NULL) {
		p = q;
		q = q->link;
	}
	NODEPTR temp = getnode();
	temp->data = x;
	temp->link = NULL;
	p->link = temp;
	return;
}
NODEPTR concat(NODEPTR a, NODEPTR b) {
	NODEPTR result;
	if (a == NULL) {
		result = b;
		return result;
	}
	result = a;
	NODEPTR temp = result;
	while (temp->link != NULL)
		temp = temp->link;
	temp->link = b;
	return result;
}
void freeallnodes(NODEPTR *a) {
	NODEPTR temp = *a, temp2 = *a;
	while (temp != NULL) {
		temp2 = temp;
		temp = temp->link;
		free(temp2);
	}
	*a = NULL;
}
void reverse(NODEPTR *a) {
	if (a == NULL)
		return;
	NODEPTR p, q, r;
	p = NULL;
	q = *a;
	r = (*a)->link;
	while (1) {
		q->link = p;
		p = q;
		q = r;
		if (q == NULL)
			break;
		r = r->link;
	}
	*a = p;
}
void deletelast(NODEPTR *a) {
	if (a == NULL)
		return;
	NODEPTR p = *a;
	NODEPTR temp = *a;
	while (temp->link != NULL) {
		p = temp;
		temp = temp->link;
	}
	// if there is only one node, the starting node will now point to null
	if (p->link == NULL) {
		free(temp);
		*a = NULL;
	}
	else {
		p->link = NULL;
		free(temp);
	}
}
void deleteNth(NODEPTR *a, int N) {
	// if node to be deleted is 1st node
	NODEPTR p = *a;
	if (N == 1) {
		*a = (*a)->link;
		free(p);
	}
	else {
		NODEPTR q = (*a)->link;
		if (q == NULL) {
			printf("N is greater than no. of nodes present in the list\n");
			return;
		}
		int i = 2;
		while (i < N) {
			p = q;
			q = q->link;
			if (q == NULL) {
				printf("N is greater than no. of nodes present in the list\n");
				return;
			}
			i++;
		}
		p->link = q->link;
		free(q);
	}
}
void MoveNode(NODEPTR *dest, NODEPTR *src) {
	NODEPTR temp = *src;
	assert (temp != NULL);
	*src = (*src)->link;
	temp->link = *dest;
	*dest = temp;
}
NODEPTR combine(NODEPTR a, NODEPTR b) {
	NODEPTR result = NULL;
	NODEPTR *temp = &result;
	while (a != NULL || b != NULL) {
		if (a != NULL && b != NULL) {
			if (a->data <= b->data)
				MoveNode(temp, &a);
			else
				MoveNode(temp, &b);
		}
		else if (a != NULL) {
			*temp = a;
			a = NULL;
		}
		else if (b != NULL) {
			*temp = b;
			b = NULL;
		}
		temp = &((*temp)->link);
	}
	return result;
}
int notpresent(NODEPTR l, int x) {
	while (l != NULL) {
		if (l->data == x)
			return 0;
		l = l->link;
	}
	return 1;
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
NODEPTR Intersection(NODEPTR a, NODEPTR b) {
	NODEPTR result = NULL;
	NODEPTR *temp = &result;
	while (a != NULL) {
		if (!notpresent(b, a->data)) {
			MoveNode(temp, &a);
			temp = &((*temp)->link);
		}
		else
			a = a->link;
	}
	return result;
}
void insertafterNth(NODEPTR *a, int N, int x) {
	if (N == 0) {
		NODEPTR temp = getnode();
		temp->data = x;
		temp->link = *a;
		*a = temp;
		return;
	}
	if (*a == NULL)
		return;
	NODEPTR p = *a;
	NODEPTR q = (*a)->link;
	int i = 2;
	while (i <= N) {
		p = q;
		if (p == NULL) {
			printf("N is greater than no. of nodes present in the list\n");
			return;
		}
		q = q->link;
		i++;
	}
	NODEPTR temp = getnode();
	temp->data = x;
	temp->link = q;
	p->link = temp;
}
void delete2nd(NODEPTR a) {
	if (a == NULL)
		return;
	NODEPTR p = a;
	NODEPTR q = a->link;
	while (q != NULL) {
		free(q);
		p->link = q->link;
		p = q->link;
		if (p == NULL)
			return;
		q = q->link->link;
	}
}
void sort(NODEPTR a) {
	if (a == NULL)
		return;
	int i, j, k, temp;
	int n = 0;
	NODEPTR p, q;
	p = a;
	while (p != NULL) {
		n++;
		p = p->link;
	}
	k = n;
	for (i = 0; i < n-1; i++, k--) {
		p = a;
		q = p->link;
		for(j = 1; j < k; j++) {
			if (p->data > q->data) {
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
			p = p->link;
			q = q->link;
		}
	}
}
int sum(NODEPTR a) {
	int s = 0;
	while (a != NULL) {
		s += a->data;
		a = a->link;
	}
	return s;
}
int count(NODEPTR a) {
	int count = 0;
	while (a != NULL) {
		count++;
		a = a->link;
	}
	return count;
}
NODEPTR copy(NODEPTR a) {
	NODEPTR result = NULL, temp;
	while (a != NULL) {
		append(&result, a->data);
		a = a->link;
	}
	return result;
}
void display (NODEPTR p) {
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}
main()
{
	NODEPTR a = NULL;
	append(&a, 17);
	append(&a, 71);
	append(&a, 13);
	append(&a, 128);
	append(&a, 12);
	append(&a, 13);
	display(a);
	/*NODEPTR b = NULL;
	append(&b, 1);
	append(&b, 71);
	append(&b, 13);
	append(&b, 128);
	display(b);
	insertafterNth(&a, 3, 21);
	insertafterNth(&b, 9, 12);
	insertafterNth(&a, 4, 1);*/
	display(copy(a));
	return 0;
}		
