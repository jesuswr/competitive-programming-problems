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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM

// Todos los rangos son semi-abiertos [a,b)
int N, Q, X, A[MAXN];
struct STN {
    int cnt[3];
    void merge(STN& L, STN& R) {
        FOR(i, 0, 3)cnt[i] = L.cnt[i] + R.cnt[i];
    }
    void operator=(ll a) {
        cnt[0] = cnt[1] = cnt[2] = 0;
        cnt[a] = 1;
    }
};
STN ST[4 * MAXN];
ll lzy[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
    lzy[id] = -1;
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
    FOR(i, 0, 3) ST[id].cnt[i] = 0;
    ST[id].cnt[x] = r - l;
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

int main() {
    riii(N, Q, X);
    int ans = 69696969;
    FOR(i, 0, N) {
        int a; ri(a);
        if (a < X) A[i] = 0;
        if (a == X) {
            ans = i;
            A[i] = 1;
        }
        if (a > X) A[i] = 2;
    }
    STB();
    while (Q--) {
        int c, l, r; riii(c, l, r);
        --l;
        auto q = STQ(l, r);
        if (c == 1) {
            if (q.cnt[0] != 0)
                STU(l, l + q.cnt[0], 0);
            l += q.cnt[0];
            if (q.cnt[1] != 0) {
                ans = l;
                STU(l, l + q.cnt[1], 1);
            }
            l += q.cnt[1];
            if (q.cnt[2] != 0)
                STU(l, l + q.cnt[2], 2);
        }
        else {
            if (q.cnt[2] != 0)
                STU(l, l + q.cnt[2], 2);
            l += q.cnt[2];
            if (q.cnt[1] != 0) {
                ans = l;
                STU(l, l + q.cnt[1], 1);
            }
            l += q.cnt[1];
            if (q.cnt[0] != 0)
                STU(l, l + q.cnt[0], 0);
        }
    }
    printf("%d\n", ans + 1);
    return 0;
}