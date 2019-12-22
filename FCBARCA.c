#include <stdio.h>

#define MOD	1000000007

main()
{
	int T, N, K;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &K);
		long long ans1 = 1ll;
		long long ans2 = 1ll;
		long long ans = 0ll;
		// when messi is not in the passes
		int i, flag = 0;
		ans1 = (ans1 * K) % MOD;
		for (i = 2; i <= N-1; i++)
			ans1 = (ans1 * (K-1)) % MOD;
		// when messi is passing
		if (N >= 4) {
			flag = 1;
			ans2 = (ans2 * K) % MOD;
			ans2 = (ans2 * K) % MOD;
			for (i = 1; i <= N-4; i++)
				ans2 = (ans2 * (K-1)) % MOD;
			ans2 = (ans2 * (N-3)) % MOD;
		}
		if (flag)
			ans = (ans1 + ans2) % MOD;
		else
			ans = ans1;
		printf("%lld\n", ans);
	}
	
	return 0;
}		
