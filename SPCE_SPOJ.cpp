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
const int MOD = 1e9 + 7;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int V, E;

int father[MAXN], siz[MAXN], nodes[MAXN];
// n es el primer elemento y m el ultimo, por ejemplo los nodos de un grafo desde el 1 al 10
void makeSet(int n, int m) {
    for (int i = n; i <= m; ++i) {
        father[i] = -1;
        siz[i] = 0;
        nodes[i] = 1;
    }
}
int find(int x) {
    if (father[x] == -1) // -1 significa que es el representante del set
        return x;
    return father[x] = find(father[x]);
}
void unio(int x, int y) { // x y y tienen que ser los representantes
    if (siz[x] > siz[y]) {
        father[y] = x;
        nodes[x] += nodes[y];
    }
    else {
        father[x] = y;
        nodes[y] += nodes[x];
        if ( siz[x] == siz[y] ) siz[y]++;
    }
}

ll binpow(ll b, ll e) {
    ll r = 1;
    while (e) {
        if (e & 1) r = (r * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return r;
}

void solve() {
    rii(V, E);
    makeSet(0, V - 1);
    int CC = V;
    FOR(_, 0, E) {
        int u, v; rii(u, v);
        --u; --v;
        u = find(u); v = find(v);
        if (u != v) {
            CC--;
            unio(u, v);
        }
    }
    if (CC == 1) {
        printf("-1\n");
        return;
    }

    ll ans = 1;
    FOR(u, 0, V) if (u == find(u))
        ans = (ans * nodes[u]) % MOD;

    ans = (ans * binpow(V, CC - 2)) % MOD;
    printf("%lld\n", ans);
}


int main() {
    int t; ri(t);
    while (t--)
        solve();
    return 0;
}