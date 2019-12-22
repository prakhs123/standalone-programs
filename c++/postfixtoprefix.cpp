#include <iostream>
#include <string>
#include <stack>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
	string postfix;
	stack<string> mystack;
	cin >> postfix;
	int i, l;
	l = postfix.size();
	for (i = 0; i < l; i++) {
		char c = postfix[i];
		if (isalnum(c)) {
			string temp;
			temp.push_back(c);
			mystack.push(temp);
		}
		else {
			string temp1 = mystack.top();
			mystack.pop();
			string temp2 = mystack.top();
			mystack.pop();
			string temp;
			temp.push_back(c);
			temp.append(temp2);
			temp.append(temp1);
			mystack.push(temp);
		}
	}
	cout << mystack.top() << endl;
}
