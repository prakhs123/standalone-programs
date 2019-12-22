#include <stdio.h>

int counter;
int search (int digit, int a[], int upper) {
	int i;
	for (i = 0; i < upper; i++)
		if (a[i] == digit)
			return 1;
	return 0;
}
void count(int a[], int i, int l)
{
	int j, k;
	if (i >= l)
		return;
		for (j = 0; j <= 9; j++) {
			if (!search(j, a, i)) {
				a[i] = j;
				if (i >= l-1) {
					counter++;
				}
				else
					count(a, i+1, l);
			}
		}
	return;
}
main()
{
	int i, j;
	int delicious_table[7][7];
	int a[10];
	for (i = 1; i <= 10; i++)
	{
		counter = 0;
		for (j = 1; j < 10; j++) {
			a[0] = j;
			count(a, 1, i);
		}
		printf("%d ,", counter);
	}
}
