#include <stdio.h>
#define ull unsigned long long
main()
{
	int T;
	ull N;
	scanf("%d", &T);
	while (T--) {
		scanf("%llu", &N);
		if (N && (!(N&(N-1))))
			printf("No\n");
		else
			printf("Yes\n");
	}
	
	return 0;
}
