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
const int MAXN = 3e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
vi G[MAXN];
int T[MAXN];
void dfs(int u, int f = -1) {
    T[u] = 1; // hoja
    for (auto v : G[u]) if (v != f) {
            dfs(v, u);
            if (T[v] == 1)
                T[u] = 2; // bud
        }
}

void solve() {
    ri(N);
    FOR(i, 0, N) {
        G[i].clear();
        T[i] = 0;
    }
    FOR(_, 1, N) {
        int a, b; rii(a, b);
        G[a - 1].pb(b - 1);
        G[b - 1].pb(a - 1);
    }
    dfs(0);
    ll k = 0;
    FOR(i, 1, N) k += T[i] == 2;
    ll ans = N - 2 * k - (T[0] == 2);
    printf("%lld\n", ans);
}

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}