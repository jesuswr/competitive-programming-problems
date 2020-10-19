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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int n;
vi G[MAXN];
int height[MAXN];
bool is_leaf[MAXN];
bool is_father_of_leaf[MAXN];

void dfs_1(int v, int f = -1) {
    is_leaf[v] = true;

    for (auto u : G[v]) {
        if (u == f)
            continue;
        is_leaf[v] = false;
        height[u] = height[v] + 1;
        dfs_1(u, v);
        if (is_leaf[u])
            is_father_of_leaf[v] = true;
    }
}


int main() {
    ri(n);
    int root;
    FOR(i, 1, n) {
        int a, b;
        rii(a, b); a--, b--;
        G[a].pb(b);
        G[b].pb(a);
        if (G[a].size() > 1)
            root = a;
        if (G[b].size() > 1)
            root = b;
    }

    dfs_1(root);
    int mn = 3;
    int par[2] = {0, 0};
    FOR(i, 0, n) {
        if (is_leaf[i])
            par[height[i] & 1]++;
    }
    if (par[0] == 0 || par[1] == 0)
        mn = 1;

    int mx = n - 1;
    FOR(i, 0, n) {
        if (is_leaf[i])
            mx--;
        if (is_father_of_leaf[i])
            mx++;
    }
    printf("%d %d\n", mn, mx);
    return 0;
}