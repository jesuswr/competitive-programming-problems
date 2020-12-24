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
const int MAXN = 2e5; // CAMBIAR ESTE

// GJNM
vector<int> G[MAXN], CT[MAXN]; int n, m, d;
bool tk[MAXN]; // already selected as a centroid
int fat[MAXN]; // father in centroid decomposition
int szt[MAXN]; // size of subtree
int calcsz(int x, int f) {
    szt[x] = 1;
    for (auto y : G[x])if (y != f && !tk[y])szt[x] += calcsz(y, x);
    return szt[x];
}
void cdfs(int x = 0, int f = -1, int sz = -1) { // O(nlogn)
    if (sz < 0)sz = calcsz(x, -1);
    for (auto y : G[x])if (!tk[y] && szt[y] * 2 >= sz) {
            szt[x] = 0; cdfs(y, f, sz); return;
        }
    tk[x] = true; fat[x] = f; if (f != -1) CT[f].pb(x);
    for (auto y : G[x])if (!tk[y])cdfs(y, x);
}
void centroid() {memset(tk, false, sizeof(tk)); cdfs();}

const int l = 23; // l = log(n)

int timer; // Tiempos de entrada y salida de cada nodo y su ancestro a dist 2**i
int tin[MAXN], tout[MAXN], anc[MAXN][ l + 1 ];
int h[MAXN];
void dfs_lca(int v, int p) { // Se inicializa con dfs_lca(1,1)
    tin[v] = ++timer;
    anc[v][0] = p;

    for (int i = 1; i <= l; ++i) anc[v][i] = anc[ anc[v][i - 1] ][i - 1];
    for (int w : G[v]) if (w != p) h[w] = h[v] + 1;
    for (int w : G[v]) if (w != p) dfs_lca(w, v);

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;

    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(anc[u][i], v)) {
            u = anc[u][i];
        }
    }
    return anc[u][0];
}

int dist(int a, int b) {
    return h[a] + h[b] - 2 * h[lca(a, b)];
}





int p[MAXN];
vi PRE[MAXN], SUF[MAXN];
int IND[MAXN], DST[MAXN];

void build(int x) {
    DST[x] = -INF;
    FOR(i, 0, SZ(CT[x])) {
        int y = CT[x][i];
        IND[y] = i;
        PRE[x].pb(-INF), SUF[x].pb(-INF);
        build(y);
    }
}

void upd(int x) {
    DST[x] = 0;
    int gf = fat[x], f = x;
    while (gf != -1) {
        SUF[gf][IND[f]] = PRE[gf][IND[f]] = max(PRE[gf][IND[f]], dist(x, gf));
        gf = fat[gf];
        f = fat[f];
    }
}

void build2(int x) {
    FOR(i, 1, SZ(CT[x])) PRE[x][i] = max(PRE[x][i], PRE[x][i - 1]);
    ROF(i, SZ(CT[x]) - 2, -1) SUF[x][i] = max(SUF[x][i], SUF[x][i + 1]);
    for (auto y : CT[x]) build2(y);
}

bool query(int x) {
    if (SZ(CT[x]) && SUF[x][0] > d)
        return false;
    int gf = fat[x], f = x;
    while (gf != -1) {
        int i = IND[f];
        int tmp = dist(gf, x);
        if (DST[gf] + tmp > d)
            return false;
        if (i > 0) {
            if (PRE[gf][i - 1] + tmp > d)
                return false;
        }
        if (i < SZ(CT[gf]) - 1) {
            if (SUF[gf][i + 1] + tmp > d)
                return false;
        }
        gf = fat[gf];
        f = fat[f];
    }
    return true;
}

int main() {
    riii(n, m, d);
    FOR(i, 0, m) ri(p[i]), p[i]--;
    FOR(i, 1, n) {
        int a, b; rii(a, b); a--, b--;
        G[a].pb(b); G[b].pb(a);
    }
    dfs_lca(0, 0);
    centroid();
    int root = 0;
    FOR(i, 0, n) root = (fat[i] == -1 ? i : root);
    build(root);
    FOR(i, 0, m) upd(p[i]);
    build2(root);
    int ans = 0;
    FOR(i, 0, n) ans += query(i);
    printf("%d\n", ans);
    return 0;
}