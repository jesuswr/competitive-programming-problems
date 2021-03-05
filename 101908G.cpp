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
const int MAXN = 1000; // CAMBIAR ESTE

// GJNM

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
};

struct EDGE {
    int from, to, time;

    bool operator<(const EDGE &other) {
        return time < other.time;
    }
};

int P, R, C;
int TOTP, TOTR;
EDGE E[200010];


int main() {
    riii(P, R, C);
    Dinic mxf(2 * MAXN + 3);
    int src = 2 * MAXN + 1, dst = 2 * MAXN + 2;
    FOR(i, 0, P) {
        int pi; ri(pi);
        TOTP += pi;
        mxf.add_edge(MAXN + i, dst, pi);
    }

    FOR(i, 0, R) {
        int ri; ri(ri);
        TOTR += ri;
        mxf.add_edge(src, i, ri);
    }
    FOR(i, 0, C) riii(E[i].to, E[i].from, E[i].time);
    sort(E, E + C);

    if (TOTR < TOTP) {
        printf("-1\n");
        return 0;
    }
    int cnt = 0;
    FOR(i, 0, C) {
        mxf.add_edge(E[i].from - 1, E[i].to - 1 + MAXN, LLINF);
        cnt += mxf.max_flow(src, dst);
        if (cnt == TOTP) {
            printf("%d\n", E[i].time);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}