#include <stdio.h>

/* Program to compute sinx using taylor series up to accuracy e */
main()
{
	float x, e, sinx, lastsinx, Tn_Tn_1, term;
	int n;
	
	printf("Enter the value of x :");
	scanf("%f", &x);
	printf("Enter the value of e :");
	scanf("%f", &e); 

	sinx = x;
	lastsinx = -1000.0;
	Tn_Tn_1 = 1000.0;
	n = 2;
	term = x;
	
	while ( Tn_Tn_1 > e) {
		term = -term * x * x / ((2*n-1)*(2*n-2));
		lastsinx = sinx;
		sinx = sinx + term;	
		n = n + 1;
		Tn_Tn_1 = sinx - lastsinx;
		if (Tn_Tn_1 < 0)
			Tn_Tn_1 = -Tn_Tn_1;
	}

	printf("The value of sinx for accuracy %f = %f\n", e, sinx);
}
