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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

pair<int, ll> comp(pair<int, ll> a, pair<int, ll> b) {
    if (a.F != b.F) return max(a, b);
    if (a.S <= b.S) return a;
    return b;
}

// GJNM
int N;
vi G[MAXN];

pair<int, ll> DP[MAXN][2];
pair<int, ll> f(int u, int b, int fa = -1) {
    if (DP[u][b].F != -1)
        return DP[u][b];
    DP[u][b] = {b, b == 0 ? 1 : 1ll * SZ(G[u])};
    if (b == 0) {
        for (auto v : G[u]) if (v != fa) {
                auto [x, y] = comp(f(v, 0, u), f(v, 1, u));
                DP[u][b].F += x;
                DP[u][b].S += y;
            }
    }
    else {
        for (auto v : G[u]) if (v != fa) {
                DP[u][b].F += f(v, 0, u).F;
                DP[u][b].S += f(v, 0, u).S;
            }
    }
    return DP[u][b];
}

int VAL[MAXN];
void build(int u, int b, int fa = -1) {
    VAL[u] = b == 0 ? 1 : SZ(G[u]);
    if (b == 0) {
        for (auto v : G[u]) if (v != fa) {
                if (f(v, 0, u) == comp(f(v, 0, u), f(v, 1, u)))
                    build(v, 0, u);
                else
                    build(v, 1, u);
            }
    }
    else {
        for (auto v : G[u]) if (v != fa) {
                build(v, 0, u);
            }
    }
}

int main() {
    FOR(i, 0, MAXN) DP[i][0] = DP[i][1] = { -1, -1};
    ri(N);
    if (N == 2) {
        printf("2 2\n1 1\n");
        return 0;
    }
    FOR(_, 1, N) {
        int a, b; rii(a, b);
        --a; --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    auto [x, y] = comp(f(0, 0), f(0, 1));
    printf("%d %lld\n", x, y);
    if (f(0, 0) == comp(f(0, 0), f(0, 1)))
        build(0, 0);
    else
        build(0, 1);
    FOR(i, 0, N) printf("%d ", VAL[i]);
    printf("\n");
    return 0;
}