#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <random>
#include <chrono>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <array>
#include <time.h>

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
const int MAXN = 2e6; // CAMBIAR ESTE

// GJNM
int N;
ll A[MAXN];
ll ans = 1;

ll go(ll x) {
    //printf("%lld\n", x);
    if (x <= ans) return 1;

    vector<pair<ll, ll>> divs;
    for (ll i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            divs.pb({i, 0});
            if (x / i != i)
                divs.pb({x / i, 0});
        }
    }
    sort(ALL(divs));

    FOR(i, 0, N) {
        ll gcdd = __gcd(x, A[i]);
        auto it = lb(divs.begin(), divs.end(), make_pair(gcdd, 0ll));
        it->second++;
    }

    FOR(i, 0, SZ(divs)) {
        FOR(j, 0, i) {
            if (divs[i].F % divs[j].F == 0)
                divs[j].S += divs[i].S;
        }
        //printf("\t %lld : %lld\n", divs[i].F, divs[i].S);
    }

    for (int i = SZ(divs) - 1; i >= 0; --i) {
        if (2 * divs[i].S >= N)
            return divs[i].F;
    }
    return 1;
}


int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ri(N);
    FOR(i, 0, N) rl(A[i]);
    set<ll> vis;
    FOR(_, 0, 12) {
        int i = rng() % N;
        if (vis.count(A[i]))
            continue;
        vis.insert(A[i]);
        ans = max(ans, go(A[i]));
    }
    printf("%lld\n", ans);
    return 0;
}