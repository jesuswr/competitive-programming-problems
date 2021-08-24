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
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
ll cost(ll len, ll pieces) {
    if (pieces > len)
        return LLINF;
    ll extra = len % pieces;
    ll x = len / pieces;
    return (pieces - extra) * x * x + extra * (x + 1) * (x + 1);
}

int main() {
    int n, k; rii(n, k);
    priority_queue< tuple<ll, ll, ll> > pq;
    ll tot = 0;
    FOR(i, 0, n) {
        int a; ri(a);
        ll a_cost = cost(a, 1);
        tot += a_cost;
        pq.push({a_cost - cost(a, 2), a, 1});
    }
    FOR(_, 0, k - n) {
        auto [delta_cst, len, pieces] = pq.top(); pq.pop();
        tot -= delta_cst;
        pq.push({cost(len, pieces + 1) - cost(len, pieces + 2), len, pieces + 1});
    }
    printf("%lld\n", tot);
    return 0;
}