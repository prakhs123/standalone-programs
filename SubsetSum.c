#include <stdio.h>

int isSubsetSum(int set[], int n, int sum)
{
	int isSum[sum+1];
	int i, j;
	isSum[0] = 1;
	for (i = 0; i < n; i++) {
		for (j = sum - set[i]; j >= 0; j--) {
			if (isSum[j] == 1)
				isSum[j+set[i]] = 1;
		}
		if (isSum[sum] == 1)
			return 1;
	}
	
	return 0;
}

int main()
{
  int set[] = {3, 34, 4, 12, 5, 2};
  int sum = 9;
  int n = sizeof(set)/sizeof(set[0]);
  if (isSubsetSum(set, n, sum) == 1)
     printf("Found a subset with given sum");
  else
     printf("No subset with given sum");
  return 0;
}
