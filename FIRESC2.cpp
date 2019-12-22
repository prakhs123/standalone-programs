#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;

#define MAXN	100000

int people[MAXN+10];
int status[MAXN+10];	
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int i, n, m;
		scanf("%d %d", &n, &m);
		for (i = 0; i < MAXN+10; i++) {
			people[i] = 0;
			status[i] = 1;
		}
		vector<int> V[n+1];
		while (m--) {
			int x, y;
			scanf("%d %d", &x, &y);
			V[x].push_back(y);
			V[y].push_back(x);
		}
		int k = 0;
		for (i = 1; i <= n; i++) {
			if (status[i] == 1) {
				queue<int> myq;
				myq.push(i);
				status[i] = 2;
				people[k]++;
				while (!myq.empty()) {
					int f = myq.front();
					myq.pop();
					status[f] = 3;
					int j, sz;
					sz = V[f].size();
					for (j = 0; j < sz; j++) {
						if (status[V[f][j]] == 1) {
							myq.push(V[f][j]);
							status[V[f][j]] = 2;
							people[k]++;
						}
					}
				}
				k++;
			}
		}
		long long ans = 1;
		for (i = 0; i < k; i++)
			ans = (ans*people[i]) % 1000000007;
		printf("%d %lld\n", k, ans);
	}
	return 0;
}
