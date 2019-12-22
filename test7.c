#include <stdio.h>


int counter = 0;
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
	for (j = 0; j <= 9; j++) {
		if (!search(j, a, i)) {
			a[i] = j;
			if (i >= l-1) {
				for (k = 0; k <= i; k++)
					printf("%d", a[k]);
				printf("\n");
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
	int i;
	int a[10];
	int l;
	int L, R;
	
	scanf("%d %d", &L, &R);
	int t1 = L;
	int t2 = R;
	int digitsL = 0;
	int digitsR = 0;
	int firstdigitL = 1;
	int firstdigitR;
	int flag = 9;
	while (L) {
		firstdigitL = L;
		digitsL++;
		L = L/10;
	}
	while (R) {
		firstdigitR = R;
		digitsR++;
		R = R/10;
	}
	l = digitsL;
	for (i = firstdigitL; i <= 9 && i <= flag; i++) {
		a[0] = i;
		count(a, 1, l);
		if (i == 9 && l < digitsR) {
			if (l == digitsR - 1)
				flag = firstdigitR;
			i = 0;
			l++;
		}
	}
	printf("%d\n", counter);
	return 0;
}
