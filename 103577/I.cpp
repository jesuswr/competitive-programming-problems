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
#define ms(obj,val) memset(obj,val,sizeof(obj))

const int INF = 1e8;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
typedef int tf;
typedef int tc;
const tf INFFLOW = 1e8;
const tc INFCOST = 1e8;
struct MCF {
    int n;
    vector<tc> prio, pot; vector<tf> curflow; vector<int> prevedge, prevnode;
    priority_queue<pair<tc, int>, vector<pair<tc, int>>, greater<pair<tc, int>>> q;
    struct edge {int to, rev; tf f, cap; tc cost;};
    vector<vector<edge>> g;
    MCF(int _n): n(_n), prio(_n), pot(_n), curflow(_n), prevedge(_n), prevnode(_n), g(_n) {}

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

int MAT[510][510];
int MN1[510], MN2[510];
void mn(int &a, int b) {
    a = min(a, b);
}

int main() {
    int n, m; rii(n, m);
    FOR(i, 0, n) {
        FOR(j, 0, n) MAT[i][j] = INF;
        MN1[i] = MN2[i] = INF;
    }
    FOR(_, 0, m) {
        int a, b, c; riii(a, b, c);
        mn(MAT[a][b], c);
        mn(MN1[a], c);
        mn(MN2[b], c);
    }

    FOR(i, 0, n) if (max(MN1[i], MN2[i]) == INF) {
        printf("Impossible\n");
        return 0;
    }

    int s = 2 * n, t = 2 * n + 1;
    MCF mcf(2 * n + 2);
    FOR(i, 0, n) {
        mcf.add_edge(s, i, 1, 0);
        mcf.add_edge(n + i, t, 1, 0);
        FOR(j, 0, n) {
            printf("%d -> %d : %d\n", i, j, min(MAT[i][j], MN1[i] + MN2[j]));
            mcf.add_edge(i, n + j, 1, min(MAT[i][j], MN1[i] + MN2[j]));
        }
    }
    printf("%d\n", mcf.get_flow(s, t).S );
    return 0;
}