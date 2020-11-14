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
#define all(s) s.begin(),s.end()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1010; // CAMBIAR ESTE

// GJNM
int n, k;
ll dp[MAXN][MAXN];
bool vis[MAXN][MAXN];

ll w[MAXN], h[MAXN];

ll f(int pos, int box) {
    if (pos == n && box == k)
        return 0;
    if (pos == n || box == k)
        return LLINF;
    if (vis[pos][box])
        return dp[pos][box];
    vis[pos][box] = true;
    ll ws = 0, hs = 0;

    ll &ret = dp[pos][box] = LLINF;

    FOR(i, pos, n) {
        ws += w[i];
        hs = max(hs, h[i]);
        ret = min(ret, ws * hs + f(i + 1, box + 1));
    }
    return ret;
}

int main() {
    rii(n, k);
    FOR(i, 0, n) {
        rll(w[i], h[i]);
    }

    printf("%lld\n", f(0, 0));

    return 0;
}