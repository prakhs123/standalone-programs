#include <iostream>
#include <set>

using namespace std;

int main()
{
	int myints[] = {75,23,65,42,13};
	set<int> myset(myints,myints+5);
	cout << myset[0] << endl;
	return 0;
}
