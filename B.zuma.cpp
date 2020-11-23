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
const int MAXN = 510; // CAMBIAR ESTE

// GJNM
int n;
int dp[MAXN][MAXN];
int a[MAXN];

int f(int l, int r) {
    if (l > r)
        return 0;
    if (l == r)
        return 1;
    if (dp[l][r] != -1)
        return dp[l][r];

    dp[l][r] = 1 + f(l + 1, r);
    FOR(i, l + 2, r + 1) {
        if (a[i] == a[l])
            dp[l][r] = min(dp[l][r], f(l + 1, i - 1) + f(i + 1, r));
    }
    if (a[l + 1] == a[l])
        dp[l][r] = min(dp[l][r], 1 + f(l + 2, r));
    return dp[l][r];
}

int main() {
    ri(n);
    FOR(i, 0, n) {
        ri(a[i]);
    }
    //memset(dp, -1, sizeof(dp));
    fill(dp[0], dp[0] + MAXN * MAXN, -1);
    printf("%d\n", f(0, n - 1));


    return 0;
}