#include <stdio.h>
#include <stdlib.h>

#define X	5
#define Y	2
int find_no_of_digits(int n)
{
	int count = 0;
	while (n) {
		count++;
		n /= 10;
	}
	return count;
}
void printar(int **a, int m, int n) {
	int i, j, k, l;
	int temp1, temp2, temp3, temp4;
	int p, q;
	temp1 = m / X;
	temp2 = n / Y;
	temp3 = X;
	temp4 = Y;
	p = 0;
	q = 0;
	int digitsCOL = find_no_of_digits(n);
	int digitsROW = find_no_of_digits(m);
	
	//for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
			printf("%d ", a[0][j]);
	//	putchar('\n');
	//}
	/*for (i = 0; i <= temp1; i++, p = temp3, temp3 += X)
		for (j = 0; j <= temp2; j++, q = temp4, temp4 += Y) {
			k = q;
			while (k < temp4) {
				if (k == q) {
					l = digitsROW;
					printf("    ");
					while (l) {
						putchar(' ');
						l /= 10;
					}
					printf(" ");
				}
				printf("COL %.*d ", digitsCOL, k);
				k++;
			}
			putchar('\n');
			while (p < temp3) {
				printf("ROW %.*d ", digitsROW, p);
				l = 4 + digitsCOL;
				while (q < temp4 && q < n && p < m) {
					printf("%.*d ", l, a[p][q]);
					q++;
				}
				putchar('\n');
				p++;
			}
		}
	*/
}

main()
{
	int m, n;
	int i, j;
	scanf("%d %d", &m, &n);
	int **a;
	a = (int **) malloc(sizeof(int) * m);
	for (i = 0; i < m; i++) {
		a[i] = malloc(sizeof(int) * n);
	}
	for(i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	for (j = 0; j < n; j++)
			printf("%d ", a[0][j]);
	putchar('\n');
	printar(a, m, n);
	
	return 0;
}
