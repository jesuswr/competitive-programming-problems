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
const int MAXN = 4e5; // CAMBIAR ESTE

// GJNM
int N, M;
bool VIS[MAXN];
int COL[MAXN];
vi G[MAXN];

void dfs(int x) {
    VIS[x] = true;
    if (COL[x] == 0) COL[x] = 1;
    if (COL[x] == 1) for (auto y : G[x]) {
            if (VIS[y] || COL[y] != 0) continue;
            COL[y] = (COL[x] == 2 ? 1 : 2);
        }
    for (auto y : G[x]) if (!VIS[y]) dfs(y);
}

void solve() {
    rii(N, M);
    FOR(i, 0, M) {
        int a, b; rii(a, b); --a, --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    COL[0] = 1;
    dfs(0);

    FOR(i, 0, N) {
        if (!VIS[i]) {
            printf("NO\n");
            return;
        }
    }
    int cnt = 0;
    FOR(i, 0, N) cnt += COL[i] == 1;
    printf("YES\n");
    printf("%d\n", cnt);
    FOR(i, 0, N) if (COL[i] == 1) printf("%d ", i + 1);
    printf("\n");
}

int main() {
    int t; ri(t);
    while (t--) {
        solve();
        FOR(i, 0, N) {
            VIS[i] = false;
            COL[i] = 0;
            G[i].clear();
        }
    }

    return 0;
}