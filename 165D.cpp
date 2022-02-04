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
const int MAXN = 1e5 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
vi G[MAXN];
vii E;

int H[MAXN], L[MAXN], R[MAXN], T = 1;
void _dfs(int u, int f, int l) {
    L[u] = l;
    R[u] = T++;
    H[u] = H[f] + 1;
    for (auto v : G[u]) if (v != f) {
            _dfs(v, u, l);
        }
}
void dfs(int u) {
    L[u] = R[u] = T++;
    for (auto v : G[u])
        _dfs(v, u, T);
}

ll BIT[2 * MAXN];
// suma de rangos [0,n-1]
void updBIT(int p, ll val) {
    p++;    // esto es porque el bit esta indexado desde 1
    for (; p < 2 * MAXN; p += p & -p) // se puede cambiar maxN por n+5 si hace falta mas velocidad
        BIT[p] += val;
}
ll sumBIT(int p) {
    p++;
    ll ret = 0;
    for (; p; p -= p & -p)
        ret += BIT[p];
    return ret;
}

int main() {
    ri(N);
    FOR(i, 1, N) {
        int a, b; rii(a, b);
        --a, --b;
        G[a].pb(b);
        G[b].pb(a);
        E.pb({a, b});
    }
    int root = 0;
    FOR(i, 1, N) if (G[i].size() > G[root].size())
        root = i;
    dfs(root);
    for (auto &p : E)
        if (H[p.F] < H[p.S])
            swap(p.F, p.S);

    int q; ri(q);
    while (q--) {
        int t; ri(t);
        if (t <= 2) {
            int u; ri(u); --u;
            u = E[u].F;
            updBIT(R[u], t == 1 ? -1 : 1);
        }
        else {
            int u, v; rii(u, v); --u, --v;
            if (H[u] > H[v])
                swap(u, v);
            if (u == root) {
                ll sm = sumBIT(R[v]) - sumBIT(L[v] - 1);
                if (sm > 0)
                    printf("-1\n");
                else
                    printf("%d\n", H[v]);
            }
            else if (L[u] == L[v]) {
                ll sm = sumBIT(R[v]) - sumBIT(R[u]);
                if (sm > 0)
                    printf("-1\n");
                else
                    printf("%d\n", H[v] - H[u]);
            }
            else {
                ll sm = (sumBIT(R[u]) - sumBIT(L[u] - 1)) + (sumBIT(R[v]) - sumBIT(L[v] - 1));
                if (sm > 0)
                    printf("-1\n");
                else
                    printf("%d\n", H[v] + H[u]);
            }
        }
    }

    return 0;
}