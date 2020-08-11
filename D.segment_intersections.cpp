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
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM

void solve() {
    ll n, k;
    rll(n, k);
    ll l1, r1, l2, r2;
    rll(l1, r1), rll(l2, r2);

    ll ans;
    if ( max(l1, l2) <= min(r1, r2) ) {
        ans = 0;
        k = max(0ll, k - n * ( min(r1, r2) - max(l1, l2) ));
        ans += min(k, n * ((max(r1, r2) - min(l1, l2)) - (min(r1, r2) - max(l1, l2))));
        k -= ans;
        ans += k * 2;
    }
    else {
        ans = LLINF;
        FOR(i, 1, n + 1) {
            ll aux_k = k;
            ll aux_n = i;
            ll aux_ans = (max(l1, l2) - min(r1, r2)) * aux_n;
            aux_ans += min(aux_k, (max(r1, r2) - min(l1, l2)) * aux_n);
            aux_k -= min(aux_k, (max(r1, r2) - min(l1, l2)) * aux_n);
            aux_ans += aux_k * 2;
            ans = min(ans, aux_ans);
        }
    }
    printf("%lld\n", ans);
}



int main() {
    int t;
    ri(t);
    while (t--) {
        solve();
    }

    return 0;
}