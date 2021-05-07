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
const int MAXP = 1010; // CAMBIAR ESTE
const ll MOD = 1e9 + 7;

// GJNM
int N, M, P[2];
ll DP[105][MAXP];
ll FACT[MAXP];

ll binpow(ll b, ll e) {
    ll ret = 1;
    while (e) {
        if (e & 1) ret = (ret * b) % MOD;
        e >>= 1;
        b = (b * b) % MOD;
    }
    return ret;
}

ll pick(ll n, ll k) {
    ll num = FACT[n];
    ll div = (FACT[k] * FACT[n - k]) % MOD;
    return (num * binpow(div, MOD - 2)) % MOD;
}

int main() {
    FACT[0] = 1;
    FOR(i, 1, MAXP) FACT[i] = (FACT[i - 1] * i) % MOD;
    rii(N, M), rii(P[0], P[1]);
    DP[0][0] = 1;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= max(P[0], P[1]); ++j)
            for (int k = 1; k <= M; ++k)
                if (j - k >= 0) {
                    DP[i][j] += DP[i - 1][j - k];
                    if (DP[i][j] >= MOD) DP[i][j] -= MOD;
                }

    ll ans = 0;
    for (int take1 = 1; take1 < N; ++take1) {
        for (int take2 = 1; take2 + take1 <= N; take2++) {
            ans += ((DP[take1][P[0]] * DP[take2][P[1]]) % MOD) * ((pick(N, take1) * pick(N - take1, take2)) % MOD);
            ans %= MOD;
        }
    }
    printf("%lld\n", ans);
    return 0;
}