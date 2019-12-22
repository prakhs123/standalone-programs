#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<char> mycharvector;
	mycharvector.push_back('a');
	mycharvector.push_back('v');
	mycharvector.push_back('a');
	mycharvector.push_back('n');
	mycharvector.push_back('i');
	
	vector<char> :: iterator it;
	
	for (it = mycharvector.begin(); it != mycharvector.end(); it++)
		cout << *it << " ";
	cout << endl;
	
	it = mycharvector.begin() + 2;
	mycharvector.insert(it, 'B');
	
	for (it = mycharvector.begin(); it != mycharvector.end(); it++)
		cout << *it << " ";
	cout << endl;
	
	cout << "Size :" << (int)mycharvector.size() << endl;
	
	sort(mycharvector.begin(), mycharvector.end());
	for (int i = 0;i < mycharvector.size(); i++)
		cout << mycharvector.at(i) << "  ";
	cout << endl;
	
	return 0;
}
