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
const int MAXN = 2e5 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
// Todos los rangos son semi-abiertos [a,b)
int N, K;
int A[MAXN][5];
struct STN {
    int MN[1 << 5], MX[1 << 5];
    int MX_D;
    void merge(STN& L, STN& R, int l = 0, int r = 0) {
        MX_D = 0;
        FOR(i, 0, 1 << K) {
            MN[i] = min(L.MN[i], R.MN[i]);
            MX[i] = max(L.MX[i], R.MX[i]);
            MX_D = max(MX_D, MX[i] - MN[i]);
        }
    }
    void operator=(int a) {
        MX_D = 0;
        FOR(i, 0, 1 << K) {
            MN[i] = MX[i] = 0;
            FOR(b, 0, K) {
                int mult = (i >> b) & 1 ? 1 : -1;
                MN[i] += mult * A[a][b];
                MX[i] += mult * A[a][b];
            }
        }
    }
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = l;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STB(L, l, m); STB(R, m, r);
    ST[id].merge(ST[L], ST[R], l, r);
}
STN STQ(int x, int y, int id = 1, int l = 0, int r = N) {
    if (x == l && y == r) return ST[id];
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (x >= m) return STQ(x, y, R, m, r);
    if (y <= m) return STQ(x, y, L, l, m);
    STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
    return res.merge(ln, rn), res;
}
void STU(int p, int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = p;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU(p, L, l, m);
    else STU(p, R, m, r);
    ST[id].merge(ST[L], ST[R], l, r);
}

int main() {
    rii(N, K);
    FOR(i, 0, N) FOR(j, 0, K) ri(A[i][j]);
    STB();
    int Q; ri(Q);
    while (Q--) {
        int t; ri(t);
        if (t == 1) {
            int i; ri(i); --i;
            FOR(j, 0, K) ri(A[i][j]);
            STU(i);
        }
        else {
            int l, r; rii(l, r);
            printf("%d\n", STQ(l - 1, r).MX_D);
        }
    }

    return 0;
}