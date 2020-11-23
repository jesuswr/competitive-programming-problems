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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
int n;
ll c[3][MAXN];
vi G[MAXN];
ll dp[MAXN][3][3]; // node id, node col, father col
vi nxt[MAXN][3][3];

ll f(int x, int col, int fcol, int fat = -1) {
    if (dp[x][col][fcol] != 0)
        return dp[x][col][fcol];
    ll &ret = dp[x][col][fcol];

    vi av;
    FOR(i, 0, 3) {
        if (i != col && i != fcol)
            av.pb(i);
    }
    vi need;
    for (auto y : G[x]) {
        if (y == fat)
            continue;
        need.pb(y);
    }

    if (SZ(need) > SZ(av)) {
        printf("-1\n");
        exit(0);
    }

    ll op1 = c[col][x];
    FOR(i, 0, SZ(need)) {
        op1 += f(need[i], av[i], col, x);
    }
    reverse(ALL(av));
    ll op2 = c[col][x];
    FOR(i, 0, SZ(need)) {
        op2 += f(need[i], av[i], col, x);
    }
    if (op1 > op2)
        nxt[x][col][fcol] = av;
    else {
        reverse(ALL(av));
        nxt[x][col][fcol] = av;
    }

    return ret = min(op1, op2);
}
int ans[MAXN];
void reconstruct(int x, int col, int fcol, int fat = -1) {
    ans[x] = col;
    vi need;
    for (auto y : G[x]) {
        if (y == fat)
            continue;
        need.pb(y);
    }

    FOR(i, 0, SZ(need)) {
        reconstruct(need[i], nxt[x][col][fcol][i], col, x);
    }
}

int main() {
    ri(n);
    FOR(i, 0, 3) {
        FOR(j, 0, n) {
            rl(c[i][j]);
        }
    }
    FOR(i, 1, n) {
        int a, b; rii(a, b); a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    printf("%lld\n", min(f(0, 0, 0), min(f(0, 1, 1), f(0, 2, 2))));

    if (f(0, 0, 0) <= min(f(0, 1, 1), f(0, 2, 2)))
        reconstruct(0, 0, 0);
    else if (f(0, 1, 1) <= min(f(0, 0, 0), f(0, 2, 2)))
        reconstruct(0, 1, 1);
    else
        reconstruct(0, 2, 2);
    FOR(i, 0, n) {
        printf("%d ", ans[i] + 1);
    }
    printf("\n");
    return 0;
}