#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define	MAXLIMIT	100
#define	N	1000

struct stack {
	int top;
	char s[MAXLIMIT][MAXLIMIT];
} s1;

void push(struct stack *stk, char item) {
	if(stk->top == MAXLIMIT-1)
		printf("Stack is FULL\n");
	else {
		stk->s[++stk->top][0] = item;
		stk->s[stk->top][1] = '\0';
	}
}

void push2(struct stack *stk, char *item) {
	if (stk->top == MAXLIMIT-1)
		printf("Stack is FULL\n");
	else
		strcpy(stk->s[++stk->top], item);
}

char *pop(struct stack *stk) {
	if (stk->top == -1) {
		printf("Stack is EMPTY\n");
		return "";
	}
	else {
		return stk->s[stk->top--];
	}
}

main()
{
	char postfix[N];
	scanf("%s", postfix);
	int i;
	char *temp1, *temp2;
	char temp3[N];
	s1.top = -1;
	for (i = 0; postfix[i] != '\0'; i++) {
		if (isalnum(postfix[i]))
			push(&s1, postfix[i]);
		if (postfix[i] == '*' || postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '/' || postfix[i] == '%' || postfix[i] == '^' || postfix[i] == '$') 
		{
			temp1 = pop(&s1);
			temp2 = pop(&s1);
			temp3[0] = '(';
			strcpy(temp3+1, temp2);
			int len = strlen(temp3);
			temp3[len] = postfix[i];
			temp3[len+1] = '\0';
			strcat(temp3, temp1);
			len = strlen(temp3);
			temp3[len] = ')';
			temp3[len+1] = '\0';
			push2(&s1, temp3);
		}
	}
	printf("%s\n", pop(&s1));
	
	return 0;
}
