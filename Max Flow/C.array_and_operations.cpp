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
#define SZ(s) (int)s.size()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 120; // CAMBIAR ESTE

// GJNM
int n, m;
int dinic_n = 1;
int a[MAXN];
vii div_a[MAXN]; // divisors and count of ai
vi div_n[MAXN];  // node id of the divs of ai in dinic

struct Dinic {
    int nodes, src, dst;
    vector<int> dist, q, work;
    struct edge {int to, rev; ll f, cap;};
    vector<vector<edge>> g;
    Dinic(int x): nodes(x), dist(x), q(x), work(x), g(x) {}
    void add_edge(int s, int t, ll cap) {
        g[s].pb((edge) {t, SZ(g[t]), 0, cap});
        g[t].pb((edge) {s, SZ(g[s]) - 1, 0, 0});
    }
    bool dinic_bfs() {
        fill(all(dist), -1); dist[src] = 0;
        int qt = 0; q[qt++] = src;
        for (int qh = 0; qh < qt; qh++) {
            int u = q[qh];
            FOR(i, 0, SZ(g[u])) {
                edge &e = g[u][i]; int v = g[u][i].to;
                if (dist[v] < 0 && e.f < e.cap)dist[v] = dist[u] + 1, q[qt++] = v;
            }
        }
        return dist[dst] >= 0;
    }
    ll dinic_dfs(int u, ll f) {
        if (u == dst)return f;
        for (int &i = work[u]; i < SZ(g[u]); i++) {
            edge &e = g[u][i];
            if (e.cap <= e.f)continue;
            int v = e.to;
            if (dist[v] == dist[u] + 1) {
                ll df = dinic_dfs(v, min(f, e.cap - e.f));
                if (df > 0) {e.f += df; g[v][e.rev].f -= df; return df;}
            }
        }
        return 0;
    }
    ll max_flow(int _src, int _dst) {
        src = _src; dst = _dst;
        ll result = 0;
        while (dinic_bfs()) {
            fill(all(work), 0);
            while (ll delta = dinic_dfs(src, INF))result += delta;
        }
        return result;
    }
};

int main() {
    rii(n, m);
    FOR(i, 0, n) {
        ri(a[i]);
        for (int j = 2; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                int cnt = 0;
                while (a[i] % j == 0) {
                    a[i] /= j;
                    cnt++;
                }
                div_a[i].pb({j, cnt});
            }
        }
        if (a[i] > 1)
            div_a[i].pb({a[i], 1});

        for (auto _ : div_a[i]) {
            div_n[i].pb(dinic_n++);
        }
    }

    Dinic dinic(dinic_n + 1);
    FOR(i, 0, n) {
        if (i & 1) {
            FOR(j, 0, div_a[i].size()) {
                dinic.add_edge(0, div_n[i][j], div_a[i][j].S);
            }
        }
        else {
            FOR(j, 0, div_a[i].size()) {
                dinic.add_edge(div_n[i][j], dinic_n, div_a[i][j].S);
            }
        }
    }

    FOR(_, 0, m) {
        int a, b;
        rii(a, b); a--, b--;
        if (b & 1)
            swap(a, b);
        int ai = 0, bi = 0;
        while (ai < div_a[a].size() && bi < div_a[b].size()) {
            if (div_a[a][ai].F == div_a[b][bi].F) {
                dinic.add_edge(div_n[a][ai], div_n[b][bi], 10000);
                ai++; bi++;
            }
            else if (div_a[a][ai] < div_a[b][bi])
                ai++;
            else
                bi++;
        }
    }

    printf("%lld\n", dinic.max_flow(0, dinic_n));


    return 0;
}