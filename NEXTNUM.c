#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<complex>
#include<string>
#include<utility>
#include<numeric>
#include<iterator>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<climits>
#include<ctime>
#include<cstring>

#define ALL(c)  c.begin(), c.end()
#define TR(c, it)   for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define FOR(i, j, n)  for(int (i) = (j); i < n; i++)
#define MAX(a, b)   ((a) > (b) ? (a) : (b))
#define gc  getchar_unlocked
#define ll long long int
#define ull unsigned long long int
#define inf INT_MAX
#define mininf INT_MIN
#define pb push_back
#define mp  make_pair
#define time   QueryPerformanceCounter
#define qp  QuadPart
#define LI LARGE_INTEGER
#define PI  3.14159265358979323846264338327950288

using namespace std;

ll fact[20];

//inline void sfast(char *str)
//{
//    register char c = 0;
//    register int i = 0;
//    while (c < 33)
//        c = gc();
//
//    while(c >= '0' && c <= '9')
//    {
//        str[i] = c;
//        c = gc();
//        i = i + 1;
//    }
//    str[i] = '\0';
//}

ll rank(char *str)
{
    ll ans = 0, d = 1;
    int freq[10] = {0}, len = strlen(str);
    for(int i = len-1; i >= 0; --i)
    {
        freq[str[i] - '0']++;
        d *= freq[str[i] - '0'];
        for(int j = 0; j < str[i] - '0'; j++)
            if(freq[j] > 0)
                ans += fact[len - i - 1]/(d/freq[j]);
    }
    return ans;
}

int main()
{
    fact[0] = 1;
    FOR(i, 1, 20)
        fact[i] = fact[i-1] * i;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        char str[20];
//        sfast(str);
        scanf("%s", str);
        printf("%lld\n", rank(str)+1);
    }
    return 0;
}