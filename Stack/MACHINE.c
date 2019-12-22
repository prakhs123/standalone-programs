#include	<stdio.h>
#include	<string.h>
#define	SIZE	100
struct stack {
	char op[SIZE][SIZE];
	int top;
} s;
void strrev(char s[])
{
	int i = 0;
	int j = strlen(s) - 1;
	while (j > i) {
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}
void push1(struct stack *s1, char a) {
	if (s1->top == SIZE - 1)
		printf("Stack overflow\n");
	else {
		s1->op[++s1->top][0] = a;
		s1->op[s1->top][1] = '\0';
	}
}
void push2(struct stack *s1, char s[], int c) {
	if (s1->top == SIZE - 1)
		printf("Stack overflow\n");
	else {
		strcpy(s1->op[++s1->top], s);
		char num[15];
		int i = 0;
		while (c != 0) {
			num[i++] = c % 10 + '0';
			c = c / 10;
		}
		num[i] = '\0';
		strrev(num);
		strcat(s1->op[s1->top], num);
	}
}
void pop(struct stack *s1, char dest[]) {
	if (s1->top == -1)
		printf("Stack underflow\n");
	else
		strcpy(dest, s1->op[s1->top--]);
}
int isoperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return 1;
	else
		return 0;
}
int isoperand(char c) {
	return !isoperator(c);
}
main()
{
	char postfix[SIZE];
	char opnd1[SIZE], opnd2[SIZE];
	scanf("%s", postfix);
	int i;
	int j;
	s.top = -1;
	for (i = 0, j = 1; postfix[i] != '\0'; i++) {
		if (isoperand(postfix[i]))
			push1(&s, postfix[i]);
		else if (isoperator(postfix[i])) {
			pop(&s, opnd2);
			pop(&s, opnd1);
			printf("LD\t%s\n", opnd1);
			switch (postfix[i]) {
				case '*':
					printf("ML\t");
					break;
				case '+':
					printf("AD\t");
					break;
				case '-':
					printf("SB\t");
					break;
				case '/':
					printf("DV\t");
					break;
			}
			printf("%s\n", opnd2);
			printf("ST\tTEMP%d\n", j);
			push2(&s, "TEMP", j);
			j++;
		}
	}
	
	return 0;
}
