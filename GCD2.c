#include <stdio.h>
#include <string.h>
main()
{
	int primes[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199};
	char B[250+1];
	int A,t,i,j,k,f[16],carry,answer;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %s", &A, B);
		if(A == 0) {
			printf("%s\n", B);
			continue;
		}
		j = 0;
		for (i = 0; A != 1 && i < 46; i++)
			if (A % primes[i] == 0) {
				f[j++] = primes[i];
				A = A / primes[i];
				while (A % primes[i] == 0) {
					f[j++] = primes[i];
					A = A / primes[i];
				}
			}
		if (A > 1)
			f[j++] = A;
		f[j] = -1;
		
		answer = 1;
		for (i = 0; f[i] != -1; i++) {
			carry = 0;
			k = 0;
			while (B[k] != '\0') {
				carry = carry * 10 + (B[k] - '0');
				carry = carry % f[i];
				k++;
			}
			if (carry == 0)
				answer *= f[i];
			else {
				j = f[i];
				while (f[i] == j)
					i++;
				i--;
			}
		}
		printf("%d\n", answer);
	}
	return 0;
}
		
		
