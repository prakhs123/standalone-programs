#include <stdio.h>
#define MOD	1000000007
#define ull unsigned long long
main()
{
	int T, N, K;
	int i;
	ull ans;	
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &K);
		ans = 0ull;
		for (i = 1; i <= N; i++) {
			if (K > i)
				continue;
			
