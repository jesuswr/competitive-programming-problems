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
const int MAXN = 1e5 + 1; // CAMBIAR ESTE

// GJNM
int n;
int a[MAXN];
int dp[MAXN];
int dp2[MAXN];

int main() {
    ri(n);
    FOR(i, 0, n) {
        ri(a[i]);
    }
    dp[n - 1] = 1;
    ROF(i, n - 2, -1) {
        if (a[i] < a[i + 1])
            dp[i] = 1 + dp[i + 1];
        else
            dp[i] = 1;
    }
    dp2[0] = 1;
    FOR(i, 1, n) {
        if (a[i] > a[i - 1])
            dp2[i] = dp2[i - 1] + 1;
        else
            dp2[i] = 1;
    }
    int ans = 0;
    FOR(i, 0, n) {
        ans = max(ans, dp[i]);
        if (i > 0)
            ans = max(ans, dp[i] + 1);
        if (i > 1) {
            if (a[i] - a[i - 2] >= 2) {
                ans = max(ans, dp[i] + 1 + dp2[i - 2]);
            }
        }
        if (i + dp[i] < n)
            ans = max(ans, dp[i] + 1);
        if (i + dp[i] < n - 1) {
            if (a[i + dp[i] + 1] - a[i + dp[i] - 1] >= 2) {
                ans = max(ans, dp[i] + 1 + dp[i + dp[i] + 1]);
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}