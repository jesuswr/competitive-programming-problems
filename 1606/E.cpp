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
const int MAXN = 610; // CAMBIAR ESTE
const ll MOD = 998244353ll;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
ll F[MAXN];
void pre() {
    F[0] = F[1] = 1;
    FOR(i, 2, MAXN) F[i] = (F[i - 1] * 1ll * i) % MOD;
}

ll binpow(ll b, ll e) {
    assert(b >= 0 && e >= 0);
    ll r = 1;
    while (e) {
        if (e & 1ll) r = (r * b) % MOD;
        e >>= 1;
        b = (b * b) % MOD;
    }
    return r;
}

ll pick(ll n, ll k) {
    assert(n < MAXN && k < MAXN);
    assert(n >= 0 && k >= 0);
    if (k > n) return 0;
    ll num = F[n];
    ll den = binpow(((F[n - k] * F[k]) % MOD), MOD - 2);
    return ((num * den) % MOD);
}

ll DP[MAXN][MAXN];
ll f(int n, int b) {
    assert(n < MAXN && b < MAXN);
    assert(n >= 0);
    if (b <= 0) {
        // printf("\t\t\t%d %d : %d\n", n, b, 0);
        return 0;
    }
    if (DP[n][b] != -1)
        return DP[n][b];
    if (n == 1) {
        // printf("\t%d %d %d\n", n, b, 0);
        return DP[n][b] = b;
    }
    if (n == 0) {
        // printf("\t\t%d %d : %d\n", n, b, 1);
        return DP[n][b] = 0;
    }

    DP[n][b] = 0;
    for (int s = 0; s <= n; ++s) {
        DP[n][b] += (((pick(n, s) * binpow(n - 1, s)) % MOD) * f(n - s, b - n + 1)) % MOD;
        DP[n][b] %= MOD;
    }
    // printf("%d %d : %lld\n", n, b, DP[n][b]);
    return DP[n][b] % MOD;
}

int main() {
    pre();
    FOR(i, 0, MAXN) FOR(j, 0, MAXN) DP[i][j] = -1;
    int n, x; rii(n, x);
    printf("%lld\n", ( ( (binpow(x, n) - f(n, x)) % MOD ) + MOD ) % MOD);
    return 0;
}