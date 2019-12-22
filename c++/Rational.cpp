#include <iostream>
using namespace std;

class Rational {
	long numerator;
	long denominator;
	//void reduce (void);
	
	void reduce (void)
	{
		int a, b, rem, sign;
		
		if (numerator == 0)
			denominator = 1;
		sign = 1;
		
		if (numerator < 0 && denominator < 0) {
			numerator = -numerator;
			denominator = -denominator;
		}
		if (numerator < 0) {
			numerator = -numerator;
			sign = -1;
		}
		if (numerator > denominator) {
			a = numerator;
			b = denominator;
		}
		else {
			a = denominator;
			b = numerator;
		}
		while (b != 0) {
			rem = a % b;
			a = b;
			b = rem;
		}
		numerator = sign * numerator / a;
		denominator = denominator / a;
	}
	
public:
	/*Rational add(Rational);
	Rational mult(Rational);
	Rational divide(Rational);
	int equal(Rational);
	void print(void);
	void setrational(long, long);*/
	
	void setrational (long n, long d)
	{
		if (d == 0)
			cout << "ERROR: denominator may not be zero";
		numerator = n;
		denominator = d;
		reduce();
	}
	
	Rational add(Rational r)
	{
		int k, denom, num;
		Rational rnl;
		
		reduce();
		r.reduce();
		
		rnl.setrational(denominator, r.denominator);
		rnl.reduce();
		k = rnl.denominator;
		
		denom = denominator * k;
		
		num = numerator*k + r.numerator*(denom/r.denominator);
		
		rnl.setrational(num, denom);
		rnl.reduce();
		
		return rnl;
	}
	
	Rational add(long i)
	{
		Rational r;
		
		r.setrational(i, 1);
		return add(r);
	}
	
	Rational mult(Rational r)
	{
		Rational rnl, rnl1, rnl2;
		int num, denom;
		
		reduce();
		r.reduce();
		
		rnl1.setrational(numerator, r.denominator);
		rnl1.reduce();
		rnl2.setrational(r.numerator, denominator);
		rnl2.reduce();
		
		num = rnl1.numerator * rnl2.numerator;
		denom = rnl1.denominator * rnl2.denominator;
		rnl.setrational(num, denom);
		return rnl;
	}
	
	Rational divide(Rational r)
	{
		Rational rnl;
		
		rnl.setrational(r.denominator, r.numerator);
		
		return mult(rnl);
	}
	
	int equal(Rational r)
	{
		reduce();
		r.reduce();
		if (numerator == r.numerator && denominator == r.denominator)
			return 1;
		else
			return 0;
	}
	
	void print(void)
	{
		cout << numerator << "/" << denominator << endl;
	}
};

int main()
{
	int a, b, c, d;
	char opr;
	cin >> a >> b;
	cin >> opr;
	cin >> c >> d;
	Rational opnd1, opnd2, result;
	opnd1.setrational(a, b);
	opnd2.setrational(c, d);
	if (opr == '+')
		result = opnd1.add(opnd2);
	else if (opr == '*')
		result = opnd1.mult(opnd2);
	else if (opr == '/')
		result = opnd1.divide(opnd2);
	
	result.print();
	
	return 0;
}
