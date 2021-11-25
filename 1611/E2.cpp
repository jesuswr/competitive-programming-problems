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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, K;
vi SRCS;
vi G[MAXN];
bool LEAF[MAXN];
int H[MAXN];

int ANC[MAXN][23];
bool MARK[MAXN];
void dfs(int u = 0, int f = -1) {
    LEAF[u] = 1;
    ANC[u][0] = (f == -1 ? u : f);
    FOR(i, 1, 23) ANC[u][i] = ANC[ ANC[u][i - 1] ][i - 1];
    for (auto v : G[u]) if (v != f) {
            LEAF[u] = 0;
            H[v] = H[u] + 1;
            dfs(v, u);
        }
}


vi bfs(vi srcs) {
    vi d(N, 2 * N);
    queue<int> q;
    for (auto u : srcs) {
        q.push(u);
        d[u] = 0;
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : G[u]) {
            if (d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

    return d;
}

void solve() {
    rii(N, K);

    FOR(i, 0, N) G[i].clear();
    FOR(i, 0, N) LEAF[i] = 0;
    FOR(i, 0, N) MARK[i] = 0;
    SRCS.clear();

    FOR(i, 0, K) {
        int a; ri(a);
        SRCS.pb(a - 1);
    }
    FOR(i, 1, N) {
        int a, b; rii(a, b);
        --a; --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs();
    vi aux = {0};

    vi dsts = bfs(aux);
    vi dsts2 = bfs(SRCS);

    FOR(i, 1, N) if (LEAF[i] && dsts[i] < dsts2[i]) {
        printf("-1\n");
        return;
    }



    for (auto u : SRCS) {
        int h = H[u] / 2;
        for (int i = 0; i < 23; ++i) if ((h >> i) & 1) {
                u = ANC[u][i];
            }
        MARK[ u ] = 1;
    }

    vector<bool> vis(N);
    vis[0] = 1;
    queue<int> q; q.push(0);

    int ans = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (MARK[u]) {
            ans++;
            continue;
        }
        for (auto v : G[u]) if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
    }
    printf("%d\n", ans);
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}