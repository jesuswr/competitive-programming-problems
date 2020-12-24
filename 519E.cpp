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
const int MAXN = 1e5 + 20; // CAMBIAR ESTE

// GJNM
const int LOGN = 18;
int n, m;
int t;
int IN[MAXN], OUT[MAXN], ANC[MAXN][LOGN], H[MAXN], SZ[MAXN];
vi G[MAXN];

void dfs_lca(int x, int f = 0) {
    IN[x] = t++;
    ANC[x][0] = f;
    SZ[x] = 1;
    for (int l = 1; l < LOGN; l++) ANC[x][l] = ANC[ ANC[x][l - 1] ][l - 1];
    for (auto y : G[x]) {
        if (y == f)
            continue;
        H[y] = H[x] + 1;
        dfs_lca(y, x);
        SZ[x] += SZ[y];
    }
    OUT[x] = t;
}

bool is_ancester(int x, int y) {
    return IN[x] <= IN[y] && OUT[y] <= OUT[x];
}

int lca(int x, int y) {
    if (H[x] > H[y]) swap(x, y);
    if (is_ancester(x, y)) return x;
    for (int l = LOGN - 1; l >= 0; l--) if (!is_ancester(ANC[x][l], y)) x = ANC[x][l];
    return ANC[x][0];
}

int dist(int a, int b) {
    return H[a] + H[b] - 2 * H[lca(a, b)];
}

int main() {
    ri(n);
    FOR(_, 1, n) {
        int a, b; rii(a, b); a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs_lca(0);

    ri(m);
    while (m--) {
        int a, b; rii(a, b), --a, --b;
        if (H[a] < H[b]) swap(a, b); // a is lower than b
        if (a == b) {
            printf("%d\n", n);
            continue;
        }
        int d = dist(a, b);
        if (d & 1) {
            printf("0\n");
            continue;
        }
        d >>= 1;
        int c = a;
        for (int l = 0; l < LOGN; l++) if (d & (1 << l)) c = ANC[c][l];
        int ans = SZ[c];
        if (is_ancester(c, a)) {
            int tmp = a;
            int aux_d = dist(tmp, c) - 1;
            for (int l = 0; l < LOGN; l++) if (aux_d & (1 << l)) tmp = ANC[tmp][l];
            ans -= SZ[tmp];
        }
        if (is_ancester(c, b)) {
            int tmp = b;
            int aux_d = dist(tmp, c) - 1;
            for (int l = 0; l < LOGN; l++) if (aux_d & (1 << l)) tmp = ANC[tmp][l];
            ans -= SZ[tmp];
        }
        if (H[a] == H[b]) {
            ans += n - SZ[c];
        }
        printf("%d\n", ans);
    }
    return 0;
}