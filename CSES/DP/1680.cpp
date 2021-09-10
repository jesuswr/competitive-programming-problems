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
int n, m;
vi G[MAXN + 69];
int DP[MAXN + 69];
int f(int u) {
    if (DP[u] != 0)
        return DP[u];
    if (u == n)
        return DP[u] = 1;
    DP[u] = -1e7;
    for (auto v : G[u])
        DP[u] = max(DP[u], f(v) + 1);
    return DP[u];
}

int main() {
    rii(n, m);
    FOR(_, 0, m) {
        int a, b; rii(a, b);
        G[a].pb(b);
    }
    if (f(1) <= 0) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    printf("%d\n", f(1));
    int s = 1;
    FOR(_, 1, DP[1]) {
        printf("%d ", s);
        for (int u : G[s]) if (DP[u] + 1 == DP[s]) {
                s = u;
                break;
            }
    }
    printf("%d\n", s);
    return 0;
}