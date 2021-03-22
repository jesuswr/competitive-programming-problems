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
const int MAXN = 150011; // CAMBIAR ESTE

// GJNM

// Todos los rangos son semi-abiertos [a,b)
int N[5], A[5][MAXN];
struct STN {
    int mn;
    void merge(STN& L, STN& R) {
        mn = min(L.mn, R.mn);
    }
    void operator=(int a) {
        mn = a;
    }
};
STN ST[5][4 * MAXN];
STN STQ(int lev, int x, int y, int id = 1, int l = 0, int r = MAXN) {
    if (x == l && y == r) return ST[lev][id];
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (x >= m) return STQ(lev, x, y, R, m, r);
    if (y <= m) return STQ(lev, x, y, L, l, m);
    STN res, ln = STQ(lev, x, m, L, l, m), rn = STQ(lev, m, y, R, m, r);
    return res.merge(ln, rn), res;
}
void STU(int lev, int p, int x, int id = 1, int l = 0, int r = MAXN) {
    if (r - l < 2) {
        ST[lev][id] = x;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU(lev, p, x, L, l, m);
    else STU(lev, p, x, R, m, r);
    ST[lev][id].merge(ST[lev][L], ST[lev][R]);
}

vi G[4][MAXN];

int main() {
    FOR(i, 0, 4) FOR(j, 0, 4 * MAXN) ST[i][j].mn = 1e9;
    FOR(i, 0, 4) ri(N[i]);
    FOR(i, 0, 4) FOR(j, 0, N[i]) ri(A[i][j]);
    FOR(i, 0, 3) {
        int mi; ri(mi);
        FOR(_, 0, mi) {
            int a, b; rii(a, b);
            --a, --b;
            G[i][a].pb(b);
        }
    }
    FOR(i, 0, 4) {
        FOR(j, 0, N[i]) {
            G[i][j].pb(-1); G[i][j].pb(MAXN);
            sort(ALL(G[i][j]));
        }
    }
    for (int i = 3; i >= 0; --i) {
        bool pos = false;
        FOR(j, 0, N[i]) {
            int mn = 1e9;
            FOR(k, 0, SZ(G[i][j]) - 1) if (G[i][j][k] + 1 != G[i][j][k + 1]) {
                mn = min(mn, STQ(i + 1, G[i][j][k] + 1, G[i][j][k + 1]).mn);
            }
            STU(i, j, A[i][j] + mn);
            if (mn != 1e9) pos = true;
        }
        if (!pos) {
            printf("-1\n");
            return false;
        }
    }
    printf("%d\n", STQ(0, 0, MAXN).mn);

    return 0;
}