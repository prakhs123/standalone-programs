#include <stdio.h>

main()
{
	int T, N, M, nr, dr, i;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &N, &M);
		nr = 1;
		dr = 1;
		for (i = 1; i <= N-1; i++) {
			nr = (nr + dr)%M;
			dr = (nr + dr)%M;
		}
		printf("%d/%d\n", nr%M, dr%M);
	}
	
	return 0;
}
