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
const int MAXN = 5e5; // CAMBIAR ESTE

// GJNM
struct RECT {
    int w, h, ind;

    bool operator<(RECT other) {
        return w < other.w;
    }
};
RECT A[MAXN];
void compress(int n) {
    vi aux;
    FOR(i, 0, n) {
        aux.pb(A[i].w);
        aux.pb(A[i].h);
    }
    sort(ALL(aux));
    map<int, int> nw;
    FOR(i, 0, 2 * n) nw[aux[i]] = i + 1;
    FOR(i, 0, n) {
        A[i].h = nw[A[i].h];
        A[i].w = nw[A[i].w];
    }
}


// Todos los rangos son semi-abiertos [a,b)
int N;
struct STN {
    int mn, mn_i;
    void merge(STN& L, STN& R) {
        mn = min(L.mn, R.mn);
        if (L.mn == mn) mn_i = L.mn_i;
        else mn_i = R.mn_i;
    }
    void operator=(int a) {
        mn = a;
    }
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = 1e9 + 20;
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
void STU(int p, pii x, int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        if (ST[id].mn > x.F) {
            ST[id].mn = x.F;
            ST[id].mn_i = x.S;
        }
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU(p, x, L, l, m);
    else STU(p, x, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}


void solve() {
    int n; ri(n);
    FOR(i, 0, n) rii(A[i].w, A[i].h), A[i].ind = i;
    compress(n);
    N = 2 * n + 10;
    STB();
    FOR(i, 0, n) {
        int h = A[i].h, w = A[i].w;
        STU(h, {w, i});
        STU(w, {h, i});
    }
    vi ans(n, -2);
    FOR(i, 0, n) {
        int h = A[i].h, w = A[i].w;
        auto node = STQ(0, h);
        assert(h != 0);
        if (node.mn < w) {
            ans[i] = node.mn_i;
            continue;
        }
        node = STQ(0, w);
        assert(w != 0);
        if (node.mn < h) {
            ans[i] = node.mn_i;
        }
    }
    FOR(i, 0, n) printf("%d ", ans[i] + 1);
    printf("\n");
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}