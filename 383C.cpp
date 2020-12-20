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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE

// GJNM
int N, A[MAXN];
int t;
int v[MAXN];
int h[MAXN], in[MAXN], out[MAXN];
vi G[MAXN];

void dfs(int x, int f = -1) {
    A[t] = v[x];
    in[x] = t++;

    for (auto u : G[x]) {
        if (u == f)
            continue;
        h[u] = h[x] + 1;
        dfs(u, x);
    }

    out[x] = t;
}

// Todos los rangos son semi-abiertos [a,b)
struct STN {
    int lzy[2] = {0, 0};
};
STN ST[4 * MAXN];
int STQ(int p, int *x, int aux, int id = 1, int l = 0, int r = N) {
    x[0] += ST[id].lzy[0];
    x[1] += ST[id].lzy[1];
    if (l == r - 1)
        return A[l] + x[aux] - x[1 - aux];

    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p >= m) return STQ(p, x, aux, R, m, r);
    else return STQ(p, x, aux, L, l, m);
}
void STU(int ql, int qr, int *x, int id = 1, int l = 0, int r = N) {
    if (l == ql && qr == r) {
        ST[id].lzy[0] += x[0];
        ST[id].lzy[1] += x[1];
        return;
    }

    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (qr <= m) STU(ql, qr, x, L, l, m);
    else if (ql >= m) STU(ql, qr, x, R, m, r);
    else {
        STU(ql, m, x, L, l, m);
        STU(m, qr, x, R, m, r);
    }
}

int main() {
    int m;
    rii(N, m);
    FOR(i, 0, N) {
        ri(v[i]);
    }
    FOR(i, 1, N) {
        int a, b; rii(a, b); a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(0);

    while (m--) {
        int T, x; rii(T, x); x--;
        if (T == 1) {
            int val; ri(val);
            int aux[2] = {0, 0};
            aux[h[x] & 1] = val;
            STU(in[x], out[x], aux);
        }
        else {
            int aux[2] = {0, 0};
            printf("%d\n", STQ(in[x], aux, h[x] & 1));
        }
    }

    return 0;
}