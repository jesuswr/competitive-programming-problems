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
const int MAXN = 51; // CAMBIAR ESTE

// GJNM
int V, E;
bool G[MAXN][MAXN];
bool VIS[MAXN];

int dfs(int u) {
    VIS[u] = true;
    int cnt = 1;
    FOR(v, 0, V) {
        if (VIS[v] || G[u][v] == false)
            continue;
        cnt += dfs(v);
    }
    return cnt;
}

int main() {
    rii(V, E);
    FOR(_, 0, E) {
        int a, b;
        rii(a, b); --a, --b;
        G[a][b] = G[b][a] = true;
    }
    int cnt = 0;
    FOR(i, 0, V) if (!VIS[i]) cnt += dfs(i) - 1;
    printf("%lld\n", 1ll << cnt);
    return 0;
}