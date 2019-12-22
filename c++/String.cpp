#include <iostream>
#include <string.h>
using namespace std;

class String {
	int length;
	char *ptr;
public:
	String(int N, char s[]) {
		length = N;
		ptr = new char[length+1];
		strcpy(ptr, s);
	}
	String(int N) {
		ptr = new char[N];
	}
	void concat(String s2) {
		length = s2.length + length;
		strcat(ptr, s2.ptr);
		
	}
	void print(void)
	{
		cout<<ptr<<endl;
	}
};

int main()
{
	char temp[50];
	cin >> temp;
	String s1(strlen(temp), temp);
	cin >> temp;
	String s2(strlen(temp), temp);
	s1.print();
	s1.concat(s2);
	s1.print();
	
	return 0;
}
	
