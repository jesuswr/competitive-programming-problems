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
const int MAXN = 50010; // CAMBIAR ESTE
const int L = 17;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
vi G[MAXN];

int timer;
int tin[MAXN], tout[MAXN], anc[MAXN][ L + 1 ];
int H[MAXN];
void dfs(int v, int p) { // Se inicializa con dfs(1,1)
    tin[v] = ++timer;
    anc[v][0] = p;

    for (int i = 1; i <= L; ++i) anc[v][i] = anc[ anc[v][i - 1] ][i - 1];
    for (int w : G[v]) if (w != p) {
            H[w] = H[v] + 1;
            dfs(w, v);
        }
    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;

    for (int i = L; i >= 0; --i) {
        if (!is_ancestor(anc[u][i], v)) {
            u = anc[u][i];
        }
    }
    return anc[u][0];
}

bool NOT_PRIME[MAXN];
void pre() {
    NOT_PRIME[0] = NOT_PRIME[1] = 1;
    for (int i = 2; i < MAXN; ++i)
        if (!NOT_PRIME[i])
            for (int j = i + i; j < MAXN; j += i) NOT_PRIME[j] = 1;
}


int main() {
    ri(N);
    pre();
    FOR(_, 1, N) {
        int a, b; rii(a, b);
        --a, --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(0, 0);
    int good = 0;
    const long double IT = 1e9;
    FOR(_, 0, IT) {
        int a = rng() % N;
        int b = rng() % N;
        while (a == b) b = rng() % N;
        int dst = H[a] + H[b] - 2 * H[lca(a, b)];
        if (!NOT_PRIME[ dst ])
            good++;
    }
    printf("%.10Lf\n", good / IT);

    return 0;
}