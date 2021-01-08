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

using namespace std;

typedef long long ll;
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
int N, M;
vector<pair<int, ll>> G[MAXN];
ll DIST[MAXN];

void dijkstra(int s) {
    FOR(i, 0, N) DIST[i + 1] = LLINF;
    priority_queue< pair< ll , int > > pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int x = pq.top().S;
        ll cost = -pq.top().F;
        pq.pop();
        if (cost != DIST[x]) continue;
        for (auto aux : G[x]) {
            int y = aux.F;
            ll c = aux.S;
            if (DIST[y] > DIST[x] + c) {
                DIST[y] = DIST[x] + c;
                pq.push({ -DIST[y], y});
            }
        }
    }
}

int main() {
    rii(N, M);
    FOR(i, 0, M) {
        int a, b; ll w; rii(a, b), rl(w);
        G[a].pb({b, 2ll * w});
        G[b].pb({a, 2ll * w});
    }
    FOR(i, 1, N + 1) {
        ll w; rl(w);
        G[0].pb({i, w});
    }
    dijkstra(0);
    FOR(i, 1, N + 1) printf("%lld ", DIST[i]);
    printf("\n");
    return 0;
}