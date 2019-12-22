#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	deque<string> mydeq;
	mydeq.push_front("Prakhar");
	mydeq.push_back("Avani");
	mydeq.push_front("Pradeep");
	mydeq.push_back("Rashmi");
	
	deque<string> :: iterator it;
	
	cout << "My Deque contains :";
	for (it = mydeq.begin(); it != mydeq.end(); it++)
		cout << *it << " ";
	cout << endl;
	sort(mydeq.begin(), mydeq.end());
	cout << "My Deque contains :";
	for (it = mydeq.begin(); it != mydeq.end(); it++)
		cout << *it << " ";
	cout << endl;
	return 0;
}
