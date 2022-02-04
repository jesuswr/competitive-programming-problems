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
const int MAXN = 3010; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
vi G[MAXN];
int H[MAXN];


void pre(int u = 0, int f = 0) {
    for (int v : G[u]) {
        if (v != f) {
            H[v] = H[u] + 1;
            pre(v, u);
        }
    }
}

bool IMP[MAXN];
int DEG[MAXN];
int mark(int val) {
    FOR(i, 0, N) IMP[i] = 1;
    FOR(i, 0, N) DEG[i] = SZ(G[i]);
    queue<int> ord;
    FOR(i, 0, N) if (DEG[i] == 1) ord.push(i);
    int ret = -1;
    while (!ord.empty()) {
        int u = ord.front();
        // printf("\t\t%d (%d)\n", u + 1, H[u]);
        ord.pop();
        if (H[u] <= val) {
            IMP[u] = 0;
            for (auto v : G[u]) {
                // printf("\t\t\t%d %d\n", v + 1, DEG[v]);
                DEG[v]--;
                if (DEG[v] == 1)
                    ord.push(v);
            }
        }
        else
            ret = u;
    }
    return ret;
}

queue<int> q;
vector<int> dst(MAXN);
pii bfs(int u) {
    FOR(i, 0, N) dst[i] = INF;
    q.push(u);
    dst[u] = 0;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (auto v : G[u]) {
            if (IMP[v] && dst[v] > dst[u] + 1) {
                dst[v] = dst[u] + 1;
                q.push(v);
            }
        }
    }
    return {u, dst[u]};
}



bool check(int val, int x) {
    // printf("%d\n", val);
    int u = mark(val);
    // FOR(i, 0, N) if (IMP[i]) printf("\t%d\n", i + 1);
    if (u == -1) return true;
    pii p = bfs(u);
    if (x + ((p.S + 1) >> 1) > val)
        return false;
    p = bfs(p.F);
    return x + ((p.S + 1) >> 1) <= val;
}


void go(int x) {
    int lo = 1, hi = N;
    while (lo < hi) {
        int mi = lo + ((hi - lo) >> 1);
        if (check(mi, x))
            hi = mi;
        else
            lo = mi + 1;
    }
    printf("%d ", lo);
}


void solve() {
    ri(N);
    FOR(i, 0, N) G[i].clear();
    FOR(i, 1, N) {
        int a, b; rii(a, b);
        --a;
        --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    pre();
    int mx = 0;
    FOR(i, 0, N) mx = max(mx, H[i]);
    FOR(x, 1, mx) go(x);
    FOR(x, mx, N + 1) printf("%d ", mx);
    printf("\n");
}



int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}