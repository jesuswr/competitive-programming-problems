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
const int LOGN = 25;

// GJNM
int N, Q;

struct STN {
    ll val;
    void merge(STN& L, STN& R) {
        val = L.val + R.val;
    }
    void operator=(ll a) {
        val = a;
    }
};
STN ST[4 * MAXN];
ll lzy[4 * MAXN];
// Actualiza el nodo y guarda en lazy
void upd(int id, int l, int r, ll x) {
    lzy[id] = x;
    ST[id].val = x * (r - l);
}
// Propaga el update en lazy
void shift(int id, int l, int r) {
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    upd(L, l, m, lzy[id]);
    upd(R, m, r, lzy[id]);
    lzy[id] = -1;
}
STN STQ(int x, int y, int id = 1, int l = 0, int r = N) {
    if (x == l && y == r) return ST[id];
    if (lzy[id] != -1)
        shift(id, l, r);
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (x >= m) return STQ(x, y, R, m, r);
    if (y <= m) return STQ(x, y, L, l, m);
    STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
    return res.merge(ln, rn), res;
}
void STU(int x, int y, int v, int id = 1, int l = 0, int r = N) {
    if (x >= r || y <= l) return;
    if (x <= l && y >= r) {
        upd(id, l, r, v);
        return;
    }
    if (lzy[id] != -1)
        shift(id, l, r);
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STU(x, y, v, L, l, m);
    STU(x, y, v, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}
vector<int> G[MAXN];
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
int query(int x, int y) {
    int r = 0;
    while (head[x] != head[y]) {
        if (dep[head[x]] > dep[head[y]])swap(x, y);
        r = r + STQ(pos[head[y]], pos[y] + 1).val;
        y = dad[head[y]];
    }
    if (dep[x] > dep[y])swap(x, y); // now x is lca
    r = r + STQ(pos[x], pos[y] + 1).val;
    return r;
}
void upd(int x, int y, int val) {
    while (head[x] != head[y]) {
        if (dep[head[x]] > dep[head[y]])swap(x, y);
        STU(pos[head[y]], pos[y] + 1, val);
        y = dad[head[y]];
    }
    if (dep[x] > dep[y])swap(x, y); // now x is lca
    STU(pos[x], pos[y] + 1, val);
}
// for updating: STU(pos[x],u)
// queries on edges: - assign values of edges to "child" node
//                   - change pos[x] to pos[x]+1 in query (line 30)


int main() {
    memset(lzy, -1, sizeof(lzy));
    rii(N, Q);
    FOR(_, 1, N) {
        int a, b; rii(a, b); --a, --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    hld_init();
    while (Q--) {
        int a, b, c, d; rii(a, b); rii(c, d);
        --a; --b; --c; --d;
        upd(a, b, 1);
        printf("%d\n", query(c, d));
        upd(a, b, 0);
    }

    return 0;
}