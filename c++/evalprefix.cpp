#include <iostream>
#include <stack>
#include <cctype>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

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
			break;
		default: 
			cout << "Invalid operator\n";
			break;	
	}
}

int main()
{
	char prefix[250];
	cin >> prefix;
	int i;
	char c;
	stack<long double> mystack;
	for (i = strlen(prefix)-1; i >= 0; i--) {
		c = prefix[i];
		if (isalnum(c))
			mystack.push((long double)(c-'0'));
		else {
			long double o1, o2, res;
			o1 = mystack.top();
			mystack.pop();
			o2 = mystack.top();
			mystack.pop();
			res = oper(c,o1,o2);
			mystack.push(res);
		}
	}
	cout << mystack.top() << endl;
	return 0;
}
