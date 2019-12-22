#include <stdio.h>

main() {
	int T, S, N, M, K;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d %d", &S, &N, &M, &K);
		int p, i;
		p = M-1 < N-1 ? M-1: N-1;
		double ans = 0.0;
		for (i = K; i <= p; i++) {
			double temp = 1.0;
			double n1,n2,n3,r1,r2,r3;
			n1 = M-1;
			n2 = S-M;
			n3 = S-1;
			r1 = i;
			r2 = N-1-i;
			r3 = N-1;
			if (r1 > n1/2)
				r1 = n1 - r1;
			if (r2 > n2/2)
				r2 = n2 - r2;
			if (r3 > n3/2)
				r3 = n3 - r3;
			if (S-M >= N-1-i) {
				int flag1 = 0, flag2 = 0, flag3 = 0;
				if (r1 < 1)
					flag1 = 1;
				if (r2 < 1)
					flag2 = 1;
				if (r3 < 1)
					flag3 = 1;
				while (r1 >= 1 && r2 >= 1 && r3 >= 1) {
					temp *= n1/r1 * n2/r2 * r3/n3;
					r1 -= 1.0;
					n1 -= 1.0;
					r2 -= 1.0;
					n2 -= 1.0;
					r3 -= 1.0;
					n3 -= 1.0;
					if (r1 < 1)
						flag1 = 1;
					if (r2 < 1)
						flag2 = 1;
					if (r3 < 1)
						flag3 = 1;
				}
				if (flag1) {
					while (r2 >= 1 && r3 >= 1) {
						temp *= n2/r2 * r3/n3;
						r2 -= 1.0;
						n2 -= 1.0;
						r3 -= 1.0;
						n3 -= 1.0;
						if (r2 < 1)
							flag2 = 1;
						if (r3 < 1)
							flag3 = 1;
					}
					if (flag2) {
						while (r3 >= 1) {
							temp *= r3/n3;
							r3 -= 1.0;
							n3 -= 1.0;
						}
					}
					if (flag3) {
						while (r2 >= 1) {
							temp *= n2/r2;
							r2 -= 1.0;
							n2 -= 1.0;
						}
					}
				}
				else if (flag2) {
					while (r1 >= 1 && r3 >= 1) {
						temp *= n1/r1 * r3/n3;
						r1 -= 1.0;
						n1 -= 1.0;
						r3 -= 1.0;
						n3 -= 1.0;
						if (r1 < 1)
							flag1 = 1;
						if (r3 < 1)
							flag3 = 1;
					}
					if (flag1) {
						while (r3 >= 1) {
							temp *= r3/n3;
							r3 -= 1.0;
							n3 -= 1.0;
						}
					}
					if (flag3) {
						while (r1 >= 1) {
							temp *= n1/r1;
							r1 -= 1.0;
							n1 -= 1.0;
						}
					}
				}
				else if (flag3) {
					while (r1 >= 1 && r2 >= 1) {
						temp *= n1/r1 * n2/r2;
						r1 -= 1.0;
						n1 -= 1.0;
						r2 -= 1.0;
						n2 -= 1.0;
						if (r1 < 1)
							flag1 = 1;
						if (r2 < 1)
							flag2 = 1;
					}
					if (flag1) {
						while (r2 >= 1) {
							temp *= n2/r2;
							r2 -= 1.0;
							n2 -= 1.0;
						}
					}
					if (flag2) {
						while (r1 >= 1) {
							temp *= n1/r1;
							r1 -= 1.0;
							n1 -= 1.0;
						}
					}
				}
				ans += temp;
			}
		}
		printf("%.8f\n", ans);
	}
	return 0;
}
