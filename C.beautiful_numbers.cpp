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
const int MAXN = 2e6; // CAMBIAR ESTE
const ll mod = 1e9 + 7;

// GJNM
int n, a, b;
ll fact[MAXN];

bool good(int x) {
    while (x > 0) {
        int tmp = x % 10;
        if (tmp != a && tmp != b)
            return false;
        x = x / 10;
    }
    return true;
}

ll binpow(ll b, ll e) {
    ll ret = 1;
    while (e > 0) {
        if (e & 1)
            ret = (ret * b) % mod;

        b = (b * b) % mod;
        e = e >> 1;
    }
    return ret;
}

ll pick(int n, int k) {
    ll num = fact[n];
    ll den = (fact[n - k] * fact[k]) % mod;
    den = binpow(den , mod - 2);
    return (num * den) % mod;
}



int main() {
    riii(a, b, n);
    ll ans = 0;
    fact[0] = 1;
    FOR(i, 1, n + 10) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    FOR(i, 0, n + 1) {
        if (good(i * a + (n - i)*b)) {
            ans += pick(n, i);
            if (ans >= 4ll * mod * mod)
                ans %= mod;
        }
    }
    printf("%lld\n", ans % mod);
    return 0;
}