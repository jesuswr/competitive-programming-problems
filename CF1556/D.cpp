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
const int MAXN = 1e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
// Todos los rangos son semi-abiertos [a,b)
int N;
struct STN {
    int sm = 0;
    void merge(STN& L, STN& R) {
        sm = L.sm + R.sm;
    }
    void operator=(int a) {
        sm = a;
    }
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = 0;
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
    int n, m; rii(n, m); N = n * m + 5;
    vii a(n * m);
    FOR(i, 0, n * m) ri(a[i].F), a[i].S = i + 3;
    map<int, queue<int>> val_to_ind;
    set<int> ord;
    FOR(i, 0, n * m) {
        ord.insert(a[i].F);
        val_to_ind[a[i].F].push(a[i].S);
    }


    ll ans = 0;
    FOR(_, 0, n) {
        STB();
        int taken = 0;
        while (taken < m) {
            stack<int> inds;
            int mn = *ord.begin();
            int aux = min(m - taken, SZ(val_to_ind[mn]));
            FOR(___, 0, min(m - taken, aux)) {
                inds.push(val_to_ind[mn].front());
                val_to_ind[mn].pop();
            }
            if (val_to_ind[mn].empty())
                ord.erase(ord.begin());
            while (!inds.empty()) {
                int ind = inds.top(); inds.pop();
                ans += STQ(0, ind).sm;
                STU(ind, 1);
                taken++;
            }
        }
    }
    printf("%lld\n", ans);
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}