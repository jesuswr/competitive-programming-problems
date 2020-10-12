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
const ll MOD = 1e9 + 7;

// GJNM
ll dp[110][2];
bool vis[110][2];
int n, k, d;

ll f(int a, int b) {
    if (a < 0 || (a == 0 && b == 0))
        return 0;
    if (a == 0 && b == 1)
        return 1;
    if (vis[a][b])
        return dp[a][b];
    vis[a][b] = true;
    FOR(i, 1, d) {
        dp[a][b] += f(a - i, b);
        dp[a][b] %= MOD;
    }
    FOR(i, d, k + 1) {
        dp[a][b] += f(a - i, 1);
        dp[a][b] %= MOD;
    }
    return dp[a][b];
}


int main() {
    riii(n, k, d);
    printf("%lld\n", f(n, 0));
    return 0;
}