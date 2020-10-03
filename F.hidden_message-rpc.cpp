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
const ll MOD = 1000000007;

// GJNM
int n[4];
char s[4][310];
ll dp[110][110][110];
bool vis[110][110][110];

ll f(int a, int b, int c) {
    if (a + b + c == n[3])
        return 1;
    if (vis[a][b][c])
        return dp[a][b][c];
    vis[a][b][c] = true;
    ll &ret = dp[a][b][c] = 0;
    int d = a + b + c;

    if (s[3][d] == s[0][a])
        ret = (ret + f(a + 1, b, c)) % MOD;
    if (s[3][d] == s[1][b])
        ret = (ret + f(a, b + 1, c)) % MOD;
    if (s[3][d] == s[2][c])
        ret = (ret + f(a, b, c + 1)) % MOD;

    return ret;
}

int main() {
    FOR(i, 0, 4) {
        scanf("%s", s[i]);
        n[i] = strlen(s[i]);
        s[i][n[i]] = '?';
    }

    if (n[0] + n[1] + n[2] != n[3]) {
        printf("0\n");
        return 0;
    }

    printf("%lld\n", f(0, 0, 0));


    return 0;
}