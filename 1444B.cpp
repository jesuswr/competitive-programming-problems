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
const int MAXN = 4e5; // CAMBIAR ESTE
const ll MOD = 998244353;

// GJNM
int n;
ll a[MAXN];
ll fact[MAXN];

ll binpow(ll b, ll e) {
    if (e == 0)
        return 1;
    ll ret = binpow(b, e / 2);
    ret = (ret * ret) % MOD;
    if (e & 1)
        ret = (ret * b) % MOD;
    return ret;
}

int main() {
    ri(n);
    FOR(i, 0, n << 1) {
        rl(a[i]);
    }
    sort(a, a + 2 * n);

    ll sm = 0;
    FOR(i, 0, n << 1) {
        sm += a[i] * (i >= n ? 1 : -1);
    }
    sm = sm % MOD;

    fact[0] = 1;
    FOR(i, 1, 2 * n + 1) {
        fact[i] = (fact[i - 1] * i);
        if (fact[i] >= 10 * MOD)
            fact[i] %= MOD;
    }


    printf("%lld\n", ((( sm * fact[2 * n]  ) % MOD) * (binpow((fact[n] * fact[n]) % MOD, MOD - 2))) % MOD );


    return 0;
}