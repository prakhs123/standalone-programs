#include <stdio.h>
#include <string.h>

#define	N	1000001
#define	NAMELEN	16

struct stack {
	char name[N][NAMELEN];
	int exer[N];
	int top;
	int min_exer;
	int min;
} s;

struct popitem {
	char name[NAMELEN];
	int number;
} p1;

void push(struct stack *s, int e, char n[])
{
	if (s->top >= N)
		printf("Error: Stack FULL\n");
	else {
		s->exer[s->top] = e;
		strcpy(s->name[s->top], n);
		if (e <= s->min_exer) {
			s->min_exer = e;
			s->min = s->top;
		}
		s->top++;
	}
}

struct popitem *pop(struct stack *s) {
	if (s->top <= 0) {
		printf("Error1: Stack EMPTY\n");
		return NULL;
	}
	else {
		int temp = s->top;
		while (s->top != s->min) {
			if(s->top < 0) {
				printf("Error2: Stack EMPTY\n");
				return NULL;
			}
			s->top--;
		}
		int i = 1;
		s->min_exer = 100000;
		while (s->top - i >= 0) {
			if (s->exer[s->top-i] < s->min_exer) {
				s->min_exer = s->exer[s->top-i];
				s->min = s->top-i;
			}
			i++;
		}
		p1.number = temp - s->top - 1;
		strcpy(p1.name, s->name[s->top]);
		return &p1;
	}
}

inline void scan(int *a) {
	register char c = 0;
	register char sign = 1;
	while (c < 33)
		c = getchar_unlocked();
	if (c == 45) {
		sign = -1;
		c = getchar_unlocked();
	}
	*a = 0;	
	while (c > 33) {
		*a = *a * 10 + c - '0';
		c = getchar_unlocked();
	}
	*a = *a * sign;
}

main()
{
	int n;
	int Ex;
	char Name[NAMELEN];
	scan(&n);
	/* stack initialization */
	s.top = 0;
	s.min_exer = 100000;
	/* End of initialization */
	while(n--) {
		scan(&Ex);
		if (Ex == -1) {
			pop(&s);
			printf("%d %s\n", p1.number, p1.name);
		}
		else {
			scanf("%s", Name);
			if (Ex > 0)
				push(&s, Ex, Name);
		}
	}
	
	return 0;
}
			
	
