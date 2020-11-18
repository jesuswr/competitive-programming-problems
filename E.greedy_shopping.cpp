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

int addsadas;

#define ri(a) addsadas=scanf("%d", &a)
#define rii(a,b) addsadas=scanf("%d %d", &a, &b)
#define riii(a,b,c) addsadas=scanf("%d %d %d", &a, &b, &c)
#define rl(a) addsadas=scanf("%lld", &a)
#define rll(a,b) addsadas=scanf("%lld %lld", &a, &b)
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
const int MAXN = 3e5; // CAMBIAR ESTE

// GJNM
void shift(int id, int l, int r) ;

// Todos los rangos son semi-abiertos [a,b)
int N, A[MAXN];
struct STN {
    ll mn, mx, sm;
    void merge(STN& L, STN& R) {
        mn = min(L.mn, R.mn);
        mx = max(L.mx, R.mx);
        sm = L.sm + R.sm;
    }
    void operator=(ll a) {
        mx = mn = sm = a;
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
    lzy[id] = max(lzy[id], x);
    if (lzy[id] <= ST[id].mn) {
        return;
    }
    else if (lzy[id] >= ST[id].mx) {
        ST[id].mx = ST[id].mn = lzy[id];
        ST[id].sm = (r - l) * lzy[id];
    }
    else {
        shift(id, l, r);
    }
}
// Propaga el update en lazy
void shift(int id, int l, int r) {
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    upd(L, l, m, lzy[id]);
    upd(R, m, r, lzy[id]);
    ST[id].merge(ST[L], ST[R]);
}
pair<ll, ll> STQ(int x, int y, ll v, int id = 1, int l = 0, int r = N) {
    if (x == l && y == r) {
        if (ST[id].sm <= v)
            return {ST[id].sm, r - l};
        if (ST[id].mn > v)
            return {0, 0};
    }
    shift(id, l, r);
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (x >= m)
        return STQ(x, y, v, R, m, r);
    if (y <= m)
        return STQ(x, y, v, L, l, m);

    auto p = STQ(x, m, v, L, l, m);
    v -= p.F;
    auto p2 = STQ(m, y, v, R, m, r);
    return {p.F + p2.F, p.S + p2.S};
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
    int n, q;
    rii(n, q); N = n;
    FOR(i, 0, n) {
        ri(A[i]);
    }
    STB();

    while (q--) {
        int t, x, y; riii(t, x, y);
        if (t == 1)
            STU(0, x, y);
        else
            printf("%lld\n", STQ(x - 1, N, y).S);
    }

    return 0;
}