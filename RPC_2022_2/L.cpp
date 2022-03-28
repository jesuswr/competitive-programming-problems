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
void mini(ll &a, ll b) {
    a = min(a, b);
}

void solve() {
    ll d, l, s;
    rll(d, l); rl(s);
    ll hl = 0, hs = 0;
    ll pl = INF, ps = INF;
    ll ans = 0;
    FOR(_, 0, d) {
        ll c, _pl, _ps; rll(c, _pl); rl(_ps);
        mini(pl, _pl);
        mini(ps, _ps);

        hl -= l * c;
        hs -= s * c;
        if (hl < 0) {
            ans += abs(hl) * pl;
            hl = 0;
        }
        if (hs < 0) {
            ll need = ( (abs(hs) + 16 * 5 - 1) / (16 * 5));
            ans += need * ps;
            hs += need * 16 * 5;
        }
    }
    printf("%lld\n", ans );
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}