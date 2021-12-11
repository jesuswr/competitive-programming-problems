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
const int MAXN = 3e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int V, E;
vi G[MAXN];

bool VIS[MAXN];
int COL[MAXN];
void dfs(int u) {
    if (VIS[u])
        return;
    VIS[u] = 1;
    for (auto v : G[u]) {
        COL[v] = 1 ^ COL[u];
        dfs(v);
    }
}

int main() {
    rii(V, E);
    FOR(i, 0, V) COL[i] = -69;
    FOR(_, 0, E) {
        int a, b; rii(a, b);
        --a, --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    COL[0] = 0;
    dfs(0);
    ll CNT[2] = {0, 0};
    FOR(i, 0, V) if (COL[i] != -69) CNT[COL[i]]++;
    if (CNT[0] + CNT[1] == V && CNT[0] * CNT[1] == E)
        printf("%lld\n", CNT[0] / 2 + CNT[1] / 2);
    else
        printf("%d\n", V / 2);


    return 0;
}