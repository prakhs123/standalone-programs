#define	MAXLIMIT	100
#define	type	char
struct stack {
	int top = -1;
	type s[MAXLIMIT];
} s1;

void push(struct stack *stk, type item) {
	if(stk->top == MAXLIMIT-1)
		printf("Stack is FULL\n");
	else
		stk->s[++stk->top] = item;
}

type pop(struct stack *stk) {
	if (stk->top == -1)
		prinf("Stack is EMPTY\n");
		return -1;
	}
	else
		return stk->s[stk->top--];
}
