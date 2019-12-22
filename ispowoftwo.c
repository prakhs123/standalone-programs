#include <stdio.h>

int ispowoftwo(int x) {
	return __builtin_popcount(x) == 1 ? 1 : 0;
}
int main() {
	int num;
	scanf("%d", &num);
	printf("%d\n", ispowoftwo(num));
	return 0;
}