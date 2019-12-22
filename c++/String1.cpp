#include <iostream>
#include <string.h>
using namespace std;

class String1 {
	int length;
	char *ptr;
public:
	String1(int N, char s[]) {
		ptr = new char[N];
		strcpy(s, ptr);
	}
	String1(int N) {
		ptr = new char[N];
	}
	String1 concat(String1 s2) {
		String1 result(s2.length+length, strcat(ptr, s2.ptr));
	}
	
	void print(void)
	{
		cout << ptr;
	}
};

int main()
{
	char temp[50];
	cin >> temp;
	String1 s1(strlen(temp), temp);
	cout << temp;
	cin >> temp;
	String1 s2(strlen(temp), temp);
	s1.print();
	s1.concat(s2);
	s1.print();
	
	return 0;
}
	
