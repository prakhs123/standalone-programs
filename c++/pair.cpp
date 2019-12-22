#include <iostream>
#include <algorithm>

using namespace std;
struct compare {
	bool operator(const pair<int,int>& lhs, const pair<int,int>& rhs)
	{
		return lhs.first < rhs.first;
	}
};
int main()
{
	pair <int, int> c[4];
	c[0]=make_pair(3,7);
	c[1]=make_pair(1,9);
	c[2]=make_pair(5,11);
	c[3]=make_pair(4,3);
	sort(c,c+4,compare());
	int i;
	for (i = 0; i < 4; i++)
		cout << c[i].first << "," << c[i].second << endl;
}
