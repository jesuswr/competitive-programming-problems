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
const int MAXN = 3e5; // CAMBIAR ESTE

// GJNM

int pre[MAXN];
int n, k;
vector<int> G[MAXN];
int wg[MAXN], dad[MAXN], dep[MAXN]; // weight,father,depth
void dfs1(int x) {
    wg[x] = 1;
    for (int y : G[x])if (y != dad[x]) {
            dad[y] = x; dep[y] = dep[x] + 1; dfs1(y);
            wg[x] += wg[y];
        }
}
int curpos, pos[MAXN], head[MAXN];
void hld(int x, int c) {
    if (c < 0)c = x;
    pos[x] = curpos++; head[x] = c;
    int mx = -1;
    for (int y : G[x])if (y != dad[x] && (mx < 0 || wg[mx] < wg[y]))mx = y;
    if (mx >= 0)hld(mx, c);
    for (int y : G[x])if (y != mx && y != dad[x])hld(y, -1);
}
void hld_init() {dad[0] = -1; dep[0] = 0; dfs1(0); curpos = 0; hld(0, -1);}
void upd(int x, int y) {
    while (head[x] != head[y]) {
        if (dep[head[x]] > dep[head[y]])swap(x, y);
        pre[pos[head[y]]] += 1;
        pre[pos[y] + 1] -= 1;
        y = dad[head[y]];
    }
    if (dep[x] > dep[y])swap(x, y); // now x is lca
    pre[pos[x] + 1] += 1;
    pre[pos[y] + 1] -= 1;
}
// for updating: STU(pos[x],u)
// queries on edges: - assign values of edges to "child" node
//                   - change pos[x] to pos[x]+1 in query (line 30)


int main() {
    ri(n);
    vii E;
    FOR(_, 1, n) {
        int a, b; rii(a, b); a--, b--;
        G[a].pb(b);
        G[b].pb(a);
        E.pb({a, b});
    }

    hld_init();

    ri(k);
    FOR(_, 0, k) {
        int a, b; rii(a, b);
        upd(a - 1, b - 1);
    }

    FOR(i, 1, n) {
        pre[i] += pre[i - 1];
    }

    for (auto e : E) {
        if (dep[e.S] < dep[e.F])
            swap(e.S, e.F);
        printf("%d ", pre[pos[e.S]]);
    }
    printf("\n");

    return 0;
}