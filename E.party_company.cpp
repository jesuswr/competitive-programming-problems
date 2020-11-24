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
int N, M, l = 25;
vi G[MAXN];
int A[MAXN];
int anc[MAXN][26];
piii P[MAXN];
vii P2[MAXN];
void dfs_anc(int v, int p) { // Se inicializa con dfs(1,1)
    anc[v][0] = p;
    for (int i = 1; i <= l; ++i) anc[v][i] = anc[ anc[v][i - 1] ][i - 1];
    for (int w : G[v]) if (w != p) dfs_anc(w, v);
}

ll BIT[MAXN];
// suma de rangos [0,n-1]
void updBIT(int p, ll val) {
    p++;    // esto es porque el bit esta indexado desde 1
    for (; p < MAXN; p += p & -p) // se puede cambiar maxN por n+1 si hace falta mas velocidad
        BIT[p] += val;
}
ll sumBIT(int p) {
    p++;
    ll ret = 0;
    for (; p; p -= p & -p)
        ret += BIT[p];
    return ret;
}

int ans[MAXN];

void dfs(int x) {
    for (auto p : P2[x]) {
        updBIT(p.F, 1);
    }

    ans[x] = sumBIT(A[x]);
    for (auto y : G[x])
        dfs(y);

    for (auto p : P2[x]) {
        updBIT(p.F, -1);
    }
}


int main() {
    rii(N, M);
    A[0] = INF;
    FOR(i, 0, N) {
        int a, f; rii(a, f);
        A[i + 1] = a;
        if (i != 0) {
            G[f].pb(i + 1);
        }
    }
    dfs_anc(1, 1);
    FOR(i, 0, M) {
        riii(P[i].F, P[i].S.F, P[i].S.S);
        for (int j = l; j >= 0; j--) {
            if (A[ anc[P[i].F][j] ] <= P[i].S.S)
                P[i].F = anc[P[i].F][j];
        }
        P2[ P[i].F ].pb({P[i].S.F, P[i].S.S});
    }

    dfs(1);

    FOR(i, 1, N + 1) {
        printf("%d ", ans[i]);
    } printf("\n");

    return 0;
}