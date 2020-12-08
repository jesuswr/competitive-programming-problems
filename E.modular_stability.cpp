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
const int MAXN = 5e5 + 2; // CAMBIAR ESTE
const ll MOD = 998244353;

// GJNM
ll fact[MAXN];

ll bpow(ll b, int e) {
    ll ret = 1;
    while (e > 0) {
        if (e & 1)
            ret = (ret * b) % MOD;

        b = (b * b) % MOD;
        e >>= 1;
    }
    return ret;
}

ll pick(int n, int k) {
    if (k > n)
        return 0;
    ll num = fact[n];
    ll den = bpow( (fact[k] * fact[n - k]) % MOD , MOD - 2 );
    return (num * den) % MOD;
}

int main() {
    fact[0] = 1;
    FOR(i, 1, MAXN) fact[i] = (fact[i - 1] * i) % MOD;
    int n, k;
    rii(n, k);

    ll ans = 0;
    FOR(i, 1, n + 1) {
        int ops = n / i - 1;
        ans += pick(ops, k - 1);
        if (ans >= MOD)
            ans -= MOD;
    }
    printf("%lld\n", ans);
    return 0;
}