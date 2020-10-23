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

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 18; // CAMBIAR ESTE

// GJNM
int n, m, k;
ll a[MAXN], c[MAXN][MAXN];
ll dp[1 << MAXN][MAXN];


ll f(int bitmask, int prev, int count) {
    if (count == m)
        return 0;
    if (dp[bitmask][prev] != -1)
        return dp[bitmask][prev];

    ll &ret = dp[bitmask][prev];
    FOR(i, 0, n) {
        if (bitmask & (1 << i))
            continue;

        ret = max(ret, f(bitmask | (1 << i), i, count + 1) + a[i] + c[prev][i]);
    }
    return ret;
}



int main() {
    riii(n, m, k);
    FOR(i, 0, n) {
        rl(a[i]);
    }
    FOR(i, 0, k) {
        int xi, yi;
        rii(xi, yi);
        rl(c[xi - 1][yi - 1]);
    }
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    FOR(i, 0, n) {
        ans = max(ans, f(1 << i, i, 1) + a[i]);
    }
    printf("%lld\n", ans);

    return 0;
}