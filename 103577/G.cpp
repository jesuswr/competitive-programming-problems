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
typedef __int128 LL;
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
const int MAXN = 3e5 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}



int N;
vi G[MAXN];
int A[MAXN];

int SZ[MAXN], H[MAXN];
void dfs_sz(int v = 0, int f = -1) {
    SZ[v] = 1;
    if (f != -1) H[v] = H[f] + 1;
    for (auto &u : G[v]) if (f != u) {
            dfs_sz(u, v);
            SZ[v] += SZ[u];
            if (SZ[u] > SZ[G[v][0]]) {
                swap(u, G[v][0]);
            }
        }
}
int IN[MAXN], OUT[MAXN], _T, NXT[MAXN], F[MAXN];
void dfs_hld(int v = 0, int f = -1) {
    IN[v] = _T++;
    A[IN[v]] = H[v];
    F[v] = f;
    for (auto u : G[v]) if (f != u) {
            NXT[u] = (u == G[v][0] ? NXT[v] : u);
            dfs_hld(u, v);
        }
    OUT[v] = _T;
}

// Todos los rangos son semi-abiertos [a,b)
struct STN {
    LL height_cnt = 0;
    LL sm = 0;
    void merge(STN& L, STN& R) {
        height_cnt = L.height_cnt + R.height_cnt;
        sm = L.sm + R.sm;
    }
    void operator=(ll a) {
        height_cnt = a;
        sm = 0;
    }
};
STN ST[4 * MAXN];
pair<LL, LL> lzy[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = A[l];
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STB(L, l, m); STB(R, m, r);
    ST[id].merge(ST[L], ST[R]);
}
// Actualiza el nodo y guarda en lazy
void upd(int id, int l, int r, pair<LL, LL> x) {
    ST[id].sm += (r - l) * x.F + ST[id].height_cnt * x.S;
    lzy[id].F += x.F;
    lzy[id].S += x.S;
}
// Propaga el update en lazy
void shift(int id, int l, int r) {
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    upd(L, l, m, lzy[id]);
    upd(R, m, r, lzy[id]);
    lzy[id] = {0, 0};
}
STN STQ(int x, int y, int id = 1, int l = 0, int r = N) {
    if (x == l && y == r) return ST[id];
    shift(id, l, r);
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (x >= m) return STQ(x, y, R, m, r);
    if (y <= m) return STQ(x, y, L, l, m);
    STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
    return res.merge(ln, rn), res;
}
void STU(int x, int y, pair<LL, LL> v, int id = 1, int l = 0, int r = N) {
    if (x >= r || y <= l) return;
    if (x <= l && y >= r) {
        upd(id, l, r, v);
        return;
    }
    shift(id, l, r);
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STU(x, y, v, L, l, m);
    STU(x, y, v, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}

int main() {
    ri(N);
    FOR(i, 1, N) {
        int a, b; rii(a, b);
        --a; --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs_sz(); dfs_hld();
    STB();
    // FOR(i, 0, N) printf("%d : %d %d %d %d %d %d\n", i + 1, IN[i], OUT[i], NXT[i] + 1, SZ[i], H[i], F[i] + 1);

    int Q; ri(Q);
    while (Q--) {
        int t; ri(t);
        if (t == 0) {
            int x, y; rii(x, y);
            --x; --y;
            LL ans = 0;
            while (NXT[x] != NXT[y]) {
                if (H[NXT[x]] < H[NXT[y]])
                    swap(x, y);
                ans += STQ(IN[NXT[x]], IN[x] + 1).sm;
                x = F[NXT[x]];
            }
            if (H[x] < H[y])
                swap(x, y);
            ans += STQ(IN[y], IN[x] + 1).sm;
            print(ans);
            printf("\n");
        }
        else {
            int u, _v, _k; riii(u, _v, _k);
            --u;
            LL v = _v, k = _k;
            STU(IN[u], OUT[u], {v - k * H[u], k});
        }
    }



    return 0;
}