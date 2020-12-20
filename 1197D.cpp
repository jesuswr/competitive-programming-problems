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
const int MAXN = 3e5 + 10; // CAMBIAR ESTE

// GJNM
int n, m, k;
int a[MAXN];
bool vis[MAXN];
ll dp[MAXN];

ll f(int p) {
    if (p == n)
        return 0;
    if (p > n)
        return -LLINF;
    if (vis[p])
        return dp[p];
    vis[p] = true;
    dp[p] = 0;
    ll sm = 0;
    FOR(i, p, p + m) {
        sm += a[i];
        dp[p] = max(dp[p], sm - k);
    }
    dp[p] = max(dp[p], sm - k + f(p + m));
    return dp[p];
}

int main() {
    riii(n, m, k);
    FOR(i, 0, n) ri(a[i]);
    ll ans = 0;
    FOR(i, 0, n) ans = max(ans, f(i));
    printf("%lld\n", ans);
    return 0;
}
