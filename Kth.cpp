#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

#define MAXP 100000
#define MAXG 10000000

vector<int> group[MAXP+10];
vector<int> children[MAXP+10];
int path[MAXP+10];
int groupNo[MAXG];
int dist[MAXP+10];
int parent[MAXP+10];
int rootnode;
int gNo;

void removeNode(int from, int X) {
    vector<int> :: iterator it;
    for (it = children[from].begin(); it != children[from].end(); it++) {
        if (*it == X) {
            break;
        }
    }
    children[from].erase(it);
}
void copyGroup(int from, int to, int X) {
    for (vector<int> :: iterator it = group[from].begin(); *it != X; it++) {
        group[to].push_back(*it);
    }
    group[to].push_back(X);
}
void copyPath(int max) {
    for (int i = 0; i < max; i++) {
        group[gNo].push_back(path[i]);
        if (groupNo[path[i]] == -1) {
            groupNo[path[i]] = gNo;
            dist[path[i]] = i;
        }
    }
}
void makeGroup(int node, int index) {
    path[index] = node;
    index++;
    if (children[node].size() == 0) {
        copyPath(index);
        gNo++;
    }
    else
        for (vector<int> :: iterator it = children[node].begin(); it != children[node].end(); it++) {
            makeGroup(*it, index);
        }
}

int main() {
    int T, P, Q, X, Y, K, q;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &P);
        for (int i = 0; i < MAXP+10; i++) {
            group[i].clear();
            children[i].clear();
            groupNo[i] = -1;
            parent[i] = -1;
        }
        gNo = 0;
        for (int i = 0; i < P; i++) {
            scanf("%d %d", &X, &Y);
            if (Y) {
                parent[X] = Y;
                children[Y].push_back(X);
            }
            else
                rootnode = X;
        }
        makeGroup(rootnode, 0);
        printf("%d\n", gNo);
        scanf("%d", &Q);
        for (int  i = 0; i < Q; i++) {
            scanf("%d", &q);
            if (q == 2) {
                scanf("%d %d", &X, &Y);
                if (groupNo[X] == -1) {
                    printf("0\n");
                    continue;
                }
                K = dist[X] - Y;
                if (K >= 0) {
                    printf("%d\n", group[groupNo[X]][K]);
                }
                else
                    printf("0\n");
            }
            else if (q == 1) {
                scanf("%d", &X);
                if (groupNo[X] != -1) {
                    removeNode(parent[X], X);
                    group[groupNo[X]].pop_back();
                    groupNo[X] = -1;
                    parent[X] = -1;
                }
            }
            else if (q == 0) {
                scanf("%d %d", &X, &Y);
                if (children[X].size() == 0) {
                    children[X].push_back(Y);
                    group[groupNo[X]].push_back(Y);
                    groupNo[Y] = groupNo[X];
                    parent[Y] = X;
                    dist[Y] = (int)group[groupNo[X]].size() - 1;
                }
                else {
                    copyGroup(groupNo[X], gNo, X);
                    children[X].push_back(Y);
                    group[gNo].push_back(Y);
                    groupNo[Y] = gNo;
                    parent[Y] = X;
                    dist[Y] = (int)group[gNo].size() - 1;
                    gNo++;
                }
            }
        }
    }
}