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
const int MAXN = 2e5; // CAMBIAR ESTE

// GJNM
int n, m;
vi G[MAXN];
vii undir, dir;
int deg[MAXN];
int order[MAXN];

void clean() {
    FOR(i, 0, n) {
        G[i].clear();
        order[i] = 0;
        deg[i] = 0;
    }
    undir.clear(); dir.clear();
}

void solve() {
    rii(n, m);
    FOR(_, 0, m) {
        int t, x, y; riii(t, x, y); --x, --y;
        if (t == 1) {
            dir.pb({x, y});
            G[x].pb(y);
            deg[y]++;
        }
        else
            undir.pb({x, y});
    }

    queue<int> topo;
    FOR(i, 0, n) {
        if (deg[i] == 0)
            topo.push(i);
    }

    int t = 1;
    while (!topo.empty()) {
        int x = topo.front(); topo.pop();
        order[x] = t++;
        for (auto y : G[x]) {
            deg[y]--;
            if (deg[y] == 0)
                topo.push(y);
        }
    }
    FOR(i, 0, n) {
        if (order[i] == 0) {
            clean();
            printf("NO\n");
            return;
        }
    }

    printf("YES\n");
    for (auto p : dir) {
        printf("%d %d\n", p.F + 1, p.S + 1);
    }
    for (auto p : undir) {
        if (order[p.F] > order[p.S])
            swap(p.S, p.F);
        printf("%d %d\n", p.F + 1, p.S + 1);
    }

    clean();
}

int main() {
    int t;
    ri(t);
    while (t--)
        solve();

    return 0;
}