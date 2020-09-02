#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 111111; // CAMBIAR ESTE

// GJNM
int n, l, m;
vi G[MAXN];
int W[MAXN], W2[MAXN];
map<int, int> old_to_comp, comp_to_old;

int timer;
int tin[MAXN], tout[MAXN];
int up[MAXN][19];
int father[MAXN];

struct STN {
    STN *l, *r;
    int val;
    STN(int val) : l(0), r(0), val(val) {}
    STN(STN *l, STN *r) : l(l), r(r), val(0) {
        if (l) val += l->val;
        if (r) val += r->val;
    }
};
int N;

void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }

    for (int i = 0; i < G[v].size(); i++) {
        if (G[v][i] != p) {
            dfs(G[v][i], v);
        }
        father[G[v][i]] = v;
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    timer = 0;
    l = ceil(log2(n)) + 1;
    dfs(root, root);
}




STN* STB(int l = 0, int r = N) {
    if (r - l < 2) return new STN(0);
    int m = (l + r) >> 1;
    return new STN(STB(l, m), STB(m, r));
}
int STQ(STN *a, STN *b, STN *c, STN *d, int k, int l = 0, int r = N) {
    if (r - l < 2)
        return l;

    int f = (a->l->val) + (b->l->val) - (c->l->val) - (d->l->val);
    int m = (l + r) >> 1;
    if (f >= k)
        return STQ(a->l, b->l, c->l, d->l, k, l, m);
    else
        return STQ(a->r, b->r, c->r, d->r, k - f, m, r);
}
STN* STU(int p, STN *v, int l = 0, int r = N) {
    if (r - l < 2) return new STN(1 + v->val);
    int m = (l + r) >> 1;
    if (p < m)
        return new STN(STU(p, v->l, l, m), v->r);
    else
        return new STN(v->l, STU(p, v->r, m, r));
}

STN* UPD[MAXN];

void dfs2(int v, int f = -1) {
    UPD[v] = STU(old_to_comp[W[v]], UPD[father[v]]);
    for (int i = 0; i < G[v].size(); i++) {
        if (G[v][i] == f)
            continue;
        dfs2(G[v][i], v);
    }
}


int main() {
    rii(n, m);
    FOR(i, 0, n) {
        ri(W[i + 1]);
        W2[i] = W[i + 1];
        UPD[i + 1] = 0;
    }
    FOR(i, 0, n - 1) {
        int x, y; rii(x, y);
        G[x].pb(y);
        G[y].pb(x);
    }
    // LCA
    preprocess(1);
    father[1] = 0;

    // COMPRIMIR COORDENADAS PORQUE SPOJ NO SIRVE
    sort(W2, W2 + n);
    int curr = 0;
    int i = 0;
    while (i < n) {
        old_to_comp[W2[i]] = curr;
        comp_to_old[curr++] = W2[i];
        int j = i;
        while ( i < n && W2[i] == W2[j] )
            i++;
    }

    // AHORA SI
    N = n + 1;
    UPD[0] = STB();
    dfs2(1);

    FOR(i, 0, m) {
        int u, v, k;
        riii(u, v, k);
        int fath = lca(u, v);
        int fath_fath = father[fath];

        STN *a, *b, *c, *d;
        a = UPD[u], b = UPD[v], c = UPD[fath], d = UPD[fath_fath];
        int l = 0, r = N;
        int ans = STQ(a, b, c, d, k);
        printf("%d\n", comp_to_old[ans]);
    }



    return 0;
}