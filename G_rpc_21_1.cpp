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
const ll MOD = 1e9;

// GJNM
ll K, Q;
ll A[MAXN];

ll f(ll b, ll e) {
    if (e == 0) return 1;
    ll ret = f(b, e / 2);
    ret %= MOD;
    ret += MOD;
    ret %= MOD;
    ret = (ret * ret) % MOD;
    if (e & 1) {
        ret = (ret * b) % MOD;
        ret += MOD;
        ret %= MOD;
    }
    return ret;
}


void solve() {
    rll(K, Q);
    FOR(i, 0, K) rl(A[i]);
    while (Q--) {
        ll e; rl(e);
        ll exp = (e / K) + 1;
        ll i = e % K;
        printf("%lld\n", f(A[i], exp));
    }
}

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}