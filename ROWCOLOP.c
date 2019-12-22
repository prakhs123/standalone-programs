#include <stdio.h>
main()
{
	int N, Q, i, R[414159] = {0}, C[414159] = {0}, X;
	char s[100];
	scanf("%d %d", &N, &Q);
	int rm, cm;
	rm = cm = 0;
	while (Q--)
	{
		scanf("%s", s);
		scanf("%d %d", &i, &X);
		if (s[0] == 'R') {
			R[i] += X;
			if (R[i] > rm)
				rm = R[i];
		}
		else if (s[0] == 'C') {
			C[i] += X;
			if (C[i] > cm)
				cm = C[i];
		}
	}
	printf("%d\n", rm+cm);
	return 0;
}
