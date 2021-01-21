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
const ll MAXN = 2e5 + 1; // CAMBIAR ESTE
const ll MOD = 1e9 + 7;

// GJNM
ll N;
ll CNT[MAXN], PRE[MAXN], SUF[MAXN];

ll binpow(ll b, ll e) {
    ll ret = 1;
    while (e > 0) {
        if (e & 1) ret = (1ll * ret * b) % MOD;
        e >>= 1;
        b = (1ll * b * b) % MOD;
    }
    return ret;
}

int main() {
    rl(N);
    FOR(i, 0, N) {
        ll tmp; rl(tmp);
        ++CNT[tmp];
    }
    for (ll i = 0; i < MAXN; i++) {
        PRE[i] = CNT[i] + 1;
        if (i > 0) PRE[i] = (1ll * PRE[i] * PRE[i - 1]) % (MOD - 1);
    }
    for (ll i = MAXN - 1; i >= 0; i--) {
        SUF[i] = CNT[i] + 1;
        if (i + 1 < MAXN) SUF[i] = (1ll * SUF[i] * SUF[i + 1]) % (MOD - 1);
    }
    ll ans = 1;
    for (ll i = 0; i < MAXN; i++) {
        ll cnt = 0;
        for (ll j = 0; j <= CNT[i]; j++) cnt = (cnt + j) % (MOD - 1);
        if (i > 0) cnt = (1ll * cnt * PRE[i - 1]) % (MOD - 1);
        if (i + 1 < MAXN) cnt = (1ll * cnt * SUF[i + 1]) % (MOD - 1);
        ans = (1ll * ans * binpow(i, cnt)) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}