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

using namespace std;

typedef long long ll;
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

// GJNM
vi G[MAXN];
int t, comp;
int low[MAXN], disc[MAXN];
bool vis[MAXN];
int C[MAXN];
stack<int> st;

void tarjan(int u) {
    low[u] = disc[u] = t++;
    vis[u] = true;
    st.push(u);

    for (auto v : G[u]) {
        if ( low[v] == -1 )
            tarjan(v);
        if ( vis[v] )
            low[u] = min(low[u], low[v]);
    }

    if ( low[u] == disc[u] ) {
        while (1) { // Los que salgan de la pila en este ciclo son de la misma comp
            int v = st.top();
            st.pop();
            vis[v] = false;
            C[v] = comp;

            if ( u == v )
                break;
        }
        comp++;
    }
}

int n, m, s;
int GC[MAXN];

int main() {
    riii(n, m, s); s--;
    FOR(_, 0, m) {
        int u, v; rii(u, v); u--, v--;
        G[u].pb(v);
    }
    FOR(i, 0, n) {
        low[i] = disc[i] = -1;
    }
    FOR(i, 0, n) {
        if (low[i] == -1)
            tarjan(i);
    }
    FOR(u, 0, n) {
        for (auto v : G[u]) {
            if (C[u] != C[v])
                GC[C[v]]++;
        }
    }
    int ans = 0;
    FOR(i, 0, comp) {
        if (i == C[s])
            continue;
        ans += GC[i] == 0;
    }
    printf("%d\n", ans);
    return 0;
}