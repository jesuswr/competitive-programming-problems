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
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int)s.size()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 55; // CAMBIAR ESTE

// GJNM
int n, q;

typedef ll tf;
typedef ll tc;
const tf INFFLOW = 1e9;
const tc INFCOST = 1e9;
struct MCF {
    int n;
    vector<tc> prio, pot; vector<tf> curflow; vector<int> prevedge, prevnode;
    priority_queue<pair<tc, int>, vector<pair<tc, int>>, greater<pair<tc, int>>> q;
    struct edge {int to, rev; tf f, cap; tc cost;};
    vector<vector<edge>> g;
    MCF(int n): n(n), prio(n), curflow(n), prevedge(n), prevnode(n), pot(n), g(n) {}
    void add_edge(int s, int t, tf cap, tc cost) {
        g[s].pb((edge) {t, SZ(g[t]), 0, cap, cost});
        g[t].pb((edge) {s, SZ(g[s]) - 1, 0, 0, -cost});
    }
    pair<tf, tc> get_flow(int s, int t) {
        tf flow = 0; tc flowcost = 0;
        while (1) {
            q.push({0, s});
            fill(ALL(prio), INFCOST);
            prio[s] = 0; curflow[s] = INFFLOW;
            while (!q.empty()) {
                auto cur = q.top();
                tc d = cur.F;
                int u = cur.S;
                q.pop();
                if (d != prio[u]) continue;
                for (int i = 0; i < SZ(g[u]); ++i) {
                    edge &e = g[u][i];
                    int v = e.to;
                    if (e.cap <= e.f) continue;
                    tc nprio = prio[u] + e.cost + pot[u] - pot[v];
                    if (prio[v] > nprio) {
                        prio[v] = nprio;
                        q.push({nprio, v});
                        prevnode[v] = u; prevedge[v] = i;
                        curflow[v] = min(curflow[u], e.cap - e.f);
                    }
                }
            }
            if (prio[t] == INFCOST) break;
            FOR(i, 0, n) pot[i] += prio[i];
            tf df = min(curflow[t], INFFLOW - flow);
            flow += df;
            for (int v = t; v != s; v = prevnode[v]) {
                edge &e = g[prevnode[v]][prevedge[v]];
                e.f += df; g[v][e.rev].f -= df;
                flowcost += df * e.cost;
            }
        }
        return {flow, flowcost};
    }
};

int lo[MAXN], hi[MAXN];


int main() {
    rii(n, q);
    FOR(i, 0, n) {
        lo[i] = 0;
        hi[i] = n - 1;
    }
    FOR(i, 0, q) {
        int t, l, r, v; rii(t, l), rii(r, v); l--, r, v--;
        FOR(j, l, r) {
            if (t == 1) {
                lo[j] = max(lo[j], v);
            } else {
                hi[j] = min(hi[j], v);
            }
            if (lo[j] > hi[j]) {
                printf("-1\n");
                return 0;
            }
        }
    }

    MCF mcf(2 * n + 2);
    int s = 2 * n, t = 2 * n + 1;

    FOR(i, 0, n) {
        FOR(j, lo[i], hi[i] + 1) {
            mcf.add_edge(i, n + j, 1, 0);
        }
        mcf.add_edge(s, i, 1, 0);
    }

    FOR(i, 0, n) {
        int curr = 1;
        FOR(j, 0, n) {
            mcf.add_edge(i + n, t, 1, curr);
            curr += 2;
        }
    }

    auto ans = mcf.get_flow(s, t);
    printf("%lld\n",ans.S);

    return 0;
}