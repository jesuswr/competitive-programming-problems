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
const int MAXN = 1e5 + 20; // CAMBIAR ESTE

// GJNM
int V, E;

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

map<pii, int> mp;
vii G[MAXN];
const int LOGV = 20;
int ANC[MAXN][LOGV + 1];
int IN[MAXN], OUT[MAXN], EDGEC[MAXN][LOGV + 1], T, H[MAXN];
void dfs(int u, int f = -1) {
    if (f == -1)
        ANC[u][0] = u;
    else
        ANC[u][0] = f;
    IN[u] = T++;

    for (int l = 1; l <= LOGV; ++l) {
        ANC[u][l] = ANC[ ANC[u][l - 1] ][l - 1];
        EDGEC[u][l] = max(EDGEC[u][l - 1], EDGEC[ ANC[u][l - 1] ][l - 1]);
    }

    for (auto [v, c] : G[u]) {
        if (v == f)
            continue;
        H[v] = H[u] + 1;
        EDGEC[v][0] = c;
        dfs(v, u);
    }

    OUT[u] = T++;
}

bool is_anc(int a, int b) {
    return IN[a] <= IN[b] && OUT[a] >= OUT[b];
}

int lca(int a, int b) {
    if (is_anc(a, b)) return a;
    if (is_anc(b, a)) return b;

    for (int l = LOGV; l >= 0; --l) {
        if (!is_anc(ANC[a][l], b))
            a = ANC[a][l];
    }
    return ANC[a][0];
}

int TOT;
void solve(int a, int b) {
    int c = lca(a, b);

    int tmp = mp[ {min(a, b), max(a, b)}];

    int mx = 0;

    if (a != c) {
        for (int l = LOGV; l >= 0; --l) {
            if (!is_anc(ANC[a][l], c)) {
                mx = max(mx, EDGEC[a][l]);
                a = ANC[a][l];
            }
        }
        mx = max(mx, EDGEC[a][0]);
    }
    if (b != c) {
        for (int l = LOGV; l >= 0; --l) {
            if (!is_anc(ANC[b][l], c)) {
                mx = max(mx, EDGEC[b][l]);
                b = ANC[b][l];
            }
        }
        mx = max(mx, EDGEC[b][0]);
    }
    printf("%d\n", (TOT - mx) + tmp);
}

int main() {
    rii(V, E);
    priority_queue<tuple<int, int, int>> pq;
    makeSet(0, V - 1);
    FOR(_, 0, E) {
        int a, b, c;
        riii(a, b, c);
        --a, --b;
        mp[ {min(a, b), max(a, b)}] = c;
        pq.push({ -c, a, b});
    }

    while (!pq.empty()) {
        auto [c, a, b] = pq.top(); pq.pop();
        if (find(a) != find(b)) {
            unio(find(a), find(b));
            G[a].pb({b, -c});
            G[b].pb({a, -c});
            TOT -= c;
        }
    }
    dfs(0);

    int q; ri(q);
    while (q--) {
        int a, b; rii(a, b); --a, --b;
        solve(a, b);
    }

    return 0;
}