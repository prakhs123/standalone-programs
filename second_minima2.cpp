#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

bool isPowerOfTwo (int x)
{
  /* First x in the below expression is for the case when x is 0 */
  return x && (!(x&(x-1)));
}
// modified
int log_2(unsigned int n) {
	int bits = 0;
	if (!isPowerOfTwo(n))
		bits++;
	if (n > 32767) {
 		n >>= 16;
		bits += 16;
	}
	if (n > 127) {
		n >>= 8;
		bits += 8;
	}
	if (n > 7) {
		n >>= 4;
		bits += 4;
	}
	if (n > 1) {
		n >>= 2;
		bits += 2;
	}
	if (n > 0) {
		bits++;
	}
	return bits;
}

int second_minima(int a[],unsigned int n) {
	int log_2n = log_2(n);
	int **p = new int* [log_2n];
	int i, j, k;
	for (i = 0, j = n; i < log_2n; i++) {
		p[i] = new int[j];
		j = j&1 ? j/2+1 : j/2;
	}
	for (i = 0; i < n; i++)
		p[0][i] = a[i];
	for (i = 1, j = n; i < log_2n; i++) {
		for (k = 0; k+1 < j; k += 2) {
			if (p[i-1][k] < p[i-1][k+1])
				p[i][k/2] = p[i-1][k];
			else
				p[i][k/2] = p[i-1][k+1];
		}
		if (j&1)
			p[i][j/2] = p[i-1][j-1];
		j = j&1 ? j/2+1 : j/2;
	}
	for (i = 0, j = n; i < log_2n; i++) {
		for (k = 0; k < j; k++)
			printf("%d ",p[i][k]);
		printf("\n");
		j = j&1 ? j/2+1 : j/2;
	}
	return 0;
}

int main()
{
	unsigned int n;
	scanf("%u", &n);
	int a[n];
	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	second_minima(a,n);
	return 0;
}
