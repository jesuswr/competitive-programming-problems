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
const int MAXN = 2e5 + 100; // CAMBIAR ESTE

// GJNM

// Todos los rangos son semi-abiertos [a,b)
int N, Q;
int A[MAXN], B[MAXN];
struct STN {
    int cnt[2];
    void merge(STN& L, STN& R) {
        FOR(i, 0, 2) cnt[i] = L.cnt[i] + R.cnt[i];
    }
};
STN ST[4 * MAXN];
ll lzy[4 * MAXN];
// Actualiza el nodo y guarda en lazy
void upd(int id, int l, int r, ll x) {
    lzy[id] = x;
    ST[id].cnt[x] = (r - l);
    ST[id].cnt[x ^ 1] = 0;
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
    if (lzy[id] != -1) shift(id, l, r);
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
    if (lzy[id] != -1) shift(id, l, r);
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STU(x, y, v, L, l, m);
    STU(x, y, v, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}
void STB(int id = 1, int l = 0, int r = N) {
    lzy[id] = -1;
    ST[id].cnt[0] = ST[id].cnt[1] = 0;
    if (r - l < 2) {
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STB(L, l, m); STB(R, m, r);
    ST[id].merge(ST[L], ST[R]);
}


void solve() {
    rii(N, Q);
    STB();
    FOR(i, 0, N) dadsadasda = scanf("%1d", A + i);
    FOR(i, 0, N) dadsadasda = scanf("%1d", B + i);
    vii qs(Q);
    FOR(i, 0, Q) rii(qs[i].F, qs[i].S);
    reverse(ALL(qs));

    FOR(i, 0, N) STU(i, i + 1, B[i]);

    FOR(i, 0, Q) {
        --qs[i].F;
        auto stq = STQ(qs[i].F, qs[i].S);
        if (stq.cnt[0] == stq.cnt[1]) {
            printf("NO\n");
            return;
        }
        int p = (stq.cnt[0] < stq.cnt[1] ? 1 : 0);
        STU(qs[i].F, qs[i].S, p);
    }

    FOR(i, 0, N) {
        auto stq = STQ(i, i + 1);
        int p = (stq.cnt[0] < stq.cnt[1] ? 1 : 0);
        if (A[i] != p) {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}