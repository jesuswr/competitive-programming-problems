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
const int MAXN = 4e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM



int N, Q, l = 23; // l = log(n)
int A[MAXN];
vector<int> G[MAXN];

int timer; // Tiempos de entrada y salida de cada nodo y su ancestro a dist 2**i
int tin[MAXN], tout[MAXN], anc[MAXN][ 23 + 1 ];

ll BIT[MAXN];
// suma de rangos [0,n-1]
void updBIT(int p, ll val) {
    p++;    // esto es porque el bit esta indexado desde 1
    for (; p < MAXN; p += p & -p) // se puede cambiar maxN por n+5 si hace falta mas velocidad
        BIT[p] += val;
}
ll sumBIT(int p) {
    p++;
    ll ret = 0;
    for (; p; p -= p & -p)
        ret += BIT[p];
    return ret;
}

int F[MAXN];
void dfs(int v, int p) { // Se inicializa con dfs(1,1)
    tin[v] = ++timer;
    anc[v][0] = p;
    F[v] = p;
    for (int i = 1; i <= l; ++i) anc[v][i] = anc[ anc[v][i - 1] ][i - 1];
    for (int w : G[v]) if (w != p) dfs(w, v);

    tout[v] = ++timer;

    updBIT(tin[v], 2 * abs(A[v]));
    updBIT(tout[v], -2 * abs(A[v]));
}

bool is_ancestor(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;

    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(anc[u][i], v)) {
            u = anc[u][i];
        }
    }
    return anc[u][0];
}


int main() {
    rii(N, Q);
    FOR(i, 0, N) ri(A[i]);
    FOR(i, 1, N) {
        int a, b; rii(a, b);
        G[a - 1].pb(b - 1);
        G[b - 1].pb(a - 1);
    }
    dfs(0, 0);

    while (Q--) {
        int t; ri(t);
        if (t == 1) {
            int v, c; rii(v, c); --v;

            updBIT(tin[v], -2 * abs(A[v]));
            updBIT(tout[v], 2 * abs(A[v]));
            A[v] = c;
            updBIT(tin[v], 2 * abs(A[v]));
            updBIT(tout[v], -2 * abs(A[v]));
        }
        else {
            int u, v; rii(u, v); --u, --v;
            printf("%lld\n", sumBIT(tin[u]) + sumBIT(tin[v]) -
                   (lca(u, v) != 0 ? sumBIT(tin[F[lca(u, v)]]) : 0)
                   - sumBIT(tin[lca(u, v)]) - abs(A[u]) - abs(A[v]));
            // printf("%lld %lld\n", sumBIT(tin[u]), sumBIT(tin[v]));
        }
    }

    return 0;
}