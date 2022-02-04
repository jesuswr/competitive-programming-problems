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
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
ll M;

ll f(ll x) {
    ll lo = 1, hi = 1e5;
    while (lo < hi) {
        ll mi = lo + (hi - lo + 1) / 2;
        if (mi * mi * mi <= x)
            lo = mi;
        else
            hi = mi - 1;
    }
    return lo;
}
ll g(ll x) {
    return x * x * x;
}

pair<ll, ll> go(ll m, ll steps, ll val) {
    if (m == 0)
        return {steps, val};
    ll a = f(m);
    auto ans = go(m - g(a), steps + 1, val + g(a));
    if (a - 1 >= 0)
        ans = max(ans, go(g(a) - 1 - g(a - 1), steps + 1, val + g(a - 1)));
    return ans;
}

int main() {
    rl(M);
    auto ans = go(M, 0, 0);
    printf("%lld %lld\n", ans.F, ans.S);
    return 0;
}