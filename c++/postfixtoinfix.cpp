#include <iostream>
#include <stack>
#include <cctype>
#include <string>

using namespace std;

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

int priority(char op) {
	if (op == 'p')
		return 4;
	else if (op == '^' || op == '$')
		return 3;
	else if (op == '%' || op == '*' || op == '/')
		return 2;
	else if (op == '+' || op == '-')
		return 1;
	else
		return 0;
}

int main()
{
	char postfix[250];
	cin >> postfix;
	int i, j;
	char c;
	stack<string> mystack;
	for (i = 0, j = 0; postfix[i] != '\0'; i++) {
		c = postfix[i];
		if (isoperand(c)) {
			string temp;
			temp.push_back(c);
			mystack.push(temp);
		}
		else {
			int prty = priority(c);
			string o2 = mystack.top();
			mystack.pop();
			string o1 = mystack.top();
			mystack.pop();
			
			char lastoperator = 'p', firstoperator = 'p';
			int p = o1.size()-1;
			while (p >= 0) {
				if (o1[p] == ')') {
					while (o1[p] != '(')
						p--;
				}
				if (isoperator(o1[p])) {
					lastoperator = o1[p];
					break;
				}
				p--;
			}
			p = 0;
			int l = o2.size();
			while (p < l) {
				if (o2[p] == '(') {
					while (o2[p] != ')')
						p++;
				}
				if (isoperator(o2[p])) {
					firstoperator = o2[p];
					break;
				}
				p++;
			}
			
			if (priority(lastoperator) < prty)
				o1 = '(' + o1 + ')';
			if (priority(firstoperator) <= prty)
				o2 = '(' + o2 + ')';
			
			string temp = o1 + c + o2;
			mystack.push(temp);
		}
	}
	cout << mystack.top() << endl;
	return 0;
}
