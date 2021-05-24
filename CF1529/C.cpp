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
const int MAXN = 1e5 + 19; // CAMBIAR ESTE

// GJNM
int N;
ll A[MAXN][2];
vi G[MAXN];

ll DP[MAXN][2];
ll f(int v, int k, int fat = -1) {
    if (DP[v][k] != -1) return DP[v][k];
    ll &ret = DP[v][k] = 0;
    for (auto u : G[v]) {
        if (u == fat) continue;
        ret +=
            max(abs(A[v][k] - A[u][0]) + f(u, 0, v), abs(A[v][k] - A[u][1]) + f(u, 1, v));
    }
    return ret;
}

void solve() {
    ri(N);
    FOR(i, 0, N) rll(A[i][0], A[i][1]);
    FOR(_, 1, N) {
        int a, b; rii(a, b); --a, --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    FOR(i, 0, N) DP[i][0] = DP[i][1] = -1;
    printf("%lld\n", max(f(0, 0), f(0, 1)));
    FOR(i, 0, N) G[i].clear();
}


int main() {
    int t; ri(t);
    while (t--) solve();

    return 0;
}