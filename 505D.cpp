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
const int MAXN = 2e5 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M;
int father[MAXN], siz[MAXN], cyc[MAXN], cnt[MAXN];
// n es el primer elemento y m el ultimo, por ejemplo los nodos de un grafo desde el 1 al 10
void makeSet(int n, int m) {
    for (int i = n; i <= m; ++i) {
        father[i] = -1;
        siz[i] = 0;
        cnt[i] = 1;
    }
}
int find(int x) {
    if (father[x] == -1) // -1 significa que es el representante del set
        return x;
    return father[x] = find(father[x]);
}
void unio(int x, int y) { // x y y tienen que ser los representantes
    if (x == y)
        return;
    if (siz[x] > siz[y]) {
        cnt[x] += cnt[y];
        cyc[x] |= cyc[y];
        father[y] = x;
    }
    else {
        cnt[y] += cnt[x];
        cyc[y] |= cyc[x];
        father[x] = y;
        if ( siz[x] == siz[y] ) siz[y]++;
    }
}
vi G[MAXN];
int V[MAXN];
void dfs(int u) {
    V[u] = 1;
    for (auto v : G[u]) {
        if (V[v] == 0) {
            unio(find(u), find(v));
            dfs(v);
        }
        else if (V[v] == 1) 
            cyc[find(u)] = 1;
        else 
            unio(find(u), find(v));
    }
    V[u] = 2;
}

int main() {
    rii(N, M);
    makeSet(0, N - 1);
    FOR(i, 0, M) {
        int a, b; rii(a, b);
        G[a - 1].pb(b - 1);
    }
    FOR(i, 0, N) if (V[i] == 0)
        dfs(i);

    ll ans = 0;
    FOR(i, 0, N) if (i == find(i)) {
        if (cyc[i])
            ans += cnt[i];
        else
            ans += cnt[i] - 1;
    }
    printf("%lld\n", ans);
    return 0;
}