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
const int MAXN = 501; // CAMBIAR ESTE

// GJNM
int n, m, b, mod;
int a[MAXN];
int dp[2][MAXN][MAXN];


//f(pos, bugs, line) = (f(pos - 1, bugs, line) + f(pos, bugs - a[b], line - 1));



int main() {
    rii(n, m), rii(b, mod);
    FOR(i, 0, n) {
        ri(a[i + 1]);
    }
    dp[0][0][0] = 1;

    FOR(pos, 1, n + 1) {
        int curr = pos & 1;
        int prev = 1 - curr;
        FOR(bugs, 0, b + 1) {
            FOR(line, 0, m + 1) {
                dp[curr][bugs][line] = dp[prev][bugs][line];
                if (bugs - a[pos] >= 0 && line > 0)
                    dp[curr][bugs][line] += dp[curr][bugs - a[pos]][line - 1];
                if (dp[curr][bugs][line] >= mod)
                    dp[curr][bugs][line] -= mod;
            }
        }
    }
    int ans = 0;
    FOR(i, 0, b + 1) {
        ans += dp[n & 1][i][m];
        if (ans >= mod)
            ans -= mod;
    }
    printf("%d\n", ans);
    return 0;
}