#include <iostream>
#include <vector>

using namespace std;


int main() {
	double fact = 1.0;
	for (int i = 100; i >= 1; i--)
		fact = fact*(double)i;
	printf("%.0f\n", fact);
	return 0;
}