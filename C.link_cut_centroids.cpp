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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
int v;
vi G[MAXN];
int sz[MAXN];
set<int> centroids;
int mx;

void dfs_sz(int x, int f = -1) {
    sz[x] = 1;
    for (auto y : G[x]) {
        if (y == f)
            continue;
        dfs_sz(y, x);
        sz[x] += sz[y];
    }
}

void dfs_centroids(int x, int f = -1) {
    int mxx = -1;
    for (auto y : G[x]) {
        if (y == f)
            continue;
        dfs_centroids(y, x);
        mxx = max(mxx, sz[y]);
    }
    mxx = max(mxx, sz[1] - sz[x]);

    if (mxx < mx) {
        mx = mxx;
        centroids.clear();
        centroids.insert(x);
    }
    else if (mxx == mx) {
        centroids.insert(x);
    }
}

int dfs_leaf(int x, int f) {
    for (auto y : G[x]) {
        if (y == f)
            continue;
        return dfs_leaf(y, x);
    }
    return x;
}

void solve() {
    ri(v);
    FOR(i, 1, v) {
        int x, y; rii(x, y);
        G[x].pb(y);
        G[y].pb(x);
    }

    dfs_sz(1);
    centroids.clear();
    mx = INF;
    dfs_centroids(1);

    if (centroids.size() == 1) {
        printf("1 %d\n", G[1][0]);
        printf("1 %d\n", G[1][0]);
    }
    else {
        vi cents;
        for (auto x : centroids) {
            cents.pb(x);
        }
        int ans;
        for (auto y : G[cents[0]]) {
            if (y != cents[1]){
                ans = y;
                break;
            }
        }
        printf("%d %d\n", ans, cents[0]);
        printf("%d %d\n", ans, cents[1]);
    }


    FOR(i, 1, v + 1) {
        G[i].clear();
    }
}



int main() {
    int t;
    ri(t);
    while (t--)
        solve();

    return 0;
}