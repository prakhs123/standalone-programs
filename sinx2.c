#include <stdio.h>

/* Program to compute sinx using taylor series up to accuracy e */
main()
{
	float x, e, sinx, diff, prevterm, term;
	int k;
	
	printf("Enter the value of x :");
	scanf("%f", &x);
	printf("Enter the value of e :");
	scanf("%f", &e); 

	sinx = x;
	prevterm = 0.0;
	diff = x;
	k = 1;
	term = x;
	if (diff < 0.0)
		diff = -diff;
	
	while (diff > e) {
		prevterm = term;
		term = -term * x * x / ((k+1)*(k+2));
		sinx = sinx + term;	
		k = k + 2;
		diff = term - prevterm;
		if (diff < 0)
			diff = -diff;
	}

	printf("The value of sinx for accuracy %f = %f\n", e, sinx);
}
