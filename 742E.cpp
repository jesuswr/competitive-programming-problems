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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
vi G[MAXN];
vii E;

bool V[MAXN];
bool C[MAXN];
void dfs(int u) {
    V[u] = 1;
    for (auto v : G[u]) {
        if (!V[v]) {
            C[v] = C[u] ^ 1;
            dfs(v);
        }
    }
}

int main() {
    ri(N);
    FOR(i, 0, N) {
        G[2 * i].pb(2 * i + 1);
        G[2 * i + 1].pb(2 * i);
    }
    FOR(i, 0, N) {
        int a, b; rii(a, b);
        --a; --b;
        G[a].pb(b);
        G[b].pb(a);
        E.pb({a, b});
    }
    FOR(i, 0, 2 * N) if (V[i] == 0) dfs(i);

    for (auto [u, v] : E) 
        printf("%d %d\n", C[u] + 1, C[v] + 1);

    return 0;
}