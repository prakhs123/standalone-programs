#include <iostream>
#include <queue>

using namespace std;

int comp(const int& lhs, const int& rhs) {
	return lhs < rhs;
}
int main()
{
	int a[] = { 10, 50, 30, 40};
	priority_queue< int, vector<int> ,greater<int> > mypq(a,a+4);
	while (!mypq.empty()) {
		cout << mypq.top() << endl;
		mypq.pop();
	}
	return 0;
}
