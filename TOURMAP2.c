#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int compare(const void * a, const void * b)
{
	return strcmp(a, b);
}
struct node {
	char name[50];
	int index;
};
main()
{
	int t;
	scanf("%d", &t);
	int n;
	int c;
	struct node cities[5000];
	char A[5000][50];
	char B[5000][50];
	char B2[5000][50];
	int cost[5000];
	char cst[6];
	int total_cost;
	int i, j, k;
	while (t--) {
		scanf("%d", &n);
		if (n == 1) {
			printf("0$\n");
		} else {
		for (i = 0; i < n - 1; i++) {
			scanf("%s", A[i]);
			cities[i].index = i;
			strcpy(cities[i].name, A[i]);
			scanf("%s", B[i]);
			strcpy(B2[i], B[i]);
			scanf("%s", cst);
			cost[i] = 0;
			for (j = 0; cst[j] != '$'; j++)
				cost[i] = cost[i] * 10 + cst[j] - '0';
		}
		int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
		for (k = 0; k < 8; k++)
			for (i = gaps[k]; i < n - 1; ++i) {
				char temp[50];
				strcpy(temp, cities[i].name);
				int ind = cities[i].index;
				
				for (j = i; j >= gaps[k] && strcmp(cities[j-gaps[k]].name, temp) > 0; j -= gaps[k]) {
					strcpy(cities[j].name, cities[j-gaps[k]].name);
					cities[j].index = cities[j-gaps[k]].index;
				}
				strcpy(cities[j].name, temp);
				cities[j].index = ind;
				
				char temp2[50];
				strcpy(temp2, B2[i]);
				
				for (j = i; j >= gaps[k] && strcmp(B2[j-gaps[k]], temp2) > 0; j -= gaps[k])
					strcpy(B2[j], B2[j-gaps[k]]);
				strcpy(B2[j], temp2);
			}
			
		for (i = 0; i < n - 1; i++) {
			char *t = (char *)bsearch(A[i], B2[0], n-1, sizeof(char[50]), compare);
			if (t == NULL)
				break;
		}
		
		printf("%s %s %d$\n", A[i], B[i], cost[i]);
		total_cost = cost[i];
		int low, high, mid, indx;
		indx = i;
		for (i = 0; i < n - 2; i++) { 
			low = 0;
			high = n - 2;
			while (low <= high) {
				mid = (low+high) / 2;
				if (strcmp(B[indx], cities[mid].name) < 0)
					high = mid - 1;
				else if (strcmp(B[indx], cities[mid].name) > 0)
					low = mid + 1;
				else
					break;
			}
			indx = cities[mid].index;
			total_cost += cost[indx];
			printf("%s %s %d$\n", A[indx], B[indx], cost[indx]);
		}
		printf("%d$\n", total_cost);
		for (i = 0; i < n - 1; i++)
			cost[i] = 0;
	}}
	return 0;
}
	
