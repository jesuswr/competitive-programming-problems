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
const int MAXN = 800090; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
vi G[MAXN];
int F[MAXN];
int FI[MAXN];
int rem;

int sz[MAXN], st[MAXN], ft[MAXN], ver[MAXN], t, col[MAXN];
void getsz(int v, int p) {
    sz[v] = 1;  // every vertex has itself in its subtree
    ver[t] = v;
    st[v] = t++;
    for (auto u : G[v])
        if (u != p) {
            getsz(u, v);
            sz[v] += sz[u]; // add size of child u to its parent(v)
        }
    ft[v] = t;
}


int cnt[MAXN], aux, uniq;
void dfs(int v, int p, bool keep) {
    int mx = -1, bigChild = -1;
    for (auto u : G[v])
        if (u != p && sz[u] > mx)
            mx = sz[u], bigChild = u;
    for (auto u : G[v])
        if (u != p && u != bigChild)
            dfs(u, v, 0);  // run a dfs on small childs and clear them from cnt
    if (bigChild != -1)
        dfs(bigChild, v, 1);  // bigChild marked as big and not cleared from cnt
    for (auto u : G[v])
        if (u != p && u != bigChild)
            for (int p = st[u]; p < ft[u]; p++) {
                cnt[ col[ ver[p] ] ]++;
                aux += cnt[col[ver[p]]] == FI[col[ver[p]]];
                uniq += cnt[col[ver[p]]] == 1;
            }
    cnt[ col[v] ]++;
    uniq += cnt[col[v]] == 1;
    aux += (cnt[col[v]] == FI[col[v]]) && (v != 0);
    if (aux == uniq)
        rem++;
    //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
    if (keep == 0) {
        aux = 0;
        uniq = 0;
        for (int p = st[v]; p < ft[v]; p++)
            cnt[ col[ ver[p] ] ]--;
    }
}


void solve() {
    ri(N);
    rem = 0;
    aux = 0;
    uniq = 0;
    t = 0;
    FOR(i, 0, N + 10) {
        G[i].clear();
        F[i] = FI[i] = 0;
        col[i] = 0;
        cnt[i] = 0;
        sz[i] = 0;
        st[i] = 0;
        ft[i] = 0;
        ver[i] = 0;
    }
    FOR(i, 1, N) {
        int a, b; rii(a, b);
        G[a - 1].pb(b - 1);
        G[b - 1].pb(a - 1);
    }
    FOR(i, 0, N) {
        ri(F[i]);
        col[i] = F[i];
        FI[F[i]]++;
    }
    getsz(0, 0);
    dfs(0, 0, 0);
    printf("%d\n", rem);
}

int main() {
    int tt; ri(tt);
    FOR(i, 1, tt + 1) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}