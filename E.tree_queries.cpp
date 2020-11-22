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
int n, m;
vi G[MAXN];
int fv[MAXN];
int t;

int father[MAXN], height[MAXN], lo[MAXN], hi[MAXN];

bool comp(int a, int b) {
    return height[a] < height[b];
}

void dfs(int v, int f) {
    father[v] = f;
    lo[v] = t++;
    for (auto u : G[v]) {
        if (u == f)
            continue;
        height[u] = height[v] + 1;
        dfs(u, v);
    }
    hi[v] = t++;
}

int main() {
    rii(n, m);
    FOR(i, 1, n) {
        int a, b; rii(a, b); a--, b--;
        G[a].pb(b); G[b].pb(a);
    }
    dfs(0, 0);

    while (m--) {
        int k; ri(k);
        FOR(i, 0, k) {
            ri(fv[i]); fv[i]--;
        }
        sort(fv, fv + k, comp);
        FOR(i, 0, k - 1) {
            fv[i] = father[fv[i]];
        }
        bool ans = true;
        FOR(i, 0, k - 1) {
            ans &= lo[fv[i]] <= lo[fv[i + 1]] && hi[fv[i + 1]] <= hi[fv[i]];
        }
        if (ans)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}