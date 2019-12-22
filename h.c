#include <stdio.h>

int R = 7;

int nextkroom(int r, int k) {
	return (r+k)%R;
}

main()
{
	int a1, a2, a3, temp1, temp2, r;
	r = 3;
	a1 = 1;
	a2 = 2;
	a3 = 3;
	printf("3 ");
	r = nextkroom(r, a1);
	printf("%d ", r);
	r = nextkroom(r, a2);
	printf("%d ", r);
	r = nextkroom(r, a3);
	printf("%d ", r);
	int counter = 0;
	while (counter <= 20) {
		temp1 = a3;
		temp2 = a2;
		a3 = a1 + a2 + a3;
		r = nextkroom(r, a3);
		printf("%d ", r);
		a2 = temp1;
		a1 = temp2;
		counter++;
	}
	return 0;
}
