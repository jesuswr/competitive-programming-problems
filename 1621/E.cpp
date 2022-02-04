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
const int MAXN = 1e5 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
// Todos los rangos son semi-abiertos [a,b)
struct STN {
    ll tot, mn;
    void merge(STN& L, STN& R) {
        tot = L.tot + R.tot;
        mn  = min(R.mn, R.tot + L.mn);
    }
    void operator=(int a) {
        tot = mn = a;
    }
    void operator+=(int a) {
        tot += a;
        mn += a;
    }
};
STN ST[4 * MAXN];
STN STQ(int x, int y, int id = 1, int l = 0, int r = MAXN) {
    if (x == l && y == r) return ST[id];
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (x >= m) return STQ(x, y, R, m, r);
    if (y <= m) return STQ(x, y, L, l, m);
    STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
    return res.merge(ln, rn), res;
}
void STU(int p, int x, int id = 1, int l = 0, int r = MAXN) {
    if (r - l < 2) {
        ST[id] += x;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU(p, x, L, l, m);
    else STU(p, x, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}

struct group {
    vi b;
    ll sm;

    int get_prom() {
        ll sz = SZ(b);
        return (sm + sz - 1) / sz;
    }
    int get_prom(int a) {
        ll sz = SZ(b) - 1;
        return (sm - a + sz - 1) / sz;
    }
};

int N, M;
int A[MAXN];

void solve() {
    rii(N, M);
    FOR(i, 0, N) ri(A[i]);
    vector<group> B(M);
    FOR(i, 0, M) {
        int k; ri(k);
        FOR(_, 0, k) {
            int x; ri(x);
            B[i].b.pb(x);
            B[i].sm += x;
        }
    }

    FOR(i, 0, N) STU(A[i], 1);
    FOR(i, 0, M) STU(B[i].get_prom(), -1);

    FOR(i, 0, M) {
        STU(B[i].get_prom(), 1);

        for (int x : B[i].b) {
            STU(B[i].get_prom(x), -1);

            if (STQ(0, MAXN).mn < 0)
                printf("0");
            else
                printf("1");

            STU(B[i].get_prom(x), 1);
        }

        STU(B[i].get_prom(), -1);
    }
    printf("\n");

    FOR(i, 0, N) STU(A[i], -1);
    FOR(i, 0, M) STU(B[i].get_prom(), 1);
}


int main() {
    int t; ri(t);
    while (t--)
        solve();
    return 0;
}