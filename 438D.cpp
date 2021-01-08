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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
// Todos los rangos son semi-abiertos [a,b)
int N, M, A[MAXN];
struct STN {
    ll sm, mx;
    void merge(STN& L, STN& R) {
        sm = L.sm + R.sm;
        mx = max(L.mx, R.mx);
    }
    void operator=(int a) {
        sm = mx = a;
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
void STU(int x, int y, ll c, int id = 1, int l = 0, int r = N) {
    if (x >= r || y <= l) return;
    if (r - l < 2) {
        ST[id].mx %= c;
        ST[id].sm %= c;
        return;
    }
    if (ST[id].mx < c) return;
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STU(x, y, c, L, l, m);
    STU(x, y, c, R, m, r);
    ST[id].merge(ST[L], ST[R]); 
}
void STU2(int p, int x, int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = x;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU2(p, x, L, l, m);
    else STU2(p, x, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}


int main() {
    rii(N, M);
    FOR(i, 0, N) ri(A[i]);
    STB();
    FOR(_, 0, M) {
        int t; ri(t);
        if (t == 1) {
            int l, r; rii(l, r);
            printf("%lld\n", STQ(l - 1, r).sm);
        }
        else if (t == 2) {
            int l, r, x; riii(l, r, x);
            STU(l - 1, r, x);
        }
        else {
            int k, x; rii(k, x);
            STU2(k - 1, x);
        }
    }
    return 0;
}