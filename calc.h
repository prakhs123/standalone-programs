#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#define	NUMBER	'0'
#define	NAME	'n'
void push(double);
double pop(void);
double top(void);
void clear(void);
int getop(char []);
int getch(void);
void ungetch(int);
