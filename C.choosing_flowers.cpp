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
const int MAXN = 1e5 + 1; // CAMBIAR ESTE

// GJNM
ll n, m;
pair<ll, ll> ab[MAXN];
ll pre[MAXN];

void solve() {
    rll(n, m);
    FOR(i, 0, m) {
        rll(ab[i].F, ab[i].S);
    }

    sort(ab, ab + m, greater<pair<ll, ll>>());

    pre[0] = ab[0].F;
    FOR(i, 1, m) {
        pre[i] = ab[i].F + pre[i - 1];
    }

    ll ans = 0;
    FOR(i, 0, m) {
        ll lo = 0, hi = min(n, m);
        while (lo < hi) {
            ll mi = lo + ((hi - lo + 1) >> 1);
            if (ab[mi - 1].F > ab[i].S)
                lo = mi;
            else
                hi = mi - 1;
        }
        if (lo == 0) {
            ans = max(ans, ab[i].F + ab[i].S * (n - 1));
        }
        else if (lo == n) {
            ans = max(ans, pre[n - 1]);
        }
        else {
            ll lft = n - lo;
            if (i < lo) {
                ans = max(ans, pre[lo - 1] + ab[i].S * (n - lo));
            }
            else {
                ans = max(ans, pre[lo - 1] + ab[i].S * (n - lo - 1) + ab[i].F);
            }
        }

    }
    printf("%lld\n", ans);
}


int main() {
    int t; ri(t);
    while (t--)
        solve();
    return 0;
}