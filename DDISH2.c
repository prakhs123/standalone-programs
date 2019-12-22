#include <stdio.h>
#include <math.h>

#define MAX_NO	9876543210LL

int counter;

void reverse(int a[])
{
	int i = 0;
	int j = 10-1;
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
	for (i = 0; i < 10; i++)
		if (a[i] != 0)
			break;

	for (j = i; j < 10; j++) {
		a[j-i] = a[j];
		a[j] = 0;
	}
}

void count_1(int a[], int i, int l, int flag[], int digits[])
{
	int j, k, inNum;
	
	if (i >= l)
		return;
	
	if (flag[i] == 0) {
		j = digits[i];
		flag[i] = 1;
	}
	else
		j = 0;	
	
	for (; j <= 9; j++) {
		inNum = 0;
		for (k = 0; k < i; k++)
			if (a[k] == j) {
				inNum = 1;
				break;
			}
		if (!inNum) {
			a[i] = j;
			if (i >= l-1) {
				counter++;
			}
			else
				count_1(a, i+1, l, flag, digits);
		}
	}
	return;
}

void count_2(int a[], int i, int l, int flag[], int digits[])
{
	int j, k, inNum;
	
	if (i >= l)
		return;
	
	if (flag[i] == 0) {
		j = digits[i];
		flag[i] = 1;
	}
	else
		j = 0;	
	
	for (; j <= 9; j++) {
		inNum = 0;
		for (k = 0; k < i; k++)
			if (a[k] == j) {
				inNum = 1;
				break;
			}
		if (!inNum) {
			a[i] = j;
			if (i >= l-1) {
				counter++;
			}
			else
				count_2(a, i+1, l, flag, digits);
		}
	}
	return;
}

main()
{
	int t;
	long long L, R, R2;
	int i;
	int digitsL;
	int digitsR;
	int digits_L[10];
	int digits_R[10];
	int count1; /* from L to 10 ^ digitsL */
	int count2; /* from R to 10 ^ digitsR */
	int num[10];
	int flag[10];
	int forEvery[10] = {1 ,9 ,72 ,504 ,3024 ,15120 ,60480 ,181440 ,362880 ,362880};
	int from10[10] = {0 ,81 ,648 ,4536 ,27216 ,136080 ,544320 ,1632960 ,3265920 ,3265920 }; /* from 10 ^ i to 10 ^ (i+1) */
	scanf("%d", &t);
	while (t--) {
		scanf("%lld %lld", &L, &R);
		if (L > MAX_NO) {
			printf("0\n");
			continue;
		}
		if (R > MAX_NO)
			R = MAX_NO;
		R = R + 1;
		R2 = R;
		
		for (i = 0; i < 10; i++) {
			digits_L[i] = 0;
			digits_R[i] = 0;
			num[i] = 0;
			flag[i] = 0;
		}
		
		digitsL = 0;
		digitsR = 0;
		i = 0;
		while (L) {
			digits_L[i++] = L % 10;
			digitsL++;
			L = L/10;
		}
		i = 0;
		while (R) {
			digits_R[i++] = R % 10;
			digitsR++;
			R = R/10;
		}
		
		reverse(digits_L);
		remove_pre_zeroes(digits_L);
		reverse(digits_R);
		remove_pre_zeroes(digits_R);
		
		counter = 0;
		count_1(num, 0, digitsL, flag, digits_L);
		count1 = counter;
		
		counter = 0;
		for (i = 0; i < 10; i++) {
			flag[i] = 0;
			num[i] = 0;
		}
		count_2(num, 0, digitsR, flag, digits_R);
		count2 = counter;
		
		if (digitsL == digitsR) {
			printf("%d\n", count1 - count2);
			continue;
		}
		else {
			/* add number of delicious numbers from 10 ^ digitsL to 10 ^ digitsR to count1 */
			for (i = digitsL; i < digitsR; i++)
				count1 += from10[i];
			printf("%d\n", count1 - count2);
		}
	}
	return 0;
}
		
