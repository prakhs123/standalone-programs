#define V 20
typedef pair<int, int> ii;
vector<ii> G[V];
int D[V];

void dijkstra(int s)
{
    for (int i = 0; i < V; i++) {
        D[i] = INT_MAX;
    }
    D[s] = 0;
    set<ii> Q;
    Q.insert(ii(0,s));
    while (!Q.empty()) {
        int u = Q.begin()->second;
        Q.erase(Q.begin());
        for (vector<ii> :: iterator it = G[u].begin(); it != G[u].end(); it++) {
            int v = it->first;
            int w = it->second;
            if (D[v] > D[u] + w) {
                if (D[v] != INT_MAX) {
                    Q.erase(Q.find(ii(D[v],v)));
                }
                D[v] = D[u] + w;
                Q.insert(ii(D[v],v));
            }
        }
    }
}