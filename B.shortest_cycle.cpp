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
const int MAXN = 1e5 + 1; // CAMBIAR ESTE

// GJNM
int n;
ll a[MAXN];
int cnt[65];
vi cnt_ind[65];
set<int> G[MAXN];
vii edges;
int ans = INF;
bool vis[MAXN];
int dist[MAXN];

bool on(ll x, int b) {
    return (x & (1ll << b)) > 0;
}

int bfs(int s, int e) {
    FOR(i, 0, n) vis[i] = false;
    queue<int> ord;

    ord.push(s); vis[s] = true; dist[s] = 0;

    while (!ord.empty()) {
        int x = ord.front(); ord.pop();

        if (x == e)
            return dist[x];

        for (int y : G[x]) {
            if (vis[y])
                continue;
            dist[y] = dist[x] + 1;
            vis[y] = true;
            ord.push(y);
        }
    }
    return INF;
}

int main() {
    ri(n);
    FOR(i, 0, n) {
        rl(a[i]);
        FOR(b, 0, 63) {
            cnt[b] += on(a[i], b);
            if (cnt[b] > 2) {
                printf("3\n");
                return 0;
            }
        }
    }

    FOR(i, 0, n) {
        FOR(b, 0, 63) {
            if (on(a[i], b)) {
                for (auto j : cnt_ind[b]) {
                    G[i].insert(j);
                    G[j].insert(i);
                    edges.pb({i, j});
                }
                cnt_ind[b].pb(i);
            }
        }
    }

    for (auto e : edges) {
        G[e.F].erase(e.S);
        G[e.S].erase(e.F);
        ans = min(ans, bfs(e.F, e.S) + 1);
        G[e.F].insert(e.S);
        G[e.S].insert(e.F);
    }

    if (ans == INF)
        printf("-1\n");
    else
        printf("%d\n", ans);

    return 0;
}