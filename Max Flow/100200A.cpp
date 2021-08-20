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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
struct Dinic {
    int nodes, src, dst;
    vector<int> dist, q, work;
    struct edge {int to, rev; ll f, cap;};
    vector<vector<edge>> g, gi;
    Dinic(int x): nodes(x), dist(x), q(x), work(x), g(x), gi(x) {}
    void add_edge(int s, int t, ll cap) {
        g[s].pb((edge) {t, SZ(g[t]), 0, cap});
        g[t].pb((edge) {s, SZ(g[s]) - 1, 0, 0});
    }
    bool dinic_bfs() {
        fill(ALL(dist), -1); dist[src] = 0;
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
            fill(ALL(work), 0);
            while (ll delta = dinic_dfs(src, INF))result += delta;
        }
        return result;
    }

    int get_cut(int s) {
        queue<int> q;
        vector<bool> vis(nodes);
        int cnt = 0;
        q.push(s);
        vis[s] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cnt++;
            for (auto e : g[u]) {
                if (vis[e.to] || e.f == e.cap)
                    continue;
                vis[e.to] = 1;
                q.push(e.to);
            }
        }
        return cnt;
    }

    int get_cut_inv(int s) {
        FOR(i, 0, nodes) {
            for (auto e : g[i]) 
                gi[e.to].pb({i, e.rev, e.f, e.cap});
        }

        queue<int> q;
        vector<bool> vis(nodes);
        int cnt = 0;
        q.push(s);
        vis[s] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            cnt++;
            for (auto e : gi[u]) {
                if (vis[e.to] || e.f == e.cap)
                    continue;
                vis[e.to] = 1;
                q.push(e.to);
            }
        }
        return cnt;
    }
};


int main() {
    freopen("attack.in", "r", stdin);
    freopen("attack.out", "w", stdout);
    int n, m, s, t;
    rii(n, m); rii(s, t);
    Dinic mxf(n + 1);

    FOR(_, 0, m) {
        int a, b, c; riii(a, b, c);
        mxf.add_edge(a, b, c);
        mxf.add_edge(b, a, c);
    }
    
    mxf.max_flow(s, t);
    if (mxf.get_cut(s) + mxf.get_cut_inv(t) == n)
        printf("UNIQUE\n");
    else
        printf("AMBIGUOUS\n");

    return 0;
}