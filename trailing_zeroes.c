#include <stdio.h>
#include <math.h>

long int count = 0l;
void find_no_of_5s(long int n) {
	if (n/5 == 1)
		count += 1;
	else {
		count += n/5;
		find_no_of_5s(n/5);
	}
}

long int endZeroes(long int n){
	long int count =0l,i=1l;
	while(n/(int)(pow(5,i))>0){
		count+=n/(int)(pow(5,i));
		i++;
	}
	return count;
}

main()
{
	long int n;
	scanf("%ld", &n);
	printf("%ld\n", endZeroes(n));
	find_no_of_5s(n);
	printf("%ld\n", count);
}

