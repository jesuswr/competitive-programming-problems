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
const int LOGN = 20;
const int MAXN = 1e6 + 10; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, K;
vi G[MAXN];
bool T[MAXN];
int H[MAXN];
int ANC[MAXN][LOGN + 1];
void dfs(int u, int f) {
    ANC[u][0] = f;
    for (int l = 1; l <= LOGN; ++l)
        ANC[u][l] = ANC[ ANC[u][l - 1] ][l - 1];
    for (auto v : G[u]) if (v != f) {
            H[v] = H[u] + 1;
            dfs(v, u);
        }
}

int main() {
    rii(N, K);
    FOR(_, 1, N) {
        int a, b; rii(a, b);
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(N, N);

    T[N] = 1;
    int lft = N - K - 1;
    for (int u = N - 1; u >= 1; --u) {
        if (T[u]) continue;
        int anc = u;
        for (int l = LOGN; l >= 0; --l)
            if (T[ ANC[anc][l] ] == false)
                anc = ANC[anc][l];
        anc = ANC[anc][0];
        if (H[u] - H[anc] <= lft) {
            lft -= (H[u] - H[anc]);
            int v = u;
            do {
                T[v] = 1;
                v = ANC[v][0];
            } while (v != anc);
        }
    }

    FOR(i, 1, N) if (!T[i]) printf("%d\n", i);
    printf("\n");

    return 0;
}