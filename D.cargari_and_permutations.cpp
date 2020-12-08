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
const int MAXN = 1010; // CAMBIAR ESTE

// GJNM
int n, k;
int a[5][MAXN];
bool can_go[5][MAXN][MAXN];
int dp[MAXN];

int f(int pos) {
    if (dp[pos] != 0)
        return dp[pos];

    FOR(i, pos + 1, n) {
        bool can = true;
        FOR(j, 0, k) can &= can_go[j][ a[0][pos] ][ a[0][i] ];

        if (can) {
            dp[pos] = max(dp[pos], 1 + f(i));
        }
    }
    return dp[pos] = max(dp[pos], 1);
}

int main() {
    rii(n, k);
    FOR(i, 0, k) FOR(j, 0, n) ri(a[i][j]);
    FOR(i, 0, k) FOR(j, 0, n) a[i][j]--;
    FOR(i, 0, k) FOR(j, 0, n) FOR(l, j + 1, n) can_go[i][ a[i][j] ][ a[i][l] ] = true;

    int ans = 0;
    FOR(i, 0, n) ans = max(ans, f(i));
    printf("%d\n", ans);
    return 0;
}