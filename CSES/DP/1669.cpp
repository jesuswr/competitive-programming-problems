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
const int MAXN = 1e5; // CAMBIAR ESTE
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int V, E;
vi G[MAXN];
bool VIS[MAXN];
int H[MAXN];
int F[MAXN];
int ans;
pii nodes;

void dfs(int u) {
    VIS[u] = true;
    for (auto v : G[u]) {
        if (v == F[u])
            continue;
        if (!VIS[v]) {
            H[v] = H[u] + 1;
            F[v] = u;
            dfs(v);
        }
        else {
            if (H[v] - H[u] > ans) {
                ans = H[v] - H[u];
                nodes = {u, v};
            }
        }
    }
}

int main() {
    rii(V, E);
    FOR(i, 0, E) {
        int a, b; rii(a, b); --a, --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    FOR(i, 0, V) if (!VIS[i]) {
        F[i] = -1;
        dfs(i);
    }

    if (ans < 2)
        printf("IMPOSSIBLE\n");
    else {
        printf("%d\n", ans + 2);
        printf("%d %d ", nodes.F + 1, nodes.S + 1);
        do {
            nodes.S = F[nodes.S];
            printf("%d ", nodes.S + 1);
        } while (nodes.S != nodes.F);
        printf("\n");
    }

    return 0;
}