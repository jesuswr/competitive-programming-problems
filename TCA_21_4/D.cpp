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
const int MAXN = 3010; // CAMBIAR ESTE
const int MOD = 1e9 + 7;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, D;
vi G[MAXN];

int DP[MAXN][MAXN];
int f(int u, int d) {
    if (DP[u][d] != 0)
        return DP[u][d];
    DP[u][d] = 1;
    for (auto v : G[u])
        DP[u][d] = (1ll * DP[u][d] * f(v, d)) % MOD;
    if (d > 1)
        DP[u][d] = (DP[u][d] + f(u, d - 1)) % MOD;
    return DP[u][d];
}

int binpow(int b, int e) {
    int ret = 1;
    while (e) {
        if (e & 1) ret = (1ll * ret * b) % MOD;
        e >>= 1;
        b = (1ll * b * b) % MOD;
    }
    return ret;
}

int main() {
    rii(N, D);
    FOR(i, 1, N) {
        int p; ri(p);
        G[p - 1].pb(i);
    }
    FOR(c, 1, N + 2) f(0, c);

    int ans = 0;
    FOR(i, 1, N + 2) {
        int fact = 1;
        FOR(j, 1, N + 2) {
            if (i == j) continue;
            fact = (1ll * fact * (D - j + MOD)) % MOD;
            fact = (1ll * fact * binpow(i - j + MOD, MOD - 2)) % MOD;
        }
        fact = (1ll * fact * DP[0][i]) % MOD;
        ans = (ans + fact) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}