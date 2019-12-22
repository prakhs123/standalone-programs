//
//  main.cpp
//  TOURMAP2
//
//  Created by Prakhar Jain on 14/08/13.
//  Copyright (c) 2013 Prakhar Jain. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <ctime>
#include <limits>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <list>
#include <deque>
#include <algorithm>

#define LL  long long
#define MOD 1000000007

using namespace std;

struct card {
    string c1, c2;
    int cost;
} cards[5555];

struct cit {
    string c;
    int index;
} city[5555];

bool mysort(pair<string, int> p1, pair<string, int> p2) {
    return p1.first == p2.first ? p1.second < p2.second : p1.first < p2.first;
}

int binsearch(struct cit a[], int low, int high, string x) {
    while (low <= high) {
        int mid = (low+high)/2;
        if (a[mid].c == x) {
            return a[mid].index;
        }
        else if (x < a[mid].c)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main(int argc, const char * argv[])
{
    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < 5555; ++i)
        {
            cards[i].c1 = cards[i].c2 = city[i].c = "";
            city[i].index = cards[i].cost = -1;
        }
        vector<pair<string, int> > temp;
        int totalCost = 0;
        for (int i = 0; i < N-1; i++) {
            char s1[55], s2[55];
            scanf("%s %s %d$", s1, s2, &cards[i].cost);
            cards[i].c1 = s1;
            cards[i].c2 = s2;
            pair<string, int> p1, p2;
            p1 = make_pair(cards[i].c1, i);
            p2 = make_pair(cards[i].c2, -1);
            temp.push_back(p1);
            temp.push_back(p2);
            totalCost += cards[i].cost;
        }
        sort(temp.begin(), temp.end(), mysort);
        string s1, s2;
        int i = 0;
        for (vector<pair<string, int> > :: iterator it = temp.begin(); it != temp.end(); it++, i++) {
            if ((*it).first == (*(it+1)).first) {
                it++;
                city[i].c = (*it).first;
                city[i].index = (*it).second;
            }
            else {
                if (!s1.size()) {
                    s1 = (*it).first;
                }
                else {
                    s2 = (*it).first;
                }
                city[i].c = (*it).first;
                city[i].index = (*it).second;
            }
        }
        int n = i-1;
        string start;
        //cout << s1 << ' ' << s2 << endl;
        for (i = 0; i < N-1; i++) {
            if (cards[i].c1 == s1 || cards[i].c1 == s2) {
                break;
            }
        }
        if (s1 == cards[i].c1) {
            start = s1;
        }
        else
            start = s2;
        
        for (int i = 0; i < N-1; i++) {
            int j = binsearch(city, 0, n, start);
            printf("%s %s %d$\n", cards[j].c1.c_str(), cards[j].c2.c_str(), cards[j].cost);
            start = cards[j].c2;
        }
        printf("%d$\n", totalCost);
    }
    return 0;
}