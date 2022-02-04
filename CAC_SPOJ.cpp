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
#include <array>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef long double ld;
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
const int MAXN = 100; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int V, E;
vi G[MAXN];
int F[MAXN]; unsigned long long H[MAXN];
bool VIS[MAXN];
vii EXTRA;

void dfs(int u = 0, int f = 0) {
    F[u] = f;
    VIS[u] = 1;
    for (auto v : G[u]) if (v != f) {
            if (VIS[v] && u > v)
                EXTRA.pb({u, v});
            else if (!VIS[v]) {
                H[v] = H[u] + 1;
                dfs(v, u);
            }
        }
}

int lca(int u, int v) {
    while (u != v) {
        if (H[u] > H[v])
            u = F[u];
        else
            v = F[v];
    }
    return u;
}

void solve() {
    rii(V, E);
    FOR(_, 0, E) {
        int a, b; rii(a, b);
        --a, --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs();

    unsigned long long ans = 1;
    for (auto [u, v] : EXTRA) 
        ans *= (H[u] + H[v] - 2 * H[lca(u, v)] + 1);
    printf("%llu\n", ans);

    FOR(i, 0, V) G[i].clear(), VIS[i] = 0;
    EXTRA.clear();
}



int main() {
    int t; ri(t);
    FOR(i, 1, t + 1) {
        printf("Case %d: ", i);
        solve();
    }
    return 0;
}