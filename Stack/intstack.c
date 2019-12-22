#include <stdio.h>
#include <stdlib.h>

class stack {
	private:
	const int MAXSIZE = 100;
	int s[MAXSIZE];
	int top = -1;

void push(struct stack *stk, int item) {
	if (stk->top == MAXSIZE-1) {
		printf("Overflow\n");
		exit(1);
	}
	stk->s[++stk->top] = item;
}

int empty(struct stack *stk) {
	if (stk->top == -1)
		return 1;
	else
		return 0;
}

int pop(struct stack *stk) {
	if (empty(stk)) {
		printf("Underflow\n");
		exit(1);
	}
	return stk->s[stk->top--];
}

int top(struct stack *stk) {
	if (empty(stk)) {
		printf("Underflow\n");
		exit(1);
	}
	return stk->s[stk->top];
}

main()
{
	struct stack mystack;
	printf("%d\n", mystack.top);
	while(1) {
		int n;
		printf("1.Push\n2.Pop\n3.Top\n4.Isempty\n5.Exit\n");
		scanf("%d", &n);
		int flag = 0;
		switch(n) {
			case 1:
				int num;
				printf("Enter a number\n");
				scanf("%d", &num);
				push(&mystack,num);
				break;
			case 2:
				printf("%d\n", pop(&mystack));
				break;
			case 3:
				printf("%d\n", top(&mystack));
				break;
			case 4:
				if (empty(&mystack))
					printf("Empty\n");
				else
					printf("Not Empty\n");
				break;
			case 5:
				flag = 1;
				break;
			default:
				flag = 1;
				break;
		}
		if (flag)
			break;
	}
	return 0;
}
