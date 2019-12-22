#include <stdio.h>

main()
{
	int t, n, c, q;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &c, &q);
		while (q--) {
			int l,r;
			scanf("%d %d", &l, &r);
			if (c >= l && c <= r) {
				int mid = (l+r)/2;
				if (c <= mid) {
					int dl = c-l;
					c = r - dl;
				}
				else {
					int dr = r-c;
					c = l + dr;
				}
			}
		}
		printf("%d\n", c);
	}
	return 0;
}
