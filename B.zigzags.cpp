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
const int MAXN = 3010; // CAMBIAR ESTE

// GJNM
ll dp[MAXN][MAXN];
ll a[MAXN];
int n;

int query(int a, int b, int c, int d) {
    ll ret = dp[c][d];
    if (a > 0)
        ret -= dp[a - 1][d];
    if (b > 0)
        ret -= dp[c][b - 1];
    if (a > 0 && b > 0)
        ret += dp[a - 1][b - 1];
    return ret;
}


void solve() {
    ri(n);
    FOR(i, 0, n) {
        rl(a[i]);
        FOR(j, 0, n) {
            dp[i][j] = 0;
        }
    }

    FOR(i, 0, n) {
        FOR(j, i + 1, n) {
            dp[j][i] = (a[i] == a[j]);
        }
    }

    FOR(i, 0, n) {
        FOR(j, 0, n) {
            if (i > 0)
                dp[i][j] += dp[i - 1][j];
            if (j > 0)
                dp[i][j] += dp[i][j - 1];
            if (i > 0 && j > 0)
                dp[i][j] -= dp[i - 1][j - 1];
        }
    }
    ll ans = 0;
    FOR(i, 0, n) {
        FOR(j, i + 2, n) {
            if (a[i] == a[j]) {
                ans += query(j + 1, i + 1, n - 1, j - 1);
            }
        }
    }
    printf("%lld\n", ans);
}


int main() {
    int t;
    ri(t);
    while (t--)
        solve();

    return 0;
}