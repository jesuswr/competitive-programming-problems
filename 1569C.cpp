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
const int MAXN = 3e5; // CAMBIAR ESTE
const ll MOD = 998244353;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
ll F[MAXN];
void pre() {
    F[0] = 1;
    FOR(i, 1, MAXN) F[i] = (F[i - 1] * i) % MOD;
}

ll binpow(ll b, ll e) {
    ll r = 1;
    while (e) {
        if (e & 1) r = (r * b) % MOD;
        e >>= 1;
        b = (b * b) % MOD;
    }
    return r;
}

ll pick(ll n, ll k) {
    ll num = F[n];
    ll den = (F[k] * F[n - k]) % MOD;
    return (num * binpow(den, MOD - 2)) % MOD;
}

pii get_mx(const vi &a) {
    pii ret = { -1, -1};
    for (auto x : a) {
        if (x > ret.F) {
            ret.S = ret.F;
            ret.F = x;
        }
        else if (x > ret.S)
            ret.S = x;
    }
    return ret;
}
int get_cnt(const vi &a, int x) {
    int ret = 0;
    for (auto y : a) ret += x == y;
    return ret;
}

void solve() {
    int n; ri(n);
    vi a(n);
    FOR(i, 0, n) ri(a[i]);
    pii mx = get_mx(a);

    if (mx.F - mx.S == 0)
        printf("%lld\n", F[n]);
    else if (mx.F - mx.S > 1)
        printf("0\n");
    else {
        int cnt = get_cnt(a, mx.S);
        ll bad = 0;
        for (int l = 0; l <= n - cnt - 1; ++l) {
            ll add = (pick(n - cnt - 1, l) * F[l + cnt]) % MOD;
            add = (add * F[n - cnt - 1 - l]) % MOD;
            bad = (bad + add) % MOD;
        }
        printf("%lld\n", (F[n] - bad + MOD) % MOD);
    }
}

int main() {
    pre();
    int t; ri(t);
    while (t--)
        solve();
    return 0;
}