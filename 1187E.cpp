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
const int MAXN = 2e5 + 1; // CAMBIAR ESTE

// GJNM
int n;
vi G[MAXN];
ll SZ[MAXN], DP[MAXN];
ll ans;

void dfs_pre(int x, int f = -1) {
    SZ[x] = 1;
    for (auto y : G[x]) {
        if (y == f) continue;
        dfs_pre(y, x);
        SZ[x] += SZ[y];
        DP[x] += DP[y];
    }
    DP[x] += SZ[x];
}

void dfs(int x, int f = -1) {
    ans = max(ans, DP[x]);
    for (auto y : G[x]) {
        if (y == f) continue;
        DP[x] -= DP[y];
        DP[x] -= SZ[y];
        SZ[x] -= SZ[y];
        DP[y] += DP[x];
        DP[y] += SZ[x];
        SZ[y] += SZ[x];

        dfs(y, x);

        DP[y] -= DP[x];
        DP[y] -= SZ[x];
        SZ[y] -= SZ[x];
        DP[x] += DP[y];
        DP[x] += SZ[y];
        SZ[x] += SZ[y];
    }
}

int main() {
    ri(n);
    FOR(_, 1, n) {
        int a, b; rii(a, b); a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs_pre(0);

    dfs(0);

    printf("%lld\n", ans);

    return 0;
}