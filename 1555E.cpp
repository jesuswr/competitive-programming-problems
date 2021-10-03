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

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 2e6 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
struct SEG {
    int l, r, w;
};
// Todos los rangos son semi-abiertos [a,b)
int N = 2e6;
struct STN {
    int mn;
    void merge(STN& L, STN& R) {
        mn = min(L.mn, R.mn);
    }
    void operator=(ll a) {
        mn = a;
    }
};
STN ST[4 * MAXN];
ll lzy[4 * MAXN];
// Actualiza el nodo y guarda en lazy
void upd(int id, int l, int r, ll x) {
    lzy[id] += x;
    ST[id].mn += x;
}
// Propaga el update en lazy
void shift(int id, int l, int r) {
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

int main() {
    int n, m; m = 2 * (m - 1) + 1;
    rii(n, m);
    m = 2 * (m - 1) + 1;
    vector<SEG> a(n);
    FOR(i, 0, n) riii(a[i].l, a[i].r, a[i].w), a[i].l = 2 *  (a[i].l - 1), a[i].r = 2 * (a[i].r - 1);
    sort(ALL(a), [](SEG x, SEG y) {
        return x.w < y.w;
    });
    // FOR(i, 0, n) printf("%d : %d %d %d\n", i, a[i].l, a[i].r, a[i].w);
    int l = 0, r = 0;
    int ans = N;
    while (1) {
        while (STQ(0, m).mn == 0 && r < n) {
            STU(a[r].l, a[r].r + 1, 1);
            ++r;
        }
        if (STQ(0, m).mn == 0)
            break;
        // printf("%d %d\n", l, r - 1);
        ans = min(a[r - 1].w - a[l].w, ans);
        STU(a[l].l, a[l].r + 1, -1);
        ++l;
    }
    printf("%d\n", ans);
    return 0;
}