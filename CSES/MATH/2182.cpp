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
#include <array>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef long double ld;
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
const int MOD = 1e9 + 7;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM

ll binpow(ll b, ll e) {
    ll ret = 1;
    while (e) {
        if (e & 1) ret = (ret * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return ret;
}

ll sum(ll b) {
    return (b * (b + 1)) / 2;
}

int main() {
    int n; ri(n);
    vector<ll> d(n), e(n);
    FOR(i, 0, n) rll(d[i], e[i]);

    ll n_divs = 1, sum_divs = 1, mul_divs = 1, n_divs2 = 1;
    FOR(i, 0, n) {
        mul_divs = binpow(mul_divs, e[i] + 1) * binpow(binpow(d[i], sum(e[i])), n_divs2) % MOD;
        n_divs = (n_divs * (e[i] + 1)) % MOD;
        n_divs2 = (n_divs2 * (e[i] + 1)) % (MOD - 1);
        sum_divs *= (binpow(d[i], e[i] + 1) + MOD - 1);
        sum_divs %= MOD;
        sum_divs *= binpow(d[i] + MOD - 1, MOD - 2);
        sum_divs %= MOD;
    }
    printf("%lld %lld %lld\n", n_divs, sum_divs, mul_divs);
    return 0;
}