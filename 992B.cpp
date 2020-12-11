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
#include <assert.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

int dadsadasda;

#define ri(a) dadsadasda=scanf("%d", &a)
#define rii(a,b) dadsadasda=scanf("%d %d", &a, &b)
#define riii(a,b,c) dadsadasda=scanf("%d %d %d", &a, &b, &c)
#define rl(a) dadsadasda=scanf("%lld", &a)
#define rll(a,b) dadsadasda=scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int)s.size()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM

int main() {
    ll l, r, gcd, lcm; rll(l, r), rll(gcd, lcm);
    if (lcm % gcd) {
        printf("0\n");
        return 0;
    }

    ll extra = lcm / gcd;
    vector<pair<ll, ll>> fact;
    for (ll i = 2; i * i <= extra; i++) {
        if (extra % i == 0) {
            int cnt = 0;
            while (extra % i == 0) {
                extra = extra / i;
                cnt++;
            }
            fact.pb({i, cnt});
        }
    }
    if (extra > 1)
        fact.pb({extra, 1});

    ll ans = 0;
    ll sz = SZ(fact);
    FOR(mask, 0, 1 << sz) {
        ll a = gcd, b = gcd;
        FOR(i, 0, sz) {
            if (mask & (1 << i)) {
                FOR(j, 0, fact[i].S) {
                    a *= fact[i].F;
                }
            }
            else {
                FOR(j, 0, fact[i].S) {
                    b *= fact[i].F;
                }
            }
        }
        if (min(a, b) >= l && max(a, b) <= r)
            ans++;
    }
    printf("%lld\n", ans);
    return 0;
}