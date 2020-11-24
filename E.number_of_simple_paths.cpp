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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE

// GJNM
int n;
ll sz[MAXN];
vi G[MAXN];
int deg[MAXN];

void solve() {
    ri(n);
    FOR(i, 0, n) {
        int a, b; rii(a, b); a--, b--;
        G[a].pb(b), G[b].pb(a);
        deg[a]++, deg[b]++;
    }

    queue<int> leafs;
    FOR(i, 0, n) {
        sz[i] = 1;
        if (deg[i] == 1)
            leafs.push(i);
    }
    while (!leafs.empty()) {
        int x; x = leafs.front(); leafs.pop();
        deg[x] = 0;
        for (auto y : G[x]) {
            if (deg[y] > 1) {
                deg[y]--;
                sz[y] += sz[x];
            }

            if (deg[y] == 1)
                leafs.push(y);
        }
    }
    ll ans = 0;
    FOR(i, 0, n) {
        if (deg[i] > 1) {
            ans += (sz[i] * (sz[i] - 1)) / 2 + (n - sz[i]) * sz[i];
        }
    }
    printf("%lld\n", ans);


    FOR(i, 0, n) {
        G[i].clear();
        deg[i] = 0;
    }
}


int main() {
    int tt;
    ri(tt);
    while (tt--)
        solve();

    return 0;
}