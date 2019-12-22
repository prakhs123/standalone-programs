#include <stdio.h>
#include <math.h>
main()
{
	int testcase;
	scanf("%d", &testcase);
	while (testcase--) {
		int array[2000 + 1];
		int length, i, j;
		int sum = 0;
		scanf("%d", &length);
		for (i = 1; i <= length; i++)
			scanf("%d", &array[i]);
		if (length % 2 != 0) {
			sum += (length+1)/2*array[(length+1)/2];
			for (i = 3; i <= length; i += 2)
				sum += ((length+3)/2) * (array[(length+i)/2] + array[(length-i+2)/2]);
		}
		else {
			for (i = 2,j = 2; i <= length; i += 2, j += 4)
				sum += ((length+j)/2) *(array[(length+i)/2] + array[(length-i+2)/2]);
		}
		printf("%f\n", pow(0.5, nlength-1) * sum);
	}
}
