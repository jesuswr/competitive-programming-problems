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
const int maxN = 3e5; // CAMBIAR ESTE

// GJNM
ll n, m;
ll x, k, y;
ll a[maxN], b[maxN];
map<ll, ll> index_of;

ll solve(ll left, ll right, ll mx) {
    if ( right - left == -1 ) {
        return 0ll;
    }
    //printf("%d %d %d\n", left, right, mx);

    ll ret = max(x, y) * maxN;

    ll rge_mx = 0;
    FOR(i, left, right + 1) {
        rge_mx = max(rge_mx, (ll)a[i]);
    }
    int n_x = 1;
    if ( rge_mx < mx ) {
        n_x = 0;
    }
    else if ( rge_mx > mx && (right + 1 - left) < k ) {
        printf("-1\n");
        exit(0);
    }

    while ( n_x * k <= right + 1 - left ) {
        ret = min(ret, n_x * x + ((right + 1 - left) - (n_x * k)) * y);
        n_x++;
    }
    //printf("%lld\n", ret);
    return ret;
}

int main() {
    rll(n, m);
    if ( m > n ) {
        printf("-1\n");
        return 0;
    }
    rll(x, k); rl(y);
    FOR(i, 0, n) {
        rl(a[i]);
        index_of[a[i]] = i;
    }
    FOR(i, 0, m) {
        rl(b[i]);
        if ( index_of.find(b[i]) == index_of.end() ) {
            printf("-1\n");
            return 0;
        }
        if ( i > 0 && index_of[b[i - 1]] > index_of[b[i]] ) {
            printf("-1\n");
            return 0;
        }
    }

    ll ans = 0;
    FOR(i, 0, m + 1) {
        if ( i == 0 ) {
            ans += solve(0, index_of[b[i]] - 1, b[i]);
        }
        else if ( i == m  ) {
            ans += solve(index_of[b[i - 1]] + 1, n - 1, b[i - 1]);
        }
        else {
            ans += solve(index_of[b[i - 1]] + 1, index_of[b[i]] - 1, max(b[i - 1], b[i]));
        }
    }

    printf("%lld\n", ans);

    return 0;
}