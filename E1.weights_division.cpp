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
int n;
ll s;
vii G[MAXN];
ll sum;
ll sz[MAXN];
ll w[MAXN];
priority_queue< pair<ll, ll> > pq;

void dfs(int x, int f = -1) {
    sz[x] = 0;
    bool is_leaf = true;
    for (auto y : G[x]) {
        if (y.F == f)
            continue;
        dfs(y.F, x);
        w[y.F] = y.S;

        sum += w[y.F] * sz[y.F];
        pq.push({w[y.F] * sz[y.F] - (w[y.F] / 2) * sz[y.F], y.F});

        is_leaf = false;
        sz[x] += sz[y.F];
    }

    sz[x] += is_leaf;
}

void solve() {
    ri(n); rl(s);
    FOR(i, 1, n) {
        int a, b, c; riii(a, b, c);
        G[a - 1].pb({b - 1, c});
        G[b - 1].pb({a - 1, c});
    }
    sum = 0;

    dfs(0);

    int ans = 0;
    while (sum > s) {
        auto p = pq.top(); pq.pop();
        sum -= w[p.S] * sz[p.S];
        w[p.S] >>= 1;
        sum += w[p.S] * sz[p.S];

        pq.push({w[p.S] * sz[p.S] - (w[p.S] / 2) * sz[p.S], p.S});
        ans++;
    }
    printf("%d\n", ans);
    while (!pq.empty())
        pq.pop();

    FOR(i, 0, n) {
        G[i].clear();
        sz[i] = w[i] = 0;
    }
}


int main() {
    int t; ri(t);
    while (t--)
        solve();
    return 0;
}