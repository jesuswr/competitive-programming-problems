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
const int MAXN = 3e5; // CAMBIAR ESTE

// GJNM
int n, m, k;
vi G[MAXN];
bool vis[2][MAXN];
int dist[2][MAXN];
vi specials;

void bfs(int s, int p) {
    queue<int> ord; ord.push(s);
    vis[p][s] = 1;

    while (!ord.empty()) {
        int x = ord.front(); ord.pop();

        for (auto y : G[x]) {
            if (vis[p][y])
                continue;
            vis[p][y] = 1;
            dist[p][y] = dist[p][x] + 1;
            ord.push(y);
        }
    }
}


int main() {
    riii(n, m, k);
    FOR(i, 0, k) {
        int tmp; ri(tmp); tmp--;
        specials.pb(tmp);
    }
    FOR(_, 0, m) {
        int a, b; rii(a, b);
        G[a - 1].pb(b - 1);
        G[b - 1].pb(a - 1);
    }
    bfs(0, 0); bfs(n - 1, 1);
    int ans = dist[0][n - 1];

    vii data;
    for (auto sp : specials) {
        data.pb({dist[0][sp] - dist[1][sp], sp});
    }
    sort(ALL(data));
    int best = 0, mx = -INF;
    for (auto it : data) {
        int a = it.second;
        best = max(best, mx + dist[1][a]);
        mx = max(mx, dist[0][a]);
    }
    printf("%d\n", min(ans, best + 1));

    return 0;
}