#include <stdio.h>

int N;
/* count no. of 1's in the binary representation of n */
int count_no_of_1s(unsigned int n)
{
	int binary_no[30 + 1];	/* binary representation in reverse order */
	int i, j;
	int count = 0;	/* no of 1s */
	for (i = 1; i <= N; i++)
	{
		int temp1 = n >> i;
		int temp2 = temp1 << i;
		printf("%d : %d %d %d\n", i, n, temp1, temp2);
		for (j = 1; j < i; ++j)	/* add previous 1's less than ith position */
			if (binary_no[j] == 1)
				temp2 = temp2 + (1 << j-1);
		printf("%d : %d %d %d\n", i, n, temp1, temp2);
		printf("%d\n", n & temp2);
		if (n == temp2)
			binary_no[i] = 0;
		else {
			binary_no[i] = 1;
			++count;
		}
	}
}

main()
{
	int test;
	scanf("%d", &test);
	while (test--) {
		unsigned int A, B;
		scanf("%d %u %u", &N, &A, &B);
		int count1 = 0, count2 = 0;
		int i;
		int num = 0;
		count1 = count_no_of_1s(A);
		count2 = count_no_of_1s(B);
		printf("%d %d\n", count1, count2);
		int sum = count1 + count2;
		if (sum > N)
			sum = N-count1 + N-count2;
		for (i = sum; i > 0 ; --i)
			num += 1 << i+1;
		printf("%d\n", num);
	}
	return 0;
}
