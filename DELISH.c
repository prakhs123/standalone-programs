#include <stdio.h>
#include <math.h>

#define MAXN	10000
#define ll long long

main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		int D[MAXN+5];
		scanf("%d", &N);
		int i;
		for (i = 0; i < N; i++)
			scanf("%d", &D[i]);
		ll MAX1[MAXN+5], MIN1[MAXN+5], MAX2[MAXN+5], MIN2[MAXN+5];
		ll sum1 = 0;
		ll sum2 = 0;
		ll max = -1;
		ll min = 1;
		int min_pos = 2000000000;
		int max_neg = -2000000000;
		for (i = 0; i < N-1; i++) {
			sum1 += (ll)D[i];
			sum2 += (ll)D[i];
			if (sum1 < 0)
				sum1 = 0;
			if (sum1 > max)
				max = sum1;
			if (max_neg < D[i])
				max_neg = D[i];
			if (max == 0)
				MAX1[i] = max_neg;
			else
				MAX1[i] = max;
			if (sum2 > 0)
				sum2 = 0;
			if (sum2 < min)
				min = sum2;
			if (min_pos > D[i])
				min_pos = D[i];
			if (min == 0)
				MIN1[i] = min_pos;
			else
				MIN1[i] = min;
		}
		sum1 = 0;
		sum2 = 0;
		max = -1;
		min = 1;
		max_neg = -2000000000;
		min_pos = 2000000000;
		for (i = N-1; i >= 1; i--) {
			sum1 += (ll)D[i];
			sum2 += (ll)D[i];
			if (sum1 < 0)
				sum1 = 0;
			if (sum1 > max)
				max = sum1;
			if (max_neg < D[i])
				max_neg = D[i];
			if (max == 0)
				MAX2[i] = max_neg;
			else
				MAX2[i] = max;
			if (sum2 > 0)
				sum2 = 0;
			if (sum2 < min)
				min = sum2;
			if (min_pos > D[i])
				min_pos = D[i];
			if (min == 0)
				MIN2[i] = min_pos;
			else
				MIN2[i] = min;
		}
		ll ans = -1;
		for (i = 0; i < N-1; i++) {
			if (fabs(MAX1[i]-MIN2[i+1]) > ans)
				ans = fabs(MAX1[i]-MIN2[i+1]);
			if (fabs(MAX2[i+1]-MIN1[i]) > ans)
				ans = fabs(MAX2[i+1]-MIN1[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
	
