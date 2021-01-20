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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int N, M;
vii G[MAXN];
vii E;

int low[MAXN], disc[MAXN];
bool vis[MAXN], SWAP[MAXN];
int t;
void dfs(int x, int father = -1) {
    low[x] = disc[x] = t++;
    vis[x] = true;
    int children = 0;
    for (auto tmp : G[x]) {
        int y = tmp.F;
        if ( !vis[y] ) {
            E.pb({x, y});
            children++;
            dfs(y, x);
            if (low[y] > disc[x]) {
                printf("0\n");
                exit(0);
            }
            low[x] = min(low[x], low[y]);
        }
        else if ( y != father ) {
            if (disc[x] > disc[y]) E.pb({x, y});
            low[x] = min(low[x], disc[y]);
        }
    }
}



int main() {
    rii(N, M);
    FOR(i, 0, M) {
        int a, b; rii(a, b); --a, --b;
        G[a].pb({b, i});
        G[b].pb({a, i});
    }
    dfs(0, -1);
    for (auto p : E) printf("%d %d\n", p.F + 1, p.S + 1);
    return 0;
}