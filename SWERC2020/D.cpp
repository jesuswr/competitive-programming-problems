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
const int MAXN = 2e5; // CAMBIAR ESTE

// GJNM
ll D[MAXN];
vii G[MAXN];
vii Es;
int V, E, L, U;

void dijkstra() {
    priority_queue<pair<ll, int>> pq;
    FOR(i, 0, V) D[i] = LLINF;

    D[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        ll c = -pq.top().F;
        int u = pq.top().S;
        pq.pop();

        if (c > D[u])
            continue;

        for (auto [v, ec] : G[u]) {
            if (D[v] > c + ec) {
                D[v] = c + ec;
                pq.push({ -D[v], v});
            }
        }
    }
}

int main() {
    rii(V, E); rii(L, U);
    FOR(_, 0, E) {
        int a, b, c; riii(a, b, c);
        G[a].pb({b, c});
        G[b].pb({a, c});
        Es.pb({a, b});
    }
    dijkstra();

    int ans = 0;
    for (auto [a, b] : Es) {
        if (2 * D[a] < U || 2 * D[b] < U)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}