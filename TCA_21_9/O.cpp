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
const int MAXN = 1e5 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M;
int ON[MAXN];
vi G[MAXN];

int father[MAXN], siz[MAXN], col[MAXN];
// n es el primer elemento y m el ultimo, por ejemplo los nodos de un grafo desde el 1 al 10
void makeSet(int n, int m) {
    for (int i = n; i <= m; ++i) {
        father[i] = -1;
        siz[i] = 0;
        col[i] = -1;
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



vi G2[2 * MAXN], G2T[2 * MAXN];
int VIS[2 * MAXN];
stack<int> ord;
int COMP[2 * MAXN];
void dfs(int u) {
    VIS[u] = 1;
    for (auto v : G2[u]) if (VIS[v] == 0) {
            dfs(v);
        }
    ord.push(u);
}
void dfs2(int u, int comp) {
    VIS[u] = 2;
    COMP[u] = comp;
    for (auto v : G2T[u]) if (VIS[v] == 1) {
            dfs2(v, comp);
        }
}

int main() {
    rii(N, M);
    FOR(i, 0, N) ri(ON[i]);
    makeSet(0, M - 1);
    FOR(i, 0, M) {
        int sz; ri(sz);
        FOR(_, 0, sz) {
            int a; ri(a);
            G[a - 1].pb(i);
        }
    }
    FOR(i, 0, N) if (ON[i] == 1) {
        if (find(G[i][0]) != find(G[i][1]))
            unio(find(G[i][0]), find(G[i][1]));
    }

    FOR(i, 0, N) if (ON[i] == 0) {
        int u = find(G[i][0]), v = find(G[i][1]);
        // printf("%d %d\n", u + 1, v + 1);
        G2[2 * u + 1].pb(2 * v);
        G2[2 * u].pb(2 * v + 1);
        G2[2 * v + 1].pb(2 * u);
        G2[2 * v].pb(2 * u + 1);

        G2T[2 * v].pb(2 * u + 1);
        G2T[2 * v + 1].pb(2 * u);
        G2T[2 * u].pb(2 * v + 1);
        G2T[2 * u + 1].pb(2 * v);
    }
    FOR(i, 0, 2 * M) if (VIS[i] == 0) {
        dfs(i);
    }
    int c = 1;
    while (!ord.empty()) {
        if (VIS[ord.top()] == 1)
            dfs2(ord.top(), c++);
        ord.pop();
    }
    FOR(i, 0, M) if (COMP[2 * i] != 0) {
        if (COMP[2 * i] == COMP[2 * i + 1]) {
            printf("NO\n");
            return 0;
        }
    }


    printf("YES\n");
    return 0;
}