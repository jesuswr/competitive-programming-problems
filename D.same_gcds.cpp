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
vector<pair<ll, int>> trial_division1(long long n) {
    vector<pair<ll, int>> factorization;
    for (long long d = 2; d * d <= n; d++) {
        int cnt = 0;
        while (n % d == 0) {
            cnt++;
            n /= d;
        }
        if (cnt)
            factorization.pb({d, cnt});
    }
    if (n > 1)
        factorization.push_back({n, 1});
    return factorization;
}

int main() {
    int t;
    ri(t);
    while (t--) {
        ll a, m;
        rll(a, m);

        ll hi = a + m - 1;
        ll lo = a - 1;

        ll gcd = __gcd(a, m);
        m /= gcd;
        vector<pair<ll, int>> fact = trial_division1(m);
        int sz = fact.size();
        ll ans = 0;
        FOR(i, 0, 1 << sz) {
            ll aux_gcd = gcd;
            int cnt = 0;
            FOR(b, 0, sz) {
                if (i & (1 << b)) {
                    aux_gcd *= fact[b].F;
                    cnt++;
                }
            }
            if (cnt & 1)
                ans -= (hi / aux_gcd - lo / aux_gcd);
            else
                ans += (hi / aux_gcd - lo / aux_gcd);
        }
        printf("%lld\n", ans);
    }

    return 0;
}