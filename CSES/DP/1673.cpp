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
vi G[2569];
bool R[2569][2569];
void dfs(int r, int u) {
    R[r][u] = 1;
    for (auto v : G[u])
        if (!R[r][v])
            dfs(r, v);
}

int main() {
    int n, m; rii(n, m);
    vector<tuple<int, int, ll>> edges(m);
    FOR(i, 0, m) {
        int a, b, c; riii(a, b, c);
        edges[i] = {a - 1, b - 1, -c};
        G[a - 1].pb(b - 1);
    }
    FOR(i, 0, n) dfs(i, i);
    vector<ll> D(n, LLINF);
    D[0] = 0;
    bool change = true;
    for (int i = 0; i < n - 1 && change; ++i) {
        change = false;
        for (auto [a, b, c] : edges) {
            if (D[a] + c < D[b] && D[a] != LLINF) {
                D[b] = D[a] + c;
                change = true;
            }
        }
    }

    for (auto [a, b, c] : edges) {
        if (D[a] + c < D[b] && R[b][n - 1] && D[a] != LLINF) {
            printf("-1\n");
            return 0;
        }
    }
    printf("%lld\n", -D[n - 1]);
    return 0;
}