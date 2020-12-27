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
const int MAXN = 3e5; // CAMBIAR ESTE

// GJNM
ll s[MAXN];

bool valid(ll k, ll t) {
    vector<ll> b;
    FOR(i, 0, k) b.pb(s[i]);
    reverse(ALL(b));
    ll mx = 0;
    FOR(i, 0, k) mx = max(mx, i + 1 + b[i]);
    return mx <= t;
}

void solve() {
    ll n, m, a, b; rll(n, m), rll(a, b);
    FOR(i, 0, m) rl(s[i]);
    sort(s, s + m);

    ll can = min(abs(a - b) - 1, m);
    ll time;
    if (a < b) time = b - 1;
    else time = n - b;

    ll lo = 0, hi = can;
    while (lo < hi) {
        ll mi = lo + (hi - lo + 1) / 2;
        if (valid(mi, time)) lo = mi;
        else hi = mi - 1;
    }

    printf("%lld\n", lo);
}


int main() {
    int t; ri(t);
    while (t--)
        solve();

    return 0;
}