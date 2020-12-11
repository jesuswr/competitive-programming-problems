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
const ll MOD = 1e9 + 7;

// GJNM
ll binpow(ll b, ll e) {
    ll ret = 1;
    while (e > 0) {
        if (e & 1)
            ret = (ret * b) % MOD;

        b = (b * b) % MOD;
        e >>= 1;
    }
    return ret;
}

int main() {
    ll x, k; rll(x, k);
    if (x == 0) {
        printf("0\n");
        return 0;
    }
    if (k == 0) {
        printf("%lld\n", (x * 2) % MOD );
        return 0;
    }
    x = x % MOD;
    ll mx = (x * binpow(2, k + 1)) % MOD;
    ll mn = (mx - (binpow(2, k + 1) - 1) + 1 + MOD) % MOD;
    ll num = (mx + mn) % MOD;
    printf("%lld\n", (num * binpow(2, MOD - 2)) % MOD);
    return 0;
}