#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	string array[5] = {"Prakhar","Avani","Pradeep","Rashmi","ABC"};
	sort(array, array+5);
	int i;
	for (i = 0; i < 5; i++)
		cout << array[i] << endl;
}
