#include <stdio.h>
#include <math.h>

double answer = 0;
int n;
void probable(int a[], int s, int e, int flag, int sum)
{
	if (s == e) {
		if (flag)
			sum += a[s];
		answer += pow(0.5, n-1) * sum;
		return ;
	}
	
	if (flag) {
		sum += a[s];
		probable(a, s+1, e, 0, sum);
		
		sum += a[e] - a[s];
		probable(a, s, e-1, 0, sum);
	}
	else {
		probable(a, s+1, e, 1, sum);
		probable(a, s, e-1, 1, sum);
	}
}

main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int a[2000 + 1];
		int i;
		int sum = 0;
		answer = 0;
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		probable(a, 1, n, 1, 0);
		printf("%f\n", answer); 
	}
	return 0;
}
