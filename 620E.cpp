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
#include <bitset>

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
const int MAXN = 4e5 + 100; // CAMBIAR ESTE

// GJNM


// Todos los rangos son semi-abiertos [a,b)
int N, M, A[MAXN], B[MAXN], IN[MAXN], OUT[MAXN];
vi G[MAXN];
struct STN {
    bitset<61> cols;
    void merge(STN& L, STN& R) {
        cols = L.cols | R.cols;
    }
    void operator=(int a) {
        cols.reset();
        cols[a] = 1;
    }
};
STN ST[4 * MAXN];
ll lzy[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = A[l];
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STB(L, l, m); STB(R, m, r);
    ST[id].merge(ST[L], ST[R]);
}
// Actualiza el nodo y guarda en lazy
void upd(int id, int l, int r, ll x) {
    lzy[id] = x;
    ST[id].cols.reset();
    ST[id].cols[x] = 1;
}
// Propaga el update en lazy
void shift(int id, int l, int r) {
    if (lzy[id] == 0) return;
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    upd(L, l, m, lzy[id]);
    upd(R, m, r, lzy[id]);
    lzy[id] = 0;
}
STN STQ(int x, int y, int id = 1, int l = 0, int r = N) {
    if (x == l && y == r) return ST[id];
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
    shift(id, l, r);
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STU(x, y, v, L, l, m);
    STU(x, y, v, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}

int T = 0;
void dfs(int x, int f = -1) {
    IN[x] = T++;
    A[IN[x]] = B[x];
    for (auto y : G[x]) {
        if (y == f) continue;
        dfs(y, x);
    }
    OUT[x] = T;
}

int main() {
    rii(N, M);
    FOR(i, 0, N) ri(B[i]);
    FOR(_, 1, N) {
        int a, b; rii(a, b); --a, --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(0);
    STB();
    FOR(_, 0, M) {
        int t; ri(t);
        if (t == 1) {
            int v, c; rii(v, c);
            STU(IN[v - 1], OUT[v - 1], c);
        }
        else {
            int v; ri(v);
            auto tmp = STQ(IN[v - 1], OUT[v - 1]);
            printf("%d\n", tmp.cols.count());
        }
    }
    return 0;
}