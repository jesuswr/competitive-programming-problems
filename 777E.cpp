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
const int MAXN = 2e5; // CAMBIAR ESTE

// GJNM
struct RING {
    ll a, b, h;
    int i;

    bool operator<(const RING &other) {
        if (b == other.b) return a > other.a;
        return b > other.b;
    }
};

int N;
RING A[MAXN];

int AUX[MAXN];
void pre() {
    FOR(i, 0, N) {
        AUX[2 * i] = A[i].a;
        AUX[2 * i + 1] = A[i].b;
    }
    sort(AUX, AUX + 2 * N);
    map<int, int> new_val;
    FOR(i, 0, 2 * N) new_val[AUX[i]] = i + 1;
    FOR(i, 0, N) {
        A[i].a = new_val[A[i].a];
        A[i].b = new_val[A[i].b];
    }
}

// Todos los rangos son semi-abiertos [a,b)
struct STN {
    ll mx;
    void merge(STN& L, STN& R) {
        mx = max(L.mx, R.mx);
    }
    void operator=(ll a) {
        mx = max(mx, a);
    }
};
STN ST[4 * MAXN];
STN STQ(int x, int y, int id = 1, int l = 0, int r = N) {
    if (x == l && y == r) return ST[id];
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (x >= m) return STQ(x, y, R, m, r);
    if (y <= m) return STQ(x, y, L, l, m);
    STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
    return res.merge(ln, rn), res;
}
void STU(int p, ll x, int id = 1, int l = 0, int r = N) {
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
    FOR(i, 0, N) rll(A[i].a, A[i].b), rl(A[i].h), A[i].i = i;
    pre();
    sort(A, A + N);
    int aux = N;
    N = MAXN;
    FOR(i, 0, aux) STU(A[i].a, A[i].h + STQ(0, A[i].b).mx);
    printf("%lld\n", STQ(0, MAXN).mx);
    return 0;
}