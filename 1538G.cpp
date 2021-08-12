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

// GJNM
void solve() {
    ll x, y, a, b;
    rll(x, y), rll(a, b);
    if (a < b)
        swap(a, b);
    if (a == b) {
        printf("%lld\n", min(x, y) / a);
        return;
    }

    ll lo = 0, hi = 1e10;
    while (lo < hi) {
        ll mi = lo + (hi - lo + 1) / 2;
        ll l = ceill((y - mi * a) * 1.0l / (b - a)), r = floorl((x - mi * b) * 1.0l / (a - b));
        if (max(l, 0ll) <= min(r, mi))
            lo = mi;
        else
            hi = mi - 1;
    }
    printf("%lld\n", lo);
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}