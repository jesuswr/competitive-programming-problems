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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE
const ll MOD[2] = {999727999, (ll)1e9 + 7};
const ll P = 29;

// GJNM
int n, q;
char s[MAXN];
vector<int> G[MAXN];
ll pw[2][MAXN];

int LOGN = 25; // l = log(n)

int timer; // Tiempos de entrada y salida de cada nodo y su ancestro a dist 2**i
int tin[MAXN], tout[MAXN], anc[MAXN][ 26 ];

void dfs(int v, int p) { // Se inicializa con dfs(1,1)
    tin[v] = ++timer;
    anc[v][0] = p;

    for (int i = 1; i <= LOGN; ++i) anc[v][i] = anc[ anc[v][i - 1] ][i - 1];
    for (int w : G[v]) if (w != p) dfs(w, v);

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;

    for (int i = LOGN; i >= 0; --i) {
        if (!is_ancestor(anc[u][i], v)) {
            u = anc[u][i];
        }
    }
    return anc[u][0];
}


// ST //////////////////////////////////////////////////////////////////////////
// Todos los rangos son semi-abiertos [a,b)
int N;
char A[MAXN];
struct STN {
    ll hash[2] = {0, 0}, rhash[2] = {0, 0};
    int sz = 0;
    void merge(STN L, STN R) {
        sz = L.sz + R.sz;
        FOR(i, 0, 2) {
            hash[i] = (L.hash[i] + (R.hash[i] * pw[i][L.sz]) % MOD[i]) % MOD[i];
            rhash[i] = (R.rhash[i] + (L.rhash[i] * pw[i][R.sz]) % MOD[i]) % MOD[i];
        }
    }
    void operator=(char c) {
        FOR(i, 0, 2) {
            hash[i] = rhash[i] = c - 'a' + 1;
        }
        sz = 1;
    }
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = A[l];
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STB(L, l, m); STB(R, m, r);
    ST[id].merge(ST[L], ST[R]);
}
STN STQ(int x, int y, int id = 1, int l = 0, int r = N) {
    if (x == l && y == r) return ST[id];
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (x >= m) return STQ(x, y, R, m, r);
    if (y <= m) return STQ(x, y, L, l, m);
    STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
    return res.merge(ln, rn), res;
}
void STU(int p, char x, int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = x;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU(p, x, L, l, m);
    else STU(p, x, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}

// ST //////////////////////////////////////////////////////////////////////////


// HLD //////////////////////////////////////////////////////////////////////////
int wg[MAXN], dad[MAXN], dep[MAXN]; // weight,father,depth
void dfs1(int x) {
    wg[x] = 1;
    for (int y : G[x])if (y != dad[x]) {
            dad[y] = x; dep[y] = dep[x] + 1; dfs1(y);
            wg[x] += wg[y];
        }
}
int curpos, pos[MAXN], head[MAXN];
void hld(int x, int c) {
    if (c < 0)c = x;
    pos[x] = curpos++; head[x] = c;
    int mx = -1;
    for (int y : G[x])if (y != dad[x] && (mx < 0 || wg[mx] < wg[y]))mx = y;
    if (mx >= 0)hld(mx, c);
    for (int y : G[x])if (y != mx && y != dad[x])hld(y, -1);
}
void hld_init() {dad[0] = -1; dep[0] = 0; dfs1(0); curpos = 0; hld(0, -1);}
STN query(int x, int y) {
    STN r;
    while (head[x] != head[y]) {
        if (dep[head[x]] > dep[head[y]])swap(x, y);
        r.merge(STQ(pos[head[y]], pos[y] + 1), r);
        y = dad[head[y]];
    }
    if (dep[x] > dep[y])swap(x, y); // now x is lca
    r.merge(STQ(pos[x], pos[y] + 1), r);
    return r;
}
STN query2(int x, int y) {
    STN r;
    while (head[x] != head[y]) {
        if (dep[head[x]] > dep[head[y]])swap(x, y);
        r.merge(STQ(pos[head[y]], pos[y] + 1), r);
        y = dad[head[y]];
    }
    if (dep[x] > dep[y])swap(x, y); // now x is lca
    if (x != y)
        r.merge(STQ(pos[x] + 1, pos[y] + 1), r);
    return r;
}
// for updating: STU(pos[x],u)
// queries on edges: - assign values of edges to "child" node
//                   - change pos[x] to pos[x]+1 in query (line 30)
// HLD //////////////////////////////////////////////////////////////////////////


int main() {
    rii(n, q);
    pw[0][0] = pw[1][0] = 1;
    FOR(i, 0, 2) {
        FOR(j, 1, n + 1) {
            pw[i][j] = (pw[i][j - 1] * P) % MOD[i];
        }
    }

    dadsadasda = scanf("%s\n", s);
    FOR(i, 1, n) {
        int a, b; rii(a, b); a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    hld_init();
    dfs(0, 0);
    FOR(i, 0, n) {
        A[pos[i]] = s[i];
    }
    N = curpos;
    STB();

    while (q--) {
        int type; ri(type);
        if (type == 1) {
            int u, v; rii(u, v); u--, v--;
            int lc = lca(u, v);
            auto x = query(u, lc), y = query2(v, lc);
            bool good = true;
            FOR(i, 0, 2) {
                ll xx = (x.rhash[i] + (y.hash[i] * pw[i][x.sz]) % MOD[i]) % MOD[i];
                ll yy = (y.rhash[i] + (x.hash[i] * pw[i][y.sz]) % MOD[i]) % MOD[i];
                if (xx != yy)
                    good = false;
            }
            if (good)
                printf("Yes\n");
            else
                printf("No\n");
        }
        else {
            int x; char c;
            dadsadasda = scanf("%d %c\n", &x, &c); x--;
            STU(pos[x], c);
        }
    }

    return 0;
}