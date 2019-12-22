#include <iostream>
#include <cctype>
#include <cmath>
using namespace std;

template <class T,int size>

class Stack {
private:
	int top;
	T *nodes;
public:
	Stack ();
	int empty (void);
	void push(const T &);
	T pop(void);
	T pop(int &);
	
	~Stack ();
};
template <class T, int size> Stack<T,size>::Stack ()
{
	top = -1;
	nodes = new T[size];
};
template <class T, int size> Stack<T,size>::~Stack ()
{
	delete nodes;
};
template <class T, int size> int Stack<T, size>::empty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}
template <class T, int size> void Stack<T,size>::push(const T & j)
{
	if (top == size - 1) {
		cout << "Stack overflow" << endl;
		return;
	}
	nodes[++top] = j;
};
template <class T, int size> T Stack<T,size>::pop(void)
{
	T p;
	if (empty ()) {
		cout << "Stack underflow" << endl;
		return p;
	}
	p = nodes[top--];
	return p;
};
//popandtest
template <class T, int size> T Stack<T,size>::pop(int & und)
{
	T p;
	if (empty ()) {
		und = 1;
		return p;
	}
	und = 0;
	p = nodes[top--];
	return p;
};


void postfix(char *infix, char *postr);
int isoperand(char op);
int isoperator(char op);
long double eval(char *postr);
long double oper(int sym, long double op1, long double op2);
int priority(char op);

int priority(char op) {
	if (op == '^' || op == '$')
		return 3;
	else if (op == '%' || op == '*' || op == '/')
		return 2;
	else if (op == '+' || op == '-')
		return 1;
	else
		return 0;
}


int isoperator(char op) {
	if (op == '^' || op == '$' || op == '%' || op == '/' || op == '*' || op == '+' || op == '-')
		return 1;
	else 
		return 0;
}

int isoperand(char op) {
	if (isalnum(op))
		return 1;
	else 
		return 0;
}

void postfix(char *infix, char *postr)
{
	int position, und;
	int outpos = 0;
	char topsymb;
	Stack<char,50> opstk;
	
	for (position = 0; infix[position] != '\0'; position++) {
		if (isoperand(infix[position]))
		{
			postr[outpos++] = infix[position];
		}
		else if (infix[position] == '(')
		{
			opstk.push(infix[position]);
		}
		else if (isoperator(infix[position]))
		{
			int prty = priority(infix[position]);
			topsymb = opstk.pop(und);
			while (!und && priority(topsymb) >= prty) {
				postr[outpos++] = topsymb;
				topsymb = opstk.pop(und);
			}
			if (!und)
				opstk.push(topsymb);
			opstk.push(infix[position]);
		}
		else if (infix[position] == ')')
		{
			while ((topsymb = opstk.pop()) != '(')
				postr[outpos++] = topsymb;
		}
	}
	
	while (!opstk.empty())
		postr[outpos++] = opstk.pop();
	
	postr[outpos] = '\0';
}

long double oper(int symb, long double op1, long double op2)
{
	switch (symb) {
		case '+':
			return op1+op2;
			break;
		case '-':
			return op1-op2;
			break;
		case '*':
			return op1*op2;
			break;
		case '/':
			return op1/op2;
			break;
		case '^': case '$':
			return pow(op1,op2);
		default: 
			cout << "Invalid operator\n";
			
	}
}

long double eval(char *postr)
{
	int c, position;
	long double opnd1, opnd2, value;
	Stack<long double, 50> opndstk;
	for (position = 0; (c = postr[position]) != '\0'; position++)
		if (isoperand(c))
			opndstk.push((long double) (c-'0'));
		else {
			opnd2 = opndstk.pop();
			opnd1 = opndstk.pop();
			value = oper(c, opnd1, opnd2);
			opndstk.push(value);
		}
	return (opndstk.pop());
}

int main(void)
{
	char in[250], post[250];
	long double res;
	cin >> in;
	postfix (in, post);
	cout << post << endl;
	res = eval(post);
	cout << res << endl;
	
	return 0;
}
