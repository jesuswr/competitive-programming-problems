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
const int MAXN = 4e5; // CAMBIAR ESTE

// GJNM
int n, x;
ll a[MAXN];
ll dp[3][MAXN];

ll f(int mode, int pos) {
    if (pos == n)
        return 0;
    if (dp[mode][pos] != -1)
        return dp[mode][pos];
    ll &ret = dp[mode][pos];

    if (mode == 0) {
        ret = max(ret, a[pos] + f(mode, pos + 1));
        ret = max(ret, a[pos] + f(mode + 1, pos + 1));
    }
    else if (mode == 1) {
        ret = max(ret, a[pos] * x + f(mode, pos + 1));
        ret = max(ret, a[pos] * x + f(mode + 1, pos + 1));
    }
    else {
        ret = max(ret, a[pos] + f(mode, pos + 1));
    }

    return ret = max(ret, 0ll);
}

int main() {
    rii(n, x);
    FOR(i, 0, n) rl(a[i]);
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    FOR(i, 0, n) ans = max(ans, max(f(0, i), f(1, i)));
    printf("%lld\n", ans);

    return 0;
}