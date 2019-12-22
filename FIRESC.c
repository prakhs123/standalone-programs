#include <stdio.h>
#include <stdbool.h>

#define N	100000
#define MOD	1000000007
int firedoor[N+1];
bool seen[N+1];
int no_of_people[N+1];

main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		int i, j;
		for (i = 0; i <= n; i++) {
			firedoor[i] = -1;
			seen[i] = false;
			no_of_people[i] = 0;
		}
		int k = 0;
		while (m--) {
			scanf("%d %d", &i, &j);
			seen[i] = seen[j] = true;
			if (firedoor[i] == -1 && firedoor[j] == -1) {
				firedoor[i] = k;
				firedoor[j] = k;
				no_of_people[k] += 2;
				k++;
			}
			else if (firedoor[i] == -1) {
				firedoor[i] = firedoor[j];
				no_of_people[firedoor[i]]++;
			}
			else if (firedoor[j] == -1) {
				firedoor[j] = firedoor[i];
				no_of_people[firedoor[j]]++;
			}
		}
		for (i = 1; i <= n; i++)
			if (seen[i] == false) {
				no_of_people[k]++;
				k++;
			}
		int ans = no_of_people[0];
		for (i = 1; i < k; i++)
			ans = (ans * no_of_people[i]) % MOD;
		printf("%d %d\n", k, ans);
	}
	
	return 0;
}
