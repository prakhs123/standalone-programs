#include <stdio.h>
#include <stdlib.h>

#define N	100000
struct node {
	int data;
	struct node *link;
};

typedef struct node *NODEPTR;

struct node start[N+10];	/* starting node of all linked list, contains how many nodes are there in it */
int id[N+10];	/* for ex : if id 6 is present in 1st start node, then id[6] = 1*/

void init(void) {
	int i;
	int l = N+10;
	for (i = 0; i < l; i++) {
		start[i].data = 0;
		start[i].link = NULL;
		id[i] = -1;
	}
}

void append(int startid, int num)
{
	NODEPTR temp = &start[startid];
	while (temp->link != NULL)
		temp = temp->link;
	NODEPTR node = (NODEPTR) malloc(sizeof(struct node));
	node->data = num;
	node->link = NULL;
	temp->link = node;
}

void change(int i, int j)
{
	NODEPTR temp = &start[i];
	temp = temp->link;
	while (temp != NULL) {
		id[temp->data] = j;
		temp = temp->link;
	}
}

void append2(int receiver, int giver)
{
	NODEPTR temp1 = &start[receiver];
	while (temp1->link != NULL)
		temp1 = temp1->link;
	NODEPTR temp2 = &start[giver];
	temp2 = temp2->link;
	temp1->link = temp2;
	start[giver].link = NULL;
}

main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		init();
		scanf("%d %d", &n, &m);
		int k = 0, counter = 0;
		while (m--) {
			int i, j;
			scanf("%d %d", &i, &j);
			if (id[i] == -1 && id[j] == -1) {
				start[k].data += 2;
				append(k, i);
				append(k, j);
				id[i] = id[j] = k;
				k++;
				counter++;
			}
			else if (id[i] == -1) {
				append(id[j], i);
				id[i] = id[j];
				start[id[j]].data++;
			}
			else if (id[j] == -1) {
				append(id[i], j);
				id[j] = id[i];
				start[id[i]].data++;
			}
			else {
				if (id[i] != id[j]) {
					if (start[id[i]].data < start[id[j]].data) {
						int t = id[i];
						// change all ids in id[i] list to id[j]
						change(id[i], id[j]);
						// increase count of id[j] by start[id[i]].data
						start[id[j]].data += start[t].data;
						// append id[i] list to id[j] list
						append2(id[j], t);
						// change the count of id[i] list to zero
						start[t].data = 0;
						// decrease counter by 1
						counter--;
					}
					else {
						int t = id[j];
						change(id[j], id[i]);
						start[id[i]].data += start[t].data;
						append2(id[i], t);
						start[t].data = 0;
						counter--;
					}
				}
			}
		}
		int i;
		for (i = 1; i <= n; i++)
			if (id[i] == -1) {
				start[k].data++;
				k++;
				counter++;
			}
		int ans = 1;
		for (i = 0; i < k; i++)
			if (start[i].data != 0)
				ans = (ans*start[i].data) % 1000000007;
		printf("%d %d\n", counter, ans);
	}
	
	return 0;
}
