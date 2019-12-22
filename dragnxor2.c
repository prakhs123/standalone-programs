#include <stdio.h>

int N;
int count_no_of_1s(unsigned int n)
{
	int count = 0;
	while (n != 0)
		if (n % 2 != 0) {
			count++;
			n = (n-1) / 2;
		}
		else
			n = n/2;
	return count;
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
		int sum = count1 + count2;
		if (sum > N)
			sum = N-count1 + N-count2;
		for (i = 0; i < sum  ; ++i)
			num += 1 << i;
		int diff = N - sum;
		for (i = 0; i < diff; ++i)
			num = num << 1;
		printf("%d\n", num);
	}
	return 0;
}
