#include <stdio.h>
#include <stdbool.h>

#define N	100000
#define MOD	1000000007
int firedoor[N+1];
int no_of_people[N+1];
int change[N+1];

main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		int i, j;
		for (i = 0; i <= N; i++) {
			firedoor[i] = -1;
			no_of_people[i] = 0;
			change[i] = -1;
		}
		int k = 0;
		int counter = 0;
		while (m--) {
			scanf("%d %d", &i, &j);
			if (firedoor[i] == -1 && firedoor[j] == -1) {
				firedoor[i] = k;
				firedoor[j] = k;
				no_of_people[k] += 2;
				k++;
				counter++;
			}
			else if (firedoor[i] == -1) {
				int k1 = firedoor[j];
				while (change[k1] != -1)
					k1 = change[k1];
				firedoor[i] = k1;
				no_of_people[k1]++;
			}
			else if (firedoor[j] == -1) {
				int k1 = firedoor[i];
				while (change[k1] != -1)
					k1 = change[k1];
				firedoor[j] = k1;
				no_of_people[k1]++;
			}
			else {
				int k1,k2;
				k1 = firedoor[i];
				while (change[k1] != -1)
					k1 = change[k1];
				k2 = firedoor[j];
				while (change[k2] != -1)
					k2 = change[k2];
				if (k1 != k2) {
					if (no_of_people[k1] > no_of_people[k2]) {
						no_of_people[k1] += no_of_people[k2];
						counter--;
						change[k2] = k1;
						no_of_people[k2] = 0;
					}
					else {
						no_of_people[k2] += no_of_people[k1];
						counter--;
						change[k1] = k2;
						no_of_people[k1] = 0;
					}
				}
			}
		}
		for (i = 1; i <= n; i++)
			if (firedoor[i] == -1) {
				no_of_people[k]++;
				k++;
				counter++;
			}
		int ans = 1;
		for (i = 0; i < k; i++)
			if (no_of_people[i] != 0)
				ans = (ans * no_of_people[i]) % MOD;
		printf("%d %d\n", counter, ans);
	}
	
	return 0;
}
