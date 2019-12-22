#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		map <int, int> idc;
		vector <unsigned long long> V[100005];
		int N;
		unsigned long long B, L;
		scanf("%d", &N);
		int id = 1;
		while (N--) {
			scanf("%llu %llu", &B, &L);
			if (!idc[B]) {
				idc[B] = id;
				V[id].push_back(L);
				id++;
			}
			else {
				int k = idc[B];
				V[k].push_back(L);
			}
		}
		
		for (int i = 1; i < id; i++)
			sort(V[i].begin(), V[i].end());
		
		unsigned long long ans = 0ull;
		unsigned long long first[100005];
		for (int i = 1; i < id; i++)
			first[i] = V[i][0];
		
		sort(first+1, first+id);
		
		for (int i = 1; i < id; i++)
			ans += i * first[i];
		
		for (int i = 1; i < id; i++)
			for (vector<unsigned long long>::iterator it = V[i].begin() + 1; it != V[i].end(); it++)
				ans += (unsigned long long)(id-1) * *it;
		
		printf("%llu\n", ans);
	}
	return 0;
}
