#include <cstdio>
#include <algorithm>
using namespace std;
main()
{
	int N, K, T;
	int W[105];
	int i;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &K);
		for (i = 0; i < N; i++)
			scanf("%d", &W[i]);
		int p = K < N-K ? K : N-K;
		sort(W,W+N);
		int S1, S2;
		S1 = S2 = 0;
		for (i = 0; i < p; i++)
			S1 += W[i];
		for (i = p; i < N; i++)
			S2 += W[i];
		printf("%d\n", S2-S1);
	}
	
	return 0;
}
