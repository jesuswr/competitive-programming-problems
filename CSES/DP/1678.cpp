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
const int MAXN = 1e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M;
vi G[MAXN];
int VIS[MAXN], F[MAXN];
void dfs(int u) {
    VIS[u] = 1;

    for (auto v : G[u]) {
        if (VIS[v] == 0) {
            F[v] = u;
            dfs(v);
        }
        else if (VIS[v] == 1) {
            vi cyc = {v, u};
            do {
                u = F[u];
                cyc.pb(u);
            } while (u != v);
            printf("%d\n", SZ(cyc));
            reverse(ALL(cyc));
            FOR(i, 0, SZ(cyc)) printf("%d ", cyc[i] + 1);
            printf("\n");
            exit(0);
        }
    }

    VIS[u] = 2;
}

int main() {
    rii(N, M);
    FOR(i, 0, M) {
        int a, b; rii(a, b); --a, --b;
        G[a].pb(b);
    }
    FOR(i, 0, N) if (VIS[i] == 0)
        dfs(i);
    printf("IMPOSSIBLE\n");
    return 0;
}