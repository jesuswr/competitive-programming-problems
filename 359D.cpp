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

// GJNM

// Todos los rangos son semi-abiertos [a,b)
int N, A[MAXN];
struct STN {
    int mn, gcd;
    void merge(STN& L, STN& R) {
        mn = min(L.mn, R.mn);
        gcd = __gcd(L.gcd, R.gcd);
    }
    void operator=(int a) {
        mn = gcd = a;
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

bool valid(int k) {
    int l = 0, r = k + 1;
    while (r <= N) {
        auto q = STQ(l, r);
        if (q.mn == q.gcd) return true;
        ++l, ++r;
    }
    return false;
}

void ans(int k) {
    vi ls;
    int l = 0, r = k + 1;
    while (r <= N) {
        auto q = STQ(l, r);
        if (q.mn == q.gcd) ls.pb(l + 1);
        ++l, ++r;
    }
    printf("%d %d\n", SZ(ls), k);
    for (auto x : ls) printf("%d ", x);
    printf("\n");
}


int main() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    STB();
    int lo = 0, hi = N;
    while (lo < hi) {
        int mi = lo + (hi - lo + 1) / 2;
        if (valid(mi)) lo = mi;
        else hi = mi - 1;
    }
    ans(lo);
    return 0;
}