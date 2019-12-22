#include <stdio.h>

#define MAXLEN	19
int digits_L[MAXLEN];
int digits_R[MAXLEN];

int counter = 0;
void reverse(int a[])
{
	int i = 0;
	int j = MAXLEN-1;
	while (i < j) {
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		i++;
		j--;
	}
}
void remove_pre_zeroes(int a[])
{
	int i, j;
	for (i = 0; i < MAXLEN; i++)
		if (a[i] != 0)
			break;

	for (j = i; j < MAXLEN; j++) {
		a[j-i] = a[j];
		a[j] = 0;
	}
}
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
void count2(int a[], int i, int l, int maxl, int a2[], int flag[])
{
	int j, k;
	if (flag[i] == 0) {
		j = digits_L[i];
		flag[i] = 1;
	}
	else
		j = 0;
	for (; j <= 9; j++) {
		if (!search(j, a, i)) {
			a[i] = j;
			if (i >= l-1) {
				for (k = 0; k <= i; k++)
					printf("%d", a[k]);
				printf("\n");
				counter++;
			}
			else
				count2(a, i+1, l, flag);
		}
		if (j == 9) {
			if (l + 1 <= maxl)
				l++;
			if (l == maxl) {
				for(i = 0; i < 10; i++)
					a2[i] = digits_R[i];
				count2(a, 0, l, maxl,
			for(i = 0; i < 10; i++)
				a[i] = -1;
			count2(a, 0, l, maxl, a2, flag);
		}
	}
	return;
}
main()
{
	int i, j, k;
	j = 0;
	k = 0;
	int a[10];
	int l;
	int L, R;
	for(i = 0; i < 10; i++)
		a[i] = -1;
	
	scanf("%d %d", &L, &R);
	int t1 = L;
	int t2 = R;
	int digitsL = 0;
	int digitsR = 0;
	int flag = 9;
	int f2 = 0;
	int a2[] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
	while (L) {
		digits_L[j++] = L % 10;
		digitsL++;
		L = L/10;
	}
	while (R) {
		digits_R[k++] = R % 10;
		digitsR++;
		R = R/10;
	}
	int f[10] = {0};
	reverse(digits_L);
	remove_pre_zeroes(digits_L);
	reverse(digits_R);
	remove_pre_zeroes(digits_R);
	count2(a, 0, digitsR, f);
	l = digitsL+1;
	/*for (i = 1; i <= 9 && i <= flag; i++) {
		a[0] = i;
		count(a, 1, l);
		if (i == 9 && l <= digitsR) {
			if (l == digitsR - 1) {
				flag = digits_R[0];
				printf("%d\n", flag);
			}
			i = 0;
			l++;
		}
	}
	printf("%d\n", counter);*/
	return 0;
}
