#include <iostream>
#include <stack>
#include <cstring>
#include <cctype>

using namespace std;

void reverse(char s[]) {
	int i = 0;
	int j = strlen(s)-1;
	while (i < j) {
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
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

int main()
{
	char infix[250], prefix[250];
	cin >> infix;
	reverse(infix);
	char c;
	int i, j;
	stack<char> mystack;
	cout << infix << endl;
	for (i = 0, j = 0; infix[i] != '\0'; i++) {
		c = infix[i];
		if (isoperand(c))
			prefix[j++] = c;
		else if (c == ')')
			mystack.push(c);
		else if (isoperator(c)) {
			int prty = priority(c);
			while (!mystack.empty() && priority(mystack.top()) > prty) {
				prefix[j++] = mystack.top();
				mystack.pop();
			}
			mystack.push(c);
		}
		else if (c == '(') {
			while (mystack.top() != ')') {
				prefix[j++] = mystack.top();
				mystack.pop();
			}
			mystack.pop();
		}
	}
	while (!mystack.empty()) {
		prefix[j++] = mystack.top();
		mystack.pop();
	}
	prefix[j] = '\0';
	reverse(prefix);
	cout << prefix << endl;
	return 0;
}
