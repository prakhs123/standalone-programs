#include <stdio.h>

/* program to output balance of the account after withdrawal of amount;
	amount should be multiple of 5 and should be less than initial balance
	otherwise initial balance will be printed */

#define BANK_CHARGES 0.50

int main()
{
	int amount;
	float balance;

	scanf("%d", &amount);
	scanf("%f", &balance);
	
	if (amount % 5 == 0 && amount + BANK_CHARGES <= balance)
		printf("%.2f\n", balance - amount - BANK_CHARGES);
	else
		printf("%.2f\n", balance);
	
	return 0;
}
