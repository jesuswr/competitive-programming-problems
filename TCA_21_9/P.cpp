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
int N, K;
vii G[MAXN];
int D[MAXN], F[MAXN];

void bfs(const vi &s) {
    FOR(i, 0, N) {
        D[i] = 1e9 + 69; // jeje
        F[i] = -1;
    }
    queue<int> q;
    for (auto u : s) {
        q.push(u);
        D[u] = 0;
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto [v, c] : G[u]) {
            if (D[v] <= 1e9)
                continue;
            F[v] = u;
            D[v] = D[u] + c;
            q.push(v);
        }
    }
}

int IN[MAXN], OUT[MAXN], T, C[MAXN];
void dfs(int u, int f = -1) {
    IN[u] = T++;
    F[u] = f;
    // printf("%d %d %d %d\n", u + 1, F[u] + 1, C[u], D[u]);
    for (auto [v, c] : G[u]) if (v != f) {
            C[v] = c;
            dfs(v, u);
        }
    OUT[u] = T++;
}

// Todos los rangos son semi-abiertos [a,b)
struct STN {
    int mx;
    void merge(STN& L, STN& R) {
        mx = max(L.mx, R.mx);
    }
    void operator=(ll a) {
        mx += a;
    }
};
STN ST[4 * MAXN];
ll lzy[4 * MAXN];
// Actualiza el nodo y guarda en lazy
void upd(int id, int l, int r, ll x) {
    lzy[id] += x;
    ST[id].mx += x;
}
// Propaga el update en lazy
void shift(int id, int l, int r) {
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    upd(L, l, m, lzy[id]);
    upd(R, m, r, lzy[id]);
    lzy[id] = 0;
}
STN STQ(int x, int y, int id = 1, int l = 0, int r = T) {
    if (x == l && y == r) return ST[id];
    shift(id, l, r);
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (x >= m) return STQ(x, y, R, m, r);
    if (y <= m) return STQ(x, y, L, l, m);
    STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
    return res.merge(ln, rn), res;
}
void STU(int x, int y, int v, int id = 1, int l = 0, int r = T) {
    if (x >= r || y <= l) return;
    if (x <= l && y >= r) {
        upd(id, l, r, v);
        return;
    }
    shift(id, l, r);
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STU(x, y, v, L, l, m);
    STU(x, y, v, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}


int main() {
    rii(N, K);
    FOR(i, 1, N) {
        int u, v, d; riii(u, v, d);
        G[u - 1].pb({v - 1, d});
        G[v - 1].pb({u - 1, d});
    }
    vi s;
    s.pb(0);
    bfs(s);
    int mxi = 0;
    FOR(i, 1, N) if (D[i] > D[mxi]) mxi = i;
    bfs({mxi});
    s.clear();
    mxi = 0;
    FOR(i, 1, N) if (D[i] > D[mxi]) mxi = i;
    while (mxi != -1) {
        s.pb(mxi);
        mxi = F[mxi];
    }
    bfs(s);
    dfs(s[0]);

    FOR(i, 0, N) {
        STU(IN[i], IN[i] + 1, D[i]);
        // printf("\t%d : %d %d : %d\n", i + 1, IN[i], IN[i] + 1, D[i]);
    }

    FOR(i, K, SZ(s)) {
        // printf("%d (%d, %d) %d \n", s[i] + 1, IN[s[i]], OUT[s[i]], STQ(IN[s[i]], OUT[s[i]]).mx);
        STU(IN[s[i]], OUT[s[i]], C[s[i]]);
        // printf("%d (%d, %d) %d \n", s[i] + 1, IN[s[i]], OUT[s[i]], STQ(IN[s[i]], OUT[s[i]]).mx);
    }

    int ans = STQ(0, T).mx;
    int l = 0;
    FOR(_, 0, SZ(s) - K) {
        l++;
        STU(IN[s[0]], OUT[s[0]], C[s[l]]);
        STU(IN[s[l]], OUT[s[l]], -C[s[l]]);
        int r = l + K - 1;
        STU(IN[s[r]], OUT[s[r]], -C[s[r]]);
        ans = min(ans, STQ(0, T).mx);
    }
    printf("%d\n", ans);

    return 0;
}