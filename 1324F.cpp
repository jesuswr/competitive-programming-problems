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

using namespace std;

typedef long long ll;
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
const int MAXN = 2e5; // CAMBIAR ESTE

// GJNM
int N;
vi G[MAXN];
int COL[MAXN], DP[MAXN];
int ANS[MAXN];

void dfs_pre(int x, int f = -1) {
    DP[x] = (COL[x] == 1 ? 1 : -1);
    for (auto y : G[x]) {
        if (y == f) continue;
        dfs_pre(y, x);
        DP[x] += max(0, DP[y]);
    }
}

void dfs(int x, int f = -1) {
    ANS[x] = DP[x];
    for (auto y : G[x]) {
        if (y == f) continue;
        DP[x] -= max(0, DP[y]);
        DP[y] += max(0, DP[x]);
        dfs(y, x);
        DP[y] -= max(0, DP[x]);
        DP[x] += max(0, DP[y]);
    }
}

int main() {
    ri(N);
    FOR(i, 0, N) ri(COL[i]);
    FOR(i, 1, N) {
        int a, b; rii(a, b);
        G[a - 1].pb(b - 1);
        G[b - 1].pb(a - 1);
    }
    dfs_pre(0);
    dfs(0);
    FOR(i, 0, N) printf("%d ", ANS[i]);
    printf("\n"); 
    return 0;
}