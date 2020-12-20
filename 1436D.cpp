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
pair<ll, ll> operator+(pair<ll, ll> a, pair<ll, ll> b) {
    return {a.F + b.F, a.S + b.S};
}

int n;
vi G[MAXN];
ll a[MAXN];
ll ans;


pair<ll, ll> dfs(int x, int f = -1) {
    pair<ll, ll> p = {0, a[x]};
    bool is_leaf = true;
    for (auto y : G[x]) {
        if (y == f)
            continue;
        p = p + dfs(y, x);
        is_leaf = false;
    }
    if (is_leaf)
        p.F = 1;
    ans = max(ans, (p.S + p.F - 1) / p.F);
    return p;
}

int main() {
    ri(n);
    FOR(i, 1, n) {
        int tmp; ri(tmp); tmp--;
        G[tmp].pb(i);
    }
    FOR(i, 0, n) rl(a[i]);
    dfs(0);
    printf("%lld\n", ans);
    return 0;
}