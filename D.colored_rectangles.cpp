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

// GJNM
int R, G, B;
ll r[210], g[210], b[210];
ll dp[210][210][210];

ll f(int rr, int gg, int bb) {
    if (dp[rr][gg][bb] != -1)
        return dp[rr][gg][bb];
    ll &ret = dp[rr][gg][bb] = 0;

    if (rr < R && gg < G)
        ret = max(ret, f(rr + 1, gg + 1, bb) + r[rr] * g[gg]);
    if (rr < R && bb < B)
        ret = max(ret, f(rr + 1, gg, bb + 1) + r[rr] * b[bb]);
    if (gg < G && bb < B)
        ret = max(ret, f(rr, gg + 1, bb + 1) + g[gg] * b[bb]);
    return ret;
}



int main() {
    riii(R, G, B);
    FOR(i, 0, R) {
        rl(r[i]);
    }
    FOR(i, 0, G) {
        rl(g[i]);
    }
    FOR(i, 0, B) {
        rl(b[i]);
    }
    sort(r, r + R, greater<ll>());
    sort(g, g + G, greater<ll>());
    sort(b, b + B, greater<ll>());

    memset(dp, -1, sizeof(dp));
    printf("%lld\n", f(0, 0, 0));

    return 0;
}