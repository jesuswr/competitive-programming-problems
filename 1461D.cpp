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

// GJNM
// Todos los rangos son semi-abiertos [a,b)
int N, A[MAXN];
struct STN {
    ll mn, mx, sm;
    void merge(STN& L, STN& R) {
        mn = min(L.mn, R.mn);
        mx = max(L.mx, R.mx);
        sm = L.sm + R.sm;
    }
    void operator=(int a) {
        mn = mx = sm = a;
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

set<ll> can_get;

void precompute(int l, int r) {
    if (l >= r)
        return;
    auto node = STQ(l, r);
    can_get.insert(node.sm);

    int mid = (node.mx + node.mn) / 2;
    auto m = upper_bound(A + l, A + r, mid) - A;
    if (m != l)
        precompute(m, r);
    if (m != r)
        precompute(l, m);
}

void solve() {
    can_get.clear();
    int q;
    rii(N, q);
    FOR(i, 0, N) {
        ri(A[i]);
    }
    sort(A, A + N);
    STB();
    precompute(0, N);

    while (q--) {
        ll qi; rl(qi);
        if (can_get.count(qi))
            printf("Yes\n");
        else
            printf("No\n");
    }
}

int main() {
    int t; ri(t);
    while (t--)
        solve();



    return 0;
}