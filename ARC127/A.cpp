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
ll poww(ll b, ll e) {
    ll ret = 1;
    FOR(i, 0, e) ret *= b;
    return ret;
}

ll h(string n, int l, int r) {
    ll ret = 0;
    FOR(i, l, r) {
        ret *= 10;
        ret += n[i] - '0';
    }
    return ret + 1;
}

ll g(string n, int ones) {
    bool gt = 0;
    FOR(i, 0, ones) {
        if (n[i] < '1' && !gt)
            return 0;
        else if (n[i] > '1')
            gt = 1;
    }
    if (ones == SZ(n)) {
        return ones;
    }
    else {
        ll ret = 0;
        for (int d = 0; d < 10; ++ d) {
            if (d == 1)
                continue;
            if (gt || (n[ones] - '0') > d) {
                ret += ones * poww(10, SZ(n) - 1 - ones);
            }
            else if ((n[ones] - '0') == d) {
                ret += ones * h(n, ones + 1, SZ(n));
            }
        }
        return ret;
    }
}

ll f(string n, int sz) {
    ll ret = 0;
    if (sz < SZ(n)) {
        for (int i = 1; i <= sz; ++i) {
            ll cnt = i;
            if (i < sz)
                cnt *= 9;
            for (int j = i + 2; j <= sz; ++j)
                cnt *= 10;
            ret += cnt;
        }
    }
    else {
        for (int i = 1; i <= sz; ++i) {
            ret += g(n, i);
        }
    }
    return ret;
}

int main() {
    string n;
    cin >> n;
    ll ans = 0;
    for (int sz = 1; sz <= SZ(n); ++sz)
        ans += f(n, sz);
    printf("%lld\n", ans);
    return 0;
}