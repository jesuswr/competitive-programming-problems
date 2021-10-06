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
ll H[3];
vector<tuple<int, int, int>> OPTS = {{5, 0, 0}, {3, 0, 1}, {2, 2, 0}, {1, 0, 2}, {0, 2, 1}};

ll go() {
    ll ret = 0;
    ll AUX_H[3] = {H[0], H[1], H[2]};
    for (auto [a, b, c] : OPTS) {
        ll mn = LLINF;
        if (a > 0)
            mn = min(mn, H[0] / a);
        if (b > 0)
            mn = min(mn, H[1] / b);
        if (c > 0)
            mn = min(mn, H[2] / c);
        ret += mn;
        H[0] -= a * mn;
        H[1] -= b * mn;
        H[2] -= c * mn;
    }
    H[0] = AUX_H[0];
    H[1] = AUX_H[1];
    H[2] = AUX_H[2];
    return ret;
}

int main() {
    int t; ri(t);
    while (t--) {
        FOR(i, 0, 3) rl(H[i]);
        ll ans = 0;
        FOR(_, 0, 120) {
            ans = max(ans, go());
            next_permutation(ALL(OPTS));
        }
        printf("%lld\n", ans);
    }
    return 0;
}