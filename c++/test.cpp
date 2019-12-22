#include <iostream>
using namespace std;

class Father {
	double x;
	public:
	Father(double a)
	{
		x = a;
	}
	virtual void show()
	{
		cout << x << endl;
	}
};

class Son : public Father {
	int y;
	public:
	Son(int b, double c): Father(c)
	{
		y = b;
	}
	void show()
	{
		cout << y << endl;
	}
};

main()
{
	Father *ptr;
	Father ob1(9.9);
	ptr = &ob1;
	ptr->show();
	Son ob2(20,9.8);
	ptr = &ob2;
	ptr->show();
	
	return 0;
}
