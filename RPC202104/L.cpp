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
const int MAXN = 5010; // CAMBIAR ESTE

// GJNM
ll N, K;
vi G[MAXN];
ll SZ[MAXN];
__int128 CNT[MAXN][MAXN];
__int128 TOT_CNT[MAXN];

void dfs(int x, int f = -1) {
    CNT[x][1] = 1;
    SZ[x] = 1;
    int mx = 0, mxi;
    for (auto y : G[x]) {
        if (y == f) continue;
        dfs(y, x);
        SZ[x] += SZ[y];
        if (SZ[y] > mx) {
            mxi = y;
            mx = SZ[y];
        }
    }

    if (mx == 0) {
        ++TOT_CNT[1];
        return;
    }

    FOR(i, 1, mx + 1) CNT[x][i + 1] = CNT[mxi][i];

    for (auto y : G[x]) {
        if (y == f || y == mxi) continue;
        ROF(i, SZ[x] + 1, 0) FOR(j, 1, SZ[y] + 1) {
            CNT[x][i + j] += CNT[y][j] * CNT[x][i];
        }
    }
    FOR(i, 1, SZ[x] + 1) {
        TOT_CNT[i] += CNT[x][i];
    }
}

int main() {
    rll(N, K);
    FOR(_, 1, N) {
        int a, b; rii(a, b); --a, --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(0);
    __int128 kaux = K;
    FOR(i, 1, SZ[0] + 1) {
        kaux -= TOT_CNT[i];
        if (kaux <= (__int128)0) {
            printf("%d\n", i);
            exit(0);
        }
    }
    printf("-1\n");
    return 0;
}