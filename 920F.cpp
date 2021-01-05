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
const int MAXN = 3e5 + 10; // CAMBIAR ESTE
const int MAXP = 1e6 + 10;

// GJNM
// Todos los rangos son semi-abiertos [a,b)
int N, A[MAXN];
int D[MAXP];

bool NOT_P[MAXP];
vi primes;
void pre() {
    FOR(i, 2, MAXP) {
        if (NOT_P[i]) continue;
        primes.pb(i);
        int j = i + i;
        while (j < MAXP) {
            NOT_P[j] = true;
            j += i;
        }
    }
}

void f(int i) {
    D[i] = 1;
    int j = i;
    for (auto p : primes) {
        if (p * p > j) break;
        int cnt = 0;
        while (j % p == 0) {
            j = j / p;
            cnt++;
        }
        D[i] *= (cnt + 1);
    }
    if (j > 1) D[i] *= 2;
}



struct STN {
    int ind;
    vector<ll> vals;
    void merge(STN& L, STN& R) {
        ind = 0;
        vals.resize(7);
        FOR(i, 0, 7) vals[i] = 0;
        int j = 0;
        FOR(i, L.ind, 7) vals[j++] += L.vals[i];
        while (j < 7) vals[j++] = L.vals.back();
        j = 0;
        FOR(i, R.ind, 7) vals[j++] += R.vals[i];
        while (j < 7) vals[j++] += R.vals.back();
    }
    void operator=(ll a) {
        ind = 0;
        vals.pb(a);
        FOR(i, 1, 7) {
            if (D[vals.back()] == 0)
                f(vals.back());
            vals.pb(D[vals.back()]);
        }
    }
};
STN ST[4 * MAXN];
int lzy[4 * MAXN];
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
    lzy[id] += x;
    ST[id].ind = min(ST[id].ind + x, 6ll);
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
    if (lzy[id] != 0)
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
    if (lzy[id] != 0)
        shift(id, l, r);
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STU(x, y, v, L, l, m);
    STU(x, y, v, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}


int main() {
    int M;
    rii(N, M);
    pre();
    FOR(i, 0, N) ri(A[i]);
    STB();
    while (M--) {
        int t, l, r; riii(t, l, r); l--;
        if (t == 1) STU(l, r, 1);
        else {
            auto node = STQ(l, r);
            printf("%lld\n", node.vals[node.ind]);
        }
    }
    return 0;
}