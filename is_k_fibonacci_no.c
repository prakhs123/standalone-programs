#include <stdio.h>

/* given a value k, check whether there exist a fibonnaci number equal to k else print that there does not exist any such fibonnaci number */
main()
{
	int k;
	int i;
	int a; // F(i-1)
	int b; // F(i-2)
	int c; // F(i)
	int flag; // true only when F(i) = k else false

	i = 1;	// F(1)
	a = 1;	// F(1)
	b = 0;	// F(0)
	c = 1;	// Intially F(1) to check case of F(1) in loop
	flag = 0;

	printf("Enter the value of k: ");
	scanf("%d", &k);

	/* special case where F(0) = 0 */
	if (k == 0)
		printf("F(0) = 0\n");
	else {
		while (c <= k) {
			if (c == k){
				flag = 1;
				printf("F(%d) = %d\n", i, k);
			}
			c = a + b;
			b = a;
			a = c;
			i = i + 1;
		}
		if (flag == 0)
			printf("There does not exist any k fibonnaci number\n");
	}
}
	
