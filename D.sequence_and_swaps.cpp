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
#include <assert.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

int dadsadasda;

#define ri(a) dadsadasda=scanf("%d", &a)
#define rii(a,b) dadsadasda=scanf("%d %d", &a, &b)
#define riii(a,b,c) dadsadasda=scanf("%d %d %d", &a, &b, &c)
#define rl(a) dadsadasda=scanf("%lld", &a)
#define rll(a,b) dadsadasda=scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int)s.size()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int n, x;
ll dp[510][510][2]; // (pos, x, need change)
int a[MAXN];

ll f(int pos, int xx, int change) {
    if (pos == n)
        return 0;
    if (dp[pos][xx][change] != -1)
        return dp[pos][xx][change];
    ll &ret = dp[pos][xx][change] = LLINF;

    if (change) {
        if (xx >= a[pos]) return ret;

        if (a[pos + 1] >= xx)
            ret = 1 + f(pos + 1, a[pos], 0);
        if (a[pos] >= xx)
            ret = min(ret, 1 + f(pos + 1, a[pos], 1));
    }
    else {
        if (a[pos + 1] >= a[pos])
            ret = f(pos + 1, xx, 0);
        if (xx >= a[pos])
            ret = min(ret, f(pos + 1, xx, 1));
    }
    return ret;
}

void solve() {
    rii(n, x);
    int mx = x;
    FOR(i, 0, n) {
        ri(a[i]);
        mx = max(mx, a[i]);
    }
    a[n] = 2000;
    FOR(i, 0, n + 2) {
        FOR(j, 0, mx + 2) {
            dp[i][j][1] = dp[i][j][0] = -1;
        }
    }
    ll ans = f(0, x, 0);
    if (a[0] > x)
        ans = min(f(0, x, 1), ans);
    if (ans >= LLINF)
        printf("-1\n");
    else
        printf("%lld\n", ans);
}

int main() {
    int t;
    ri(t);
    while (t--)
        solve();
    return 0;
}