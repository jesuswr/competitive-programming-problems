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
const int MAXN = 2e5; // CAMBIAR ESTE

// GJNM
int V, E;
vi G[MAXN];

pii bfs(int s) {
    vector<bool> vis(V, false);
    vector<int> dis(V, false);
    queue<int> ord;

    vis[s] = true;
    ord.push(s);

    int v;
    while (!ord.empty()) {
        v = ord.front();
        ord.pop();

        for (auto u : G[v]) {
            if (!vis[u]) {
                vis[u] = true;
                ord.push(u);
                dis[u] = dis[v] + 1;
            }
        }
    }

    FOR(i, 0, V) if (!vis[i]) {
        printf("-1\n");
        exit(0);
    }

    return {v, dis[v]};
}

int main() {
    rii(V, E);
    FOR(_, 0, E) {
        int a, b; rii(a, b); --a; --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    auto [a, da] = bfs(0);
    auto [b, db] = bfs(a);

    int ans = 0;
    while (db > 0) {
        ans++;
        db /= 2;
    }
    cout << ans << endl;
    return 0;
}