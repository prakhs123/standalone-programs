#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
using namespace std;

void encode (char symb[], string code[], int n, string msge, string& bitcode)
{
	int l = msge.size();
	bitcode = "";
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < n; j++)
			if (symb[j] == msge.at(i))
				break;
		bitcode.append(code[j]);
	}
}

int main()
{
	return 0;
}
