#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define	MAXLIMIT	100
#define	N	1000

struct stack {
	int top;
	char s[MAXLIMIT];
} s1;

void push(struct stack *stk, char item) {
	if(stk->top == MAXLIMIT-1)
		printf("Stack is FULL\n");
	else
		stk->s[++stk->top] = item;
}

char pop(struct stack *stk) {
	if (stk->top == -1) {
		printf("Stack is EMPTY\n");
		return -1;
	}
	else {
		return stk->s[stk->top--];
	}
}

int priority (char c)
{
	if (c == '$' || c == '^')
		return 3;
	else if (c == '%' || c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return 0;
}

void strrev (char s[])
{
	int j = strlen(s) - 1;
	int i = 0;
	int c;
	for (; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}
main()
{
	char infix[N], prefix[N];
	scanf("%s", infix);
	strrev(infix);
	int i, j;
	for (i = 0, j = 0; infix[i] != '\0';) {
		if (isalnum(infix[i])) 
		{
			while (isalnum(infix[i])) 
			{
				prefix[j++] = infix[i];
				i++;
			}
		}
		if (infix[i] == ')')
		{
			push(&s1, ')');
			i++;
		}
		if (infix[i] == '*' || infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '%' || infix[i] == '^' || infix[i] == '$') 
		{
			if (s1.top != -1) 
			{
				char opr = pop(&s1);
				
				while (priority(opr) > priority(infix[i])) 
				{
					prefix[j++] = opr;
					opr = pop(&s1);
				}
				push(&s1, opr);
				push(&s1, infix[i]);
			}
			else
				push(&s1, infix[i]);
			i++;
		}
		if (infix[i] == '(')
		{
			char opr = pop(&s1);
			while (opr != ')')
			{
				prefix[j++] = opr;
				opr = pop(&s1);
			}
			i++;
		}
	}
	
	while (s1.top != -1)
	{
		char opr = pop(&s1);
		prefix[j++] = opr;
	}
	prefix[j] = '\0';
	strrev(prefix);
	printf("%s\n", prefix);
	
	return 0;
}
