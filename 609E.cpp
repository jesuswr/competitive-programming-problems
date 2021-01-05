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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE

// GJNM
struct EDGE {
    int from, to, w, ind;

    bool operator<(const EDGE &other) {
        return w < other.w;
    }
};

int N, M;
vector<EDGE> E;
ll ANS[MAXN];

int REP[MAXN], HEI[MAXN];
void make() {
    FOR(i, 0, N) {
        REP[i] = -1;
        HEI[i] = 0;
    }
}

int find(int x) {
    if (REP[x] == -1) return x;
    return REP[x] = find(REP[x]);
}

void unio(int x, int y) {
    if (HEI[x] > HEI[y]) {
        REP[y] = x;
    }
    else {
        REP[x] = y;
        if (HEI[y] == HEI[x]) HEI[y]++;
    }
}


// Todos los rangos son semi-abiertos [a,b)
int A[MAXN];
struct STN {
    int mx;
    void merge(STN& L, STN& R) {
        mx = max(L.mx, R.mx);
    }
    void operator=(int a) {
        mx = a;
    }
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = MAXN) {
    if (r - l < 2) {
        ST[id] = A[l];
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STB(L, l, m); STB(R, m, r);
    ST[id].merge(ST[L], ST[R]);
}
STN STQ(int x, int y, int id = 1, int l = 0, int r = MAXN) {
    if (x == l && y == r) return ST[id];
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (x >= m) return STQ(x, y, R, m, r);
    if (y <= m) return STQ(x, y, L, l, m);
    STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
    return res.merge(ln, rn), res;
}
void STU(int p, int x, int id = 1, int l = 0, int r = MAXN) {
    if (r - l < 2) {
        ST[id] = x;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU(p, x, L, l, m);
    else STU(p, x, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}



vii G[MAXN];
int wg[MAXN], dad[MAXN], dep[MAXN]; // weight,father,depth
void dfs1(int x) {
    wg[x] = 1;
    for (auto aux : G[x]) {
        int y = aux.F;
        if (y != dad[x]) {
            dad[y] = x; dep[y] = dep[x] + 1; dfs1(y);
            wg[x] += wg[y];
        }
    }
}
int curpos, pos[MAXN], head[MAXN];
void hld(int x, int c) {
    if (c < 0)c = x;
    pos[x] = curpos++; head[x] = c;
    int mx = -1;
    for (auto y : G[x])if (y.F != dad[x] && (mx < 0 || wg[mx] < wg[y.F]))mx = y.F;
    if (mx >= 0)hld(mx, c);
    for (auto y : G[x])if (y.F != mx && y.F != dad[x])hld(y.F, -1);
}
void hld_init() {dad[0] = -1; dep[0] = 0; dfs1(0); curpos = 0; hld(0, -1);}
int query(int x, int y) {
    int r = 0;
    while (head[x] != head[y]) {
        if (dep[head[x]] > dep[head[y]])swap(x, y);
        r = max(r, STQ(pos[head[y]], pos[y] + 1).mx);
        y = dad[head[y]];
    }
    if (dep[x] > dep[y])swap(x, y); // now x is lca
    if (x != y)
        r = max(r, STQ(pos[x] + 1, pos[y] + 1).mx);
    return r;
}
// for updating: STU(pos[x],u)
// queries on edges: - assign values of edges to "child" node
//                   - change pos[x] to pos[x]+1 in query (line 30)


void dfs(int x = 0, int f = -1) {
    for (auto tmp : G[x]) {
        int y = tmp.F;
        int w = tmp.S;
        if (y == f) continue;
        A[pos[y]] = w;
        dfs(y, x);
    }
}



int main() {
    rii(N, M);
    FOR(i, 0, M) {
        int a, b, w; riii(a, b, w);
        E.pb({a - 1, b - 1, w, i});
    }
    sort(ALL(E));
    make();
    ll w = 0;
    for (auto e : E) {
        if (find(e.from) != find(e.to)) {
            unio(find(e.from), find(e.to));
            w += e.w;
            G[e.from].pb({e.to, e.w});
            G[e.to].pb({e.from, e.w});
        }
    }
    hld_init();
    dfs();
    STB();
    for (auto e : E) {
        ANS[e.ind] = w + e.w - query(e.from, e.to);
    }

    FOR(i, 0, M) printf("%lld\n", ANS[i]);

    return 0;
}