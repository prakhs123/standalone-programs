#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int compare(const void * a, const void * b)
{
	return strcmp(a, b);
}
struct node {
	char name[51];
	int index;
};
/*	1.Sort the Array cities (which was copy of A) and Array B2 (which was copy of B).	
	2.Do binary search in sorted array B (called B2) to find a city in A which is not present in B2.
	3.If the index found is i, then print "A[i] B[i] cost[i]$".
	4.Do this for n - 2 times :
		For each B[indx], find it in sorted array cities and use its index(called indx) to print A[indx] B[indx] cost[indx]$ and repeat the same
*/
main()
{
	int t;
	scanf("%d", &t);
	int n;
	int c;
	struct node cities[5000];// stored sorted array A with original index
	char A[5000][51];
	char B[5000][51];
	char B2[5000][51];// stored sorted array B to find(using binary search) first city which is present in A but not in B
	int cost[5000];
	int total_cost;
	int i, j, k;
	while (t--) {
		scanf("%d", &n);
		if (n == 1) {
			printf("0$\n");
		} else {
		/* Reading input - start */
		for (i = 0; i < n - 1; i++) {
			scanf("%s", A[i]);
			cities[i].index = i;
			strcpy(cities[i].name, A[i]);
			scanf("%s", B[i]);
			strcpy(B2[i], B[i]);
			while (isspace (c = getchar()))
				;
			cost[i] = cost[i] * 10 + c - '0';
			while (isdigit(c = getchar()))
			cost[i] = cost[i] * 10 + c - '0';
		}
		/* Reading input - end */
		/* Shell Sort starts for array "cities" and "B2" 
			note : original index in array "cities" is stored*/
		int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
		for (k = 0; k < 8; k++)
			for (i = gaps[k]; i < n - 1; ++i) {
				char temp[51];
				strcpy(temp, cities[i].name);
				int ind = cities[i].index;
				
				for (j = i; j >= gaps[k] && strcmp(cities[j-gaps[k]].name, temp) > 0; j -= gaps[k]) {
					strcpy(cities[j].name, cities[j-gaps[k]].name);
					cities[j].index = cities[j-gaps[k]].index;
				}
				strcpy(cities[j].name, temp);
				cities[j].index = ind;
				
				char temp2[51];
				strcpy(temp2, B2[i]);
				
				for (j = i; j >= gaps[k] && strcmp(B2[j-gaps[k]], temp2) > 0; j -= gaps[k])
					strcpy(B2[j], B2[j-gaps[k]]);
				strcpy(B2[j], temp2);
			}
			/* Shell Sorts Ends */
		/* Binary Search to find city in A that is not present in B */
		for (i = 0; i < n - 1; i++) {
			char *t = (char *)bsearch(A[i], B2[0], n-1, sizeof(char[51]), compare);
			if (t == NULL)
				break;
		}
		/* printing 1st City */
		printf("%s %s %d$\n", A[i], B[i], cost[i]);
		total_cost = cost[i];
		int low, high, mid, indx;
		indx = i;	// using this index we ll continue finding B[indx] in sorted array "cities" and will get new value of index
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
	
