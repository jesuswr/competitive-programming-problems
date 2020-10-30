#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define all(s) s.begin(),s.end()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
struct help {
    int d, s, pos;
};

bool comp(help &a, help &b) {
    if ((a.d - a.s) == (b.d - b.s))
        return a.s < b.s;
    return (a.d - a.s) > (b.d - b.s);
}

help a[MAXN];
int n, c;

int dp[501][MAXN];
int nxt[501][MAXN];
bool vis[501][MAXN];

int f(int pos, int lft) {
    if (pos == n)
        return 0;
    if (vis[pos][lft])
        return dp[pos][lft];
    vis[pos][lft] = true;

    int &ret = dp[pos][lft];
    int &next = nxt[pos][lft];

    ret = f(pos + 1, lft);
    next = lft;

    if (lft >= max(a[pos].d, a[pos].s)) {
        int old_ret = ret;
        ret = max(ret, f(pos + 1, lft - a[pos].s) + 1);
        if (ret != old_ret)
            next = lft - a[pos].s;
    }

    return dp[pos][lft];
}


int main() {
    rii(n, c);
    FOR(i, 0, n) {
        rii(a[i].d, a[i].s);
        a[i].pos = i;
    }
    sort(a, a + n, comp);
    int ans = f(0, c);
    printf("%d\n", ans);
    if (ans == 0)
        return 0;
    int curr_p = 0, curr_c = c;
    while (curr_p != n && curr_c > 0) {
        if (nxt[curr_p][curr_c] != curr_c) {
            printf("%d ", a[curr_p].pos + 1);
        }
        curr_c = nxt[curr_p][curr_c];
        curr_p++;
    }
    printf("\n");
    return 0;
}