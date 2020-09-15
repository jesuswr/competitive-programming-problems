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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

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
#define max(x, y) (((x) > (y))? (x) : (y))

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 20000; // CAMBIAR ESTE

// GJNM
int n;
vii G[MAXN];
int E1[MAXN], E2[MAXN], C[MAXN];

// dfs for basic stuff
int height[MAXN], father[MAXN], sz[MAXN], weight[MAXN], weight2[MAXN];

void dfs_pre(int x, int f = -1) {
    sz[x] = 1;
    for (auto aux : G[x]) {
        int y = aux.F, c = aux.S;
        if (y == f)
            continue;
        father[y] = x;
        height[y] = height[x] + 1;
        weight[y] = c;
        dfs_pre(y, x);
        sz[x] += sz[y];
        weight2[y] = c;
    }
}
// dfs for basic stuff

// code for HLD
int heavy[MAXN];
void dfs_heavy(int x, int f = -1) {
    heavy[x] = -1;
    int mx = -1;
    for (auto aux : G[x]) {
        int y = aux.F, c = aux.S;
        if (y == f)
            continue;
        if (sz[y] > mx) {
            mx = sz[y];
            heavy[x] = y;
        }
    }
    for (auto aux : G[x]) {
        if (aux.F == f)
            continue;
        dfs_heavy(aux.F, x);
    }
}

int head[MAXN], start[MAXN];
int paths[MAXN];
int pos;
void hld()
{
    for (int i = 0, pos = 0; i < n; ++i){
        if (father[i] == -1 || heavy[father[i]] != i)
            for (int j = i; j != -1; j = heavy[j])
            {
                head[j] = i;
                start[j] = pos; paths[pos] = weight2[j];
                pos++;
            }
    }
}



// SEGTREE
// Todos los rangos son semi-abiertos [a,b)
int N, A[MAXN];
struct STN {
    int val;
    void merge(STN& L, STN& R) {
        val = max(L.val, R.val);
    }
    void operator=(int a) {
        val = a;
    }
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = paths[l];
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STB(L, l, m); STB(R, m, r);
    ST[id].merge(ST[L], ST[R]);
}
STN STQ(int x, int y, int id = 1, int l = 0, int r = N) {
    if (x == l && y == r) return ST[id];
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (x >= m) return STQ(x, y, R, m, r);
    if (y <= m) return STQ(x, y, L, l, m);
    STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
    return res.merge(ln, rn), res;
}
void STU(int p, int x, int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = x;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU(p, x, L, l, m);
    else STU(p, x, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}
// SEGTREE

// QUERY
int query(int a, int b) {
    int res = 0;
    while (head[a] != head[b]) {
        if (height[head[a]] < height[head[b]]) {
            swap(a, b);
        }
        res = max(res, STQ(start[head[a]], start[a] + 1).val);
        a = father[head[a]];
    }
    if (height[a] > height[b])
        swap(a, b);
    if (a != b)
        res = max(res, STQ(start[a] + 1, start[b] + 1).val);
    return res;
}

// QUERY





int main() {
    int t;
    ri(t);
    while (t--) {
        ri(n);

        FOR(i, 1, n) {
            int a, b, c;
            riii(a, b, c); a--, b--;
            E1[i] = a, E2[i] = b, C[i] = c;
            G[a].pb({b, c});
            G[b].pb({a, c});
        }

        //preprocess(0);
        dfs_pre(0);
        dfs_heavy(0);
        //dfs_hld(0, 0);
        hld();
        N = n;
        STB();

        char aux[20];
        while (true) {
            scanf("%s", aux);
            if (aux[0] == 'D')
                break;
            int a, b;
            rii(a, b);
            if (aux[0] == 'Q') {
                a--, b--;
                printf("%d\n", (query(a,b)));
            }
            else {
                int u = E1[a], v = E2[a];
                if (u == father[v])
                    STU(start[v], b);
                else
                    STU(start[u], b);
            }
        }

        FOR(i, 0, n) {
            G[i].clear();
        }

    }


    return 0;
}