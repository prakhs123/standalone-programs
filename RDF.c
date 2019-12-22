#include <stdio.h>
double myfun(int N, int K, double p)
{
	if (N <= 0)
		return 0;
	else if (K == 0)
		return p*N;
	else {
		int i;
		double ans = 0;
		for (i = 0; i < N; i++) {
			double t = myfun(i,K-1,p*(1.0/N)); 
			printf("%d %d:%f\n", i, K-1, t);
			ans += t;
		}
		return ans;
	}
}

int main()
{
	int i;
	for (i = 1; i <= 6; i++) {
		printf("%.8f\n", myfun(i,2,1));
		printf("---\n");
	}
	return 0;
}
