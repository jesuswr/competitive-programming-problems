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
const int MAXN = 2e6; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
vi G[MAXN];
int X[MAXN];

int IN[MAXN], OUT[MAXN], H[MAXN], T;
void dfs(int u) {
    IN[u] = T++;
    for (int v : G[u]) {
        H[v] = H[u] + 1;
        dfs(v);
    }
    OUT[u] = T;
}
const int MOD = 11092019;
bool cmp(int u, int v) {
    if (X[u] != X[v])
        return X[u] > X[v];
    return H[u] > H[v];
}

// Todos los rangos son semi-abiertos [a,b)
int A[MAXN];
struct STN {
    ll mx = 0, cnt = 0;
    void merge(STN& L, STN& R) {
        if (L.mx == R.mx) {
            mx = L.mx;
            cnt = L.cnt + R.cnt;
            cnt %= MOD;
        }
        else if (L.mx > R.mx) {
            mx = L.mx;
            cnt = L.cnt;
        }
        else if (R.mx > L.mx) {
            mx = R.mx;
            cnt = R.cnt;
        }
    }
    void operator=(int a) {
        mx = a;
        cnt = 1;
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
void STU(int p, int x, int y, int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id].mx = x;
        ST[id].cnt = y;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU(p, x, y, L, l, m);
    else STU(p, x, y, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}


int main() {
    ri(N);
    FOR(i, 0, N) ri(X[i]);
    FOR(i, 1, N) {
        int p; ri(p); --p;
        G[p].pb(i);
    }
    dfs(0);
    vi ord;
    FOR(i, 0, N) ord.pb(i);
    sort(ALL(ord), cmp);
    int mx = 0;
    ll cnt = 0;
    N = T;
    for (auto i : ord) {
        auto node = STQ(IN[i], OUT[i]);
        STU(IN[i], node.mx + 1, node.cnt == 0 ? 1 : node.cnt);
        if (mx < node.mx + 1) {
            mx = node.mx + 1;
            cnt = 0;
        }
        if (mx == node.mx + 1) {
            cnt += node.cnt == 0 ? 1 : node.cnt;
            cnt %= MOD;
        }
    }
    printf("%d %lld\n", mx, cnt);
    return 0;
}