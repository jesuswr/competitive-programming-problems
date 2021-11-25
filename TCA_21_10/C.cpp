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
vi G[MAXN], GI[MAXN];
stack<int> O;
int V[MAXN], C[MAXN], NC;
vi COMP[MAXN];
void dfs(int u) {
    V[u] = 1;
    for (auto v : G[u]) if (V[v] == 0)
            dfs(v);
    O.push(u);
}
void dfs2(int u, int cmp) {
    V[u] = 2;
    C[u] = cmp;
    COMP[cmp].pb(u);
    for (auto v : GI[u]) if (V[v] == 1)
            dfs2(v, cmp);
}

map<pii, int> DP;
void dfs3(int u, int s, int l) {
    V[u] = 1;
    // printf("\t\t\t%d %d %d %d\n", u + 1, s + 1, l, C[s]);
    DP[ {s, u}] = max(DP[ {s, u}], l);
    for (auto v : G[u]) if (V[v] == 0 && C[u] == C[v])
            dfs3(v, s, l + 1);
    V[u] = 0;
}

void brute_force(int cmp) {
    FOR(i, 0, SZ(COMP[cmp])) dfs3(COMP[cmp][i], COMP[cmp][i], 1);
}

int DP2[MAXN], DP3[MAXN];
void solve() {
    // printf("%d\n", NC);
    FOR(cmp, 0, NC) {
        for (int i : COMP[cmp]) for (int j : COMP[cmp]) {
                DP3[j] = max(DP3[j], DP2[i] + DP[ {i, j}]);
                // printf("\t\t%d %d : %d %d %d\n", i + 1, j + 1, DP3[j], DP2[i], DP[ {i, j}]);
            }
        for (int i : COMP[cmp]) {
            DP2[i] = max(DP3[i], 1);
            // printf("\t%d %d\n", i + 1, DP2[i]);
            for (auto j : G[i]) if (C[i] != C[j]) {
                    // printf("\t\t%d\n", j + 1);
                    DP2[j] = max(DP2[j], DP2[i]);
                }
        }
        // printf("\n");
    }
}

int main() {
    rii(N, M);
    FOR(_, 0, M) {
        int a, b; rii(a, b);
        G[a - 1].pb(b - 1);
        GI[b - 1].pb(a - 1);
    }
    FOR(i, 0, N) if (V[i] == 0) dfs(i);
    while (!O.empty()) {
        int i = O.top(); O.pop();
        if (V[i] == 1) dfs2(i, NC++);
    }
    FOR(i, 0, N) V[i] = 0;
    FOR(i, 0, NC) brute_force(i);
    solve();
    int ans = 0;
    FOR(i, 0, N) ans = max(ans, DP2[i]);
    printf("%d\n", ans);
    return 0;
}