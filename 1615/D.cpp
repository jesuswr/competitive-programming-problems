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
const int MAXN = 3e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
struct edge {
    int to, val;
};
int V, M;
int VIS[MAXN];
int COL[MAXN];
vector<edge> G[MAXN], G2[MAXN];

bool dfs(int u, int col, int vis = 1) {
    VIS[u] = vis;
    COL[u] = col;
    for (auto [v, c] : G2[u]) {
        if (VIS[v] == vis) {
            if ((COL[u] ^ c) != COL[v])
                return false;
        }
        else {
            if (dfs(v, COL[u] ^ c, vis) == false)
                return false;
        }
    }
    return true;
}

void dfss(int u = 1, int f = 1) {
    for (auto [v, c] : G[u]) if (v != f) {
            printf("%d %d %d\n", u, v, c == -1 ?  COL[u] ^ COL[v] : c);
            dfss(v, u);
        }
}

void solve() {
    rii(V, M);
    FOR(i, 1, V + 1) {
        VIS[i] = 0;
        G[i].clear();
        G2[i].clear();
    }
    FOR(i, 1, V) {
        int f, t, c;
        riii(f, t, c);
        G[f].pb({t, c});
        G[t].pb({f, c});
        if (c >= 0) {
            G2[f].pb({t, c & 1});
            G2[t].pb({f, c & 1});
        }
    }
    FOR(_, 0, M) {
        int f, t, c;
        riii(f, t, c);
        G2[f].pb({t, c});
        G2[t].pb({f, c});
    }
    FOR(i, 1, V + 1)if (!VIS[i]) {
        bool can = dfs(i, 0);
        if (!can && i > 1)
            can = dfs(i, 1, 2);
        if (!can) {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
    dfss();

}



int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}