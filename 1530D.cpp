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
const int MAXN = 3e5; // CAMBIAR ESTE

// GJNM
int N;
int A[MAXN];
int B[MAXN];
int IN[MAXN];
bool VIS[MAXN];
vi IG[MAXN];
vi G[MAXN];

pii dfs(int u, int s) {
    VIS[u] = true;
    for (auto v : G[u]) {
        B[u] = v;
        if (VIS[v])
            continue;
        return dfs(v, s);
    }
    return {s, u};
}

void solve() {
    ri(N);
    FOR(i, 0, N) {
        IG[i].clear();
        G[i].clear();
        IN[i] = 0;
        VIS[i] = 0;
    }
    FOR(i, 0, N) {
        ri(A[i]);
        --A[i];
        ++IN[A[i]];
        IG[A[i]].pb(i);
    }

    FOR(i, 0, N) {
        if (IN[i] > 1) {
            int fst = IG[i][0];
            int found_zero = -1;
            for (auto j : IG[i]) {
                if (IN[j] == 0)
                    found_zero = j;
            }
            IG[i].clear();
            if (found_zero >= 0) IG[i].pb(found_zero);
            else IG[i].pb(fst);
        }
    }

    FOR(i, 0, N) {
        for (auto j : IG[i]) {
            G[j].pb(i);
        }
    }
    vii hola;
    FOR(i, 0, N) {
        if (VIS[i] || IG[i].size() > 0)
            continue;
        auto [s, e] = dfs(i, i);
        hola.pb({s, e});
    }
    FOR (i, 0, N) {
        if (VIS[i]) continue;
        dfs(i, i);
    }

    FOR(i, 0, SZ(hola)) {
        B[hola[i].S] = hola[(i + 1) % SZ(hola)].F;
    }

    int cnt = 0;
    FOR(i, 0, N) cnt += A[i] == B[i];
    printf("%d\n", cnt);
    FOR(i, 0, N) printf("%d ", B[i] + 1);
    printf("\n");

}

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}