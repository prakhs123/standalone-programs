#include <stdio.h>
#include <malloc.h>
#include <ctype.h>

#define	MAXLINE	1000

struct node {
	int data;
	struct node *link;
};

void push(struct node **s, int data)
{
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	temp->data = data;
	temp->link = *s;
	*s = temp;
}

int pop(struct node **s)
{
	if (*s == NULL)
		return -1;
	int temp = (*s)->data;
	*s = (*s)->link;
	return temp;
}

int priority(char c)
{
	if (c == '^')
		return 3;
	else if (c == '%' || c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return 0;
}
main()
{
	struct node *stacktop = NULL;
	char infix[MAXLINE], postfix[MAXLINE];
	scanf("%s", infix);
	
	int i, j;
	for (i = 0, j = 0; infix[i] != '\0'; ++i) {
		if (isalpha(infix[i]) || isdigit(infix[i]))
			postfix[j++] = infix[i];
		else if (infix[i] == '^' || infix[i] == '%' || infix[i] == '*' || infix[i] == '/' || infix[i] == '+' || infix[i] == '-') {
			int prty = priority(infix[i]);
			int c = 5;
			while (stacktop != NULL && priority((c = pop(&stacktop))) >= prty)
				postfix[j++] = c;
			if (priority(c) < prty)
				push(&stacktop, c);
			push(&stacktop, infix[i]);
		}
		else if (infix[i] == '(')
			push(&stacktop, infix[i]);
		else if (infix[i] == ')') {
			int c;
			while ((c = pop(&stacktop)) != '(')
				postfix[j++] = c;
		}
			
	}
	int c;
	while ((c = pop(&stacktop)) != -1)
		postfix[j++] = c;
	postfix[j] = '\0';
	printf("%s\n", postfix);
	return 0;
}
