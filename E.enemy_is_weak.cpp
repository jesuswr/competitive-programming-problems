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
const int MAXN = 1e6 + 10; // CAMBIAR ESTE

// GJNM
int n;
int a[MAXN], b[MAXN];

void compress() {
    sort(b, b + n);
    map<int, int> new_a;
    FOR(i, 0, n) {
        new_a[b[i]] = i + 1;
    }
    FOR(i, 0, n) {
        a[i] = new_a[a[i]];
    }
}

// Todos los rangos son semi-abiertos [a,b)
int N, A[MAXN];
struct STN {
    int l, r;
    void merge(STN& L, STN& R) {
        l = L.l + R.l;
        r = L.r + R.r;
    }
    void operator=(pii aa) {
        l += aa.F;
        r += aa.S;
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
void STU(int p, pii x, int id = 1, int l = 0, int r = N) {
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
    ri(n);
    FOR(i, 0, n) {
        ri(a[i]);
        b[i] = a[i];
    }
    compress();
    N = n + 5;
    FOR(i, 0, n) {
        STU(a[i], {0, 1});
    }
    ll ans = 0;
    FOR(i, 0, n) {
        if (i > 0 && i < n - 1) {
            ans += STQ(0, a[i]).r * 1ll * STQ(a[i] + 1, N).l;
        }
        STU(a[i], {1, -1});
    }
    printf("%lld\n", ans);

    return 0;
}