#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void reverse(list<int>& l) {
	list<int>::iterator first = l.begin();
	list<int>::iterator last = l.end();
	if (first != last) {
		last--;
		if (first != last) {
			while (true) {
				int temp = *first;
				*first = *last;
				*last = temp;
				first++;
				if (first == last)
					break;
				last--;
				if (first == last)
					break;
			}
		}
	}
}

void display(list<int>& l) {
	list<int>::iterator it = l.begin();
	for (; it != l.end(); it++)
		cout << *it << ' ';
	cout << '\n';
}

int main()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	display(l);
	reverse(l.begin(),l.end());
	//reverse(l);
	display(l);
	
	return 0;
}
