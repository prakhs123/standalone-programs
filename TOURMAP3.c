#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

struct node {
	char name[50];
	int index;
	struct node *link;
};
/*int find(struct node **s, char *b)
{
	int indx;
	struct node *temp, *temp2;
	int flag = 1
	if (strcmp((*s)->name, b) == 0) {
		indx = (*s)->index;
		temp = *s;
		free (temp);
		*s = (*s)->link;
		flag = 0;
	}
	else {
		temp = (*s)->link;
		while (temp != NULL) {
			if (strcmp(temp, b) == 0) {
				indx = temp->index;
				printf("%s ", temp->name);
				strcpy(temp->name, temp->link->name);
				temp->index = temp->link->index
				temp->link = temp->link-link;
				flag = 1;
			}
			temp = temp->link;
		}
	}
}*/
		
main()
{
	int t;
	int n;
	struct node *cities = NULL;
	struct node *t2;
	char cities2[5000][50];
	int cost[5000];
	int i;
	int c;
	int flag;
	int indx;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n == 1)
			printf("0$\n");
		else {
			cities = NULL;
			for (i = 0; i < n-1; i++) {
				struct node *temp = (struct node *) malloc(sizeof(struct node));
				scanf("%s", temp->name);
				temp->index = i;
				temp->link = cities;
				cities = temp;
				scanf("%s", cities2[i]);
				while (isspace (c = getchar()))
					;
				cost[i] = cost[i] * 10 + c - '0';
				while (isdigit(c = getchar()))
				cost[i] = cost[i] * 10 + c - '0';
			}
			/* start - find a name in cities that is not present in cities2; store its index and print the city name of that index; remove that node from cities */
			t2 = cities;
			while (t2 != NULL) {
				for (i = 0; i < n-1; i++)
					if (strcmp(t2->name, cities2[i]) == 0)
						break;
				if (i == n-1) {
					indx = t2->index;
					printf("%s ", t2->name);
					if (t2->link == NULL) {
						printf("***\n");
						t2 = NULL;
						free(t2);
						break;
					}
					strcpy(t2->name, t2->link->name);
					t2->index = t2->link->index;
					t2->link = t2->link->link;
					free(t2->link);
					break;
				}
				t2 = t2->link;
			}
			/* end */
			printf("%s %d$\n", cities2[indx], cost[indx]);
			t2 = cities;
			while (t2 != NULL) {
				printf("%d-%s\n", t2->index, t2->name);
				t2 = t2->link;
			}
			/*for (i = 0; i < n-2; i++) {
				indx = find(cities2[indx], &cities);
			*/
			for (i = 0; i < n-1; i++)
				cost[i] = 0;	
		}
	}
	return 0;
}
	
