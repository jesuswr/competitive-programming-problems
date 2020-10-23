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
const ll LLINF = 1e16;
const int MAXN = 6e5; // CAMBIAR ESTE

// GJNM
int n;
ll a[MAXN];
ll dp[MAXN][2][2];
ll vis[MAXN][2][2];

ll f(int p, int pos, int neg) {
    if (p == n) {
        if (pos && neg)
            return 0;
        else
            return -LLINF;
    }
    if (vis[p][pos][neg])
        return dp[p][pos][neg];
    vis[p][pos][neg] = true;

    return dp[p][pos][neg] = max(f(p + 1, 1, neg) + a[p], f(p + 1, pos, 1) - a[p]);
}


int main() {
    ri(n);
    FOR(i, 0, n) {
        rl(a[i]);
    }
    if (n != 1)
        printf("%lld\n", f(0,0,0));
    else
        printf("%lld\n", a[0]);
    return 0;
}