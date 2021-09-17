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
int K[MAXN];
vi G[MAXN], GI[MAXN];

stack<int> ORD;
int VIS[MAXN];
void dfs1(int u) {
    VIS[u] = 1;
    for (auto v : G[u]) {
        if (VIS[v] == 1)
            continue;
        dfs1(v);
    }
    ORD.push(u);
}
int CMP[MAXN];
void dfs2(int u, int cmp) {
    CMP[u] = cmp;
    VIS[u] = 2;
    for (auto v : GI[u]) {
        if (VIS[v] == 2)
            continue;
        dfs2(v, cmp);
    }
}

vi SCC[MAXN];
ll SM[MAXN];

ll DP[MAXN];
ll f(int u) {
    if (DP[u] != 0)
        return DP[u];
    DP[u] = SM[u];
    for (auto v : SCC[u])
        DP[u] = max(DP[u], SM[u] + f(v));
    return DP[u];
}

int main() {
    rii(N, M);
    FOR(i, 0, N) ri(K[i]);
    FOR(_, 0, M) {
        int a, b; rii(a, b);
        G[a - 1].pb(b - 1);
        GI[b - 1].pb(a - 1);
    }
    FOR(i, 0, N) if (VIS[i] == 0)
        dfs1(i);
    int cmp = 0;
    while (!ORD.empty()) {
        if (VIS[ORD.top()] == 1)
            dfs2(ORD.top(), cmp++);
        ORD.pop();
    }

    FOR(i, 0, N) {
        SM[CMP[i]] += K[i];
        for (auto v : G[i]) if (CMP[i] != CMP[v])
                SCC[CMP[i]].pb(CMP[v]);
    }
    ll ans = 0;
    FOR(i, 0, cmp) ans = max(ans, f(i));
    printf("%lld\n", ans);
    return 0;
}