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
const int MAXN = 5010; // CAMBIAR ESTE

// GJNM
int n, k, m;
ll dp[MAXN][MAXN];
ll a[MAXN];
ll pre[2 * MAXN];

ll pick(int pos) {
    ll ret = pre[pos + m - 1];
    if (pos > 0)
        ret -= pre[pos - 1];
    return ret;
}

ll f(int p, int left) {
    if (left == 0) {
        if ( p <= n)
            return 0;
        else
            return -(1e15);
    }
    if (p >= n) {
        return -LLINF;
    }
    if (dp[p][left] != -1)
        return dp[p][left];
    return dp[p][left] = max(f(p + 1, left), f(p + m, left - 1) + pick(p));
}



int main() {
    riii(n, m, k);
    FOR(i, 0, n) {
        rl(a[i]);
    }
    pre[0] = a[0];
    FOR(i, 1, n) {
        pre[i] = a[i] + pre[i - 1];
    }
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", f(0, k));
    return 0;
}