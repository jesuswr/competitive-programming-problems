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
int N, Q, A[MAXN];
struct STN {
    int lft, rgt;
    void merge(STN& L, STN& R) {
        lft = min(L.lft, R.lft);
        rgt = min(L.rgt, R.rgt);
    }
    void operator=(int a) {
        lft = A[a] - a;
        rgt = A[a] + a;
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
void STU(int p,  int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = p;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU(p, L, l, m);
    else STU(p, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}

int main() {
    rii(N, Q);
    FOR(i, 0, N) ri (A[i + 1]);
    A[0] = A[N + 1] = 1e9;
    N += 2;
    STB();
    while (Q--) {
        int t; ri(t);
        if (t == 1) {
            int k, Ak; rii(k, Ak);
            A[k] = Ak;
            STU(k);
        }
        else {
            int p; ri(p);
            auto lft = STQ(0, p), rgt = STQ(p, N);
            printf("%d\n", min(lft.lft + p, rgt.rgt - p));
        }
    }
    return 0;
}