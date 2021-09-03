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
const int MAXN = 2010; // CAMBIAR ESTE
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
ll D[MAXN][MAXN];

int father[MAXN], siz[MAXN];
// n es el primer elemento y m el ultimo, por ejemplo los nodos de un grafo desde el 1 al 10
void makeSet(int n, int m) {
    for (int i = n; i <= m; ++i) {
        father[i] = -1;
        siz[i] = 0;
    }
}
int find(int x) {
    if (father[x] == -1) // -1 significa que es el representante del set
        return x;
    return father[x] = find(father[x]);
}
void unio(int x, int y) { // x y y tienen que ser los representantes
    if (siz[x] > siz[y])
        father[y] = x;
    else {
        father[x] = y;
        if ( siz[x] == siz[y] ) siz[y]++;
    }
}

vector<pair<int, ll>> G[MAXN];
int ANC[MAXN][15];
ll H[MAXN];
int tin[MAXN], tout[MAXN], t;
void dfs(int u, int f = 0) {
    tin[u] = t++;
    ANC[u][0] = f;
    FOR(i, 1, 15) ANC[u][i] = ANC[ ANC[u][i - 1] ][i - 1];
    for (auto [v, c] : G[u]) {
        if (v == f)
            continue;
        H[v] = H[u] + c;
        dfs(v, u);
    }
    tout[u] = t++;
}

bool is_ancestor(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;

    for (int i = 14; i >= 0; --i) {
        if (!is_ancestor(ANC[u][i], v)) {
            u = ANC[u][i];
        }
    }
    return ANC[u][0];
}

int main() {
    ri(N);
    FOR(i, 0, N) FOR(j, 0, N) rl(D[i][j]);
    FOR(i, 0, N) if (D[i][i] != 0) {
        printf("NO\n");
        return 0;
    }
    FOR(i, 0, N) FOR(j, i + 1, N) if (D[i][j] != D[j][i] || D[i][j] == 0) {
        printf("NO\n");
        return 0;
    }
    priority_queue<tuple<ll, int, int>> pq;
    FOR(i, 0, N) FOR(j, i + 1, N) pq.push({ -D[i][j], i, j});

    makeSet(0, N - 1);
    while (!pq.empty()) {
        auto [c, a, b] = pq.top(); pq.pop();
        c = -c;
        if (find(a) != find(b)) {
            unio(find(a), find(b));
            G[a].pb({b, c});
            G[b].pb({a, c});
        }
    }

    dfs(0, 0);

    FOR(i, 0, N) FOR(j, i + 1, N) {
        if (D[i][j] != H[i] + H[j] - 2 * H[lca(i, j)]) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}