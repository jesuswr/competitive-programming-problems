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
const int MAXN = 1e5 + 69; // CAMBIAR ESTE
const int LOGN = 22;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M;
vii G[MAXN];
bool V[MAXN];
vi run_d;

ll H[MAXN];
int ANC[MAXN][LOGN];
int tin[MAXN], tout[MAXN], t;
void pre(int u, int f = 0) {
    V[u] = 1;
    ANC[u][0] = f;
    tin[u] = t++;
    FOR(l, 1, LOGN) ANC[u][l] = ANC[ ANC[u][l - 1] ][l - 1];
    for (auto [v, c] : G[u]) if (v != f) {
            if (V[v])
                run_d.pb(v);
            else {
                H[v] = H[u] + c;
                pre(v, u);
            }
        }
    tout[u] = t++;
}

bool is_ancestor(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }
int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = LOGN - 1; i >= 0; --i) {
        if (!is_ancestor(ANC[u][i], v)) {
            u = ANC[u][i];
        }
    }
    return ANC[u][0];
}

vector<vector<ll>> dsts;
vector<ll> dijkstra(int s) {
    vector<ll> d(N, LLINF);
    priority_queue<pair<ll, int>> pq;
    pq.push({0, s}); d[s] = 0;
    while (!pq.empty()) {
        auto [cst, u] = pq.top(); pq.pop();
        cst = -cst;
        if (cst != d[u])
            continue;
        for (auto [v, e] : G[u]) {
            if (d[u] + e < d[v]) {
                d[v] = d[u] + e;
                pq.push({ -d[v], v});
            }
        }
    }
    return d;
}



int main() {
    rii(N, M);
    FOR(i, 0, M) {
        int a, b, c; riii(a, b, c); --a, --b;
        G[a].pb({b, c});
        G[b].pb({a, c});
    }
    pre(0);
    for (auto u : run_d) dsts.pb(dijkstra(u));
    int q; ri(q);
    while (q--) {
        int a, b; rii(a, b); --a, --b;
        ll ans = H[a] + H[b] - 2 * H[lca(a, b)];
        for (vector<ll> &d : dsts) {
            ans = min(ans, d[a] + d[b]);
        }
        printf("%lld\n", ans);
    }

    return 0;
}