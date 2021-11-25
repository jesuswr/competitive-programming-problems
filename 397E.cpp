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
const int MAXN = 6e5 + 69; // CAMBIAR ESTE
const ll MOD = 1e9 + 7;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
struct BIT {
    vector<ll> _BIT;
    BIT() {
        _BIT.resize(MAXN);
    }
    void updBIT(int p, ll val) {
        p++;
        val = ((val % MOD) + MOD) % MOD;
        for (; p < MAXN; p += p & -p)
            _BIT[p] = (val + _BIT[p]) % MOD;
    }
    ll sumBIT(int p) {
        p++;
        ll ret = 0;
        for (; p; p -= p & -p)
            ret = (ret + _BIT[p]) % MOD;
        return ret;
    }
    ll query(int l) {
        return sumBIT(l);
    }
};

int N;
vi G[MAXN];
int IN[MAXN], OUT[MAXN], T, H[MAXN];

void dfs(int u, int f = -1) {
    IN[u] = T++;
    for (auto v : G[u]) {
        if (v == f)
            continue;
        H[v] = H[u] + 1;
        dfs(v, u);
    }
    OUT[u] = T;
}

int main() {
    ri(N);
    FOR(i, 1, N) {
        int pi; ri(pi);
        G[pi - 1].pb(i);
    }
    H[0] = 1;
    dfs(0);
    int q; ri(q);
    BIT Xs, Ks;
    while (q--) {
        int t; ri(t);
        if (t == 1) {
            int v, x, k; riii(v, x, k); --v;
            Xs.updBIT(IN[v], x + 1ll * H[v] * k);
            Xs.updBIT(OUT[v], -(x + 1ll * H[v] * k));
            Ks.updBIT(IN[v], k);
            Ks.updBIT(OUT[v], -1 * k);
        }
        else {
            int v; ri(v); --v;
            ll ans = Xs.query(IN[v]) - Ks.query(IN[v]) * H[v];
            ans = ((ans % MOD) + MOD) % MOD;
            printf("%lld\n", ans);
        }
    }

    return 0;
}