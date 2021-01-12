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
const long double PI = 2 * acos(0.0);

// GJNM
struct CAKE {
    ll r, h, vol;
    int ind;
    bool operator<(const CAKE &other) {
        if (vol != other.vol) return vol < other.vol;
        return ind > other.ind;
    }
};

int N;
CAKE A[MAXN];

// Todos los rangos son semi-abiertos [a,b)
struct STN {
    ll mx;
    void merge(STN& L, STN& R) {
        mx = max(L.mx, R.mx);
    }
    void operator=(ll a) {
        mx = a;
    }
};
STN ST[4 * MAXN];
STN STQ(int x, int y, int id = 1, int l = 0, int r = N + 1) {
    if (x == l && y == r) return ST[id];
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (x >= m) return STQ(x, y, R, m, r);
    if (y <= m) return STQ(x, y, L, l, m);
    STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
    return res.merge(ln, rn), res;
}
void STU(int p, ll x, int id = 1, int l = 0, int r = N + 1) {
    if (r - l < 2) {
        ST[id] = x;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU(p, x, L, l, m);
    else STU(p, x, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}

int main() {
    ri(N);
    FOR(i, 0, N) dadsadasda = scanf("%lld %lld", &A[i].r, &A[i].h);
    FOR(i, 0, N) {
        A[i].ind = i + 1;
        A[i].vol = A[i].r * A[i].r * A[i].h;
    }
    sort(A, A + N);
    FOR(i, 0, N) {
        ll mx = STQ(0, A[i].ind).mx;
        STU(A[i].ind, A[i].vol + mx);
    }
    printf("%.10Lf\n", PI * STQ(1, N + 1).mx);
    return 0;
}