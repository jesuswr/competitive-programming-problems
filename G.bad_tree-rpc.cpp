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
const ll LLINF = 2e18;
const int MAXN = 110; // CAMBIAR ESTE

// GJNM
ll dp[MAXN][MAXN];

ll f(int l, int r) {
    if (l == r)
        return dp[l][r] = 1;
    if (dp[l][r] != -1)
        return dp[l][r];
    return dp[l][r] = min(f(l + 1, r) + f(l, r - 1), LLINF);
}

vi ans;

void reconstruct(int l, int r, ll k) {
    if (l == r) {
        ans.pb(l);
        return;
    }
    if (dp[l + 1][r] >= k) {
        ans.pb(l);
        reconstruct(l + 1, r, k);
    }
    else {
        ans.pb(r);
        reconstruct(l, r - 1, k - dp[l + 1][r]);
    }
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n;
    ri(n);
    f(1, n);
    ll k; rl(k);

    if (k > f(1, n)) {
        printf("%d\n", -1);
        return 0;
    }

    reconstruct(1, n, k);
    FOR(i, 0, ans.size()) {
        printf("%d", ans[i]);
        if (i < ans.size() - 1)
            printf(" ");
    }
    printf("\n");

    return 0;
}