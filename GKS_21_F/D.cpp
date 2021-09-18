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
vi G[15];
int N, M, K;
ll L[15], R[15], A[15];

ll DP[1 << 15];
ll f(int msk, ll sm) {
    if (DP[msk] != -1)
        return DP[msk];
    DP[msk] = sm == K;
    FOR(u, 0, N) if (((~msk) >> u) & 1) {
        bool can_reach = false;
        for (auto v : G[u])
            can_reach |= ((msk >> v) & 1);
        if (can_reach && sm >= L[u] && sm <= R[u])
            DP[msk] += f(msk | (1 << u), sm + A[u]);
    }
    return DP[msk];
}

void solve() {
    riii(N, M, K);
    FOR(i, 0, N) G[i].clear();
    FOR(i, 0, 1 << N) DP[i] = -1;
    FOR(i, 0, N) rll(L[i], R[i]), rl(A[i]);
    FOR(_, 0, M) {
        int x, y; rii(x, y);
        G[x].pb(y);
        G[y].pb(x);
    }
    ll ans = 0;
    FOR(i, 0, N) ans += f(1 << i, A[i]);
    printf("%lld\n", ans);
}


int main() {
    int t; ri(t);
    FOR(i, 1, t + 1) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}