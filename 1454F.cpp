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
const int MAXN = 2e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
// Todos los rangos son semi-abiertos [a,b)
int N, A[MAXN];
struct STN {
    int mn, mx;
    void merge(STN& L, STN& R) {
        mn = min(L.mn, R.mn);
        mx = max(L.mx, R.mx);
    }
    void operator=(int a) {
        mn = mx = a;
    }
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = A[l];
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
void STU(int p, int x, int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = x;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU(p, x, L, l, m);
    else STU(p, x, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}

void solve() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    STB();
    for (int l = 0; l < N - 2; ++l) {
        int mx = STQ(0, l + 1).mx;
        int lo = l + 2, hi = N - 1;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (STQ(mi, N).mx <= mx)
                hi = mi;
            else
                lo = mi + 1;
        }
        int r = hi;
        // printf("%d %d %d\n", l, r, mx);
        if (STQ(r, N).mx != mx)
            continue;
        if (r + 1 < N && STQ(r + 1, N).mx == mx && A[r] == mx)
            ++r;
        if (STQ(l + 1, r).mn == mx) {
            printf("YES\n%d %d %d\n", l + 1, r - 1 - l, N - r);
            return;
        }
    }
    printf("NO\n");
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}