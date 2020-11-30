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
const int MAXN = 2600; // CAMBIAR ESTE
const ll mod = 1e9 + 7;

// GJNM
int N, K;
ll dp[MAXN][MAXN];

ll f(int n, int k) {
    if (k == 0)
        return 0;
    if (k == 1)
        return n == 1;
    if (k > n)
        return 0;
    if (dp[n][k] != -1)
        return dp[n][k];

    dp[n][k] = (k * f(n - 1, k - 1) + (k - 1) * f(n - 1, k)) % mod;
    //printf("%d %d : %lld\n", n - 1, k - 1, f(n - 1, k - 1));
    //printf("%d %d : %lld\n", n - 1, k , f(n - 1, k ));
    //printf("%d %d : %lld\n", n, k, dp[n][k]);
    //printf("\n");
    return dp[n][k];
}

int main() {
    rii(N, K);
    FOR(i, 0, MAXN) {
        FOR(j, 0, MAXN) {
            dp[i][j] = -1;
        }
    }
    printf("%lld\n", f(N, K));

    return 0;
}