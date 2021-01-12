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
const int LOG = 19;

// GJNM
int N;
vi G[MAXN];

int H[MAXN], ANC[MAXN][20];
bool ROOT[MAXN];
void pre(int x, int f) {
    ANC[x][0] = f;
    for (int l = 1; l <= LOG; l++) ANC[x][l] = ANC[ ANC[x][l - 1] ][l - 1];
    for (auto y : G[x]) {
        H[y] = H[x] + 1;
        pre(y, x);
    }
}

struct QUERY {
    int h, ind;
};
int M;
vector<QUERY> Q[MAXN];

// https://codeforces.com/blog/entry/44351

int sz[MAXN], st[MAXN], ft[MAXN], ver[MAXN], t, col[MAXN];
void getsz(int v) {
    sz[v] = 1;  // every vertex has itself in its subtree
    ver[t] = v;
    st[v] = t++;
    col[v] = H[v];
    for (auto u : G[v]) {
        getsz(u);
        sz[v] += sz[u]; // add size of child u to its parent(v)
    }
    ft[v] = t;
}


int cnt[MAXN];
int ans[MAXN];
void dfs(int v, bool keep) {
    int mx = -1, bigChild = -1;
    for (auto u : G[v])
        if (sz[u] > mx)
            mx = sz[u], bigChild = u;
    for (auto u : G[v])
        if (u != bigChild)
            dfs(u, 0);  // run a dfs on small childs and clear them from cnt
    if (bigChild != -1)
        dfs(bigChild, 1);  // bigChild marked as big and not cleared from cnt
    for (auto u : G[v])
        if (u != bigChild)
            for (int p = st[u]; p < ft[u]; p++)
                cnt[ col[ ver[p] ] ]++;
    cnt[ col[v] ]++;
    //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
    for (auto q : Q[v]) ans[q.ind] = cnt[q.h] - 1;

    if (keep == 0)
        for (int p = st[v]; p < ft[v]; p++)
            cnt[ col[ ver[p] ] ]--;
}

int main() {
    ri(N);
    FOR(i, 0, N) {
        int p; ri(p);
        ROOT[i] = true;
        if (p != 0) {
            ROOT[i] = false;
            G[p - 1].pb(i);
        }
    }
    FOR(i, 0, N) if (ROOT[i]) pre(i, i);
    ri(M);
    FOR(i, 0, M) {
        int v, p; rii(v, p); --v;
        if (p > H[v]) continue;
        for (int l = LOG; l >= 0; l--) if (p & (1 << l)) v = ANC[v][l];
        Q[v].pb({p + H[v], i});
    }
    FOR(i, 0, N) if (ROOT[i]) getsz(i);
    FOR(i, 0, N) if (ROOT[i]) dfs(i, 0);
    FOR(i, 0, M) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}