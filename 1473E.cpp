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
const int MAXN = 9e5; // CAMBIAR ESTE

// GJNM
int N, M;
vector< pair<int, ll>> G[MAXN];
ll D[MAXN];

void dijkstra() {
    priority_queue< pair<ll, int> > pq;
    FOR(i, 0, 4 * N) D[i] = LLINF;
    D[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        int x = pq.top().S;
        ll w = -pq.top().F;
        pq.pop();
        if (D[x] != w) continue;
        for (auto nxt : G[x]) {
            int y = nxt.F;
            ll c = nxt.S;
            if (D[y] > D[x] + c) {
                D[y] = D[x] + c;
                pq.push({ -D[y], y});
            }
        }
    }
}

int main() {
    rii(N, M);
    FOR(_, 0, M) {
        int a, b, w; riii(a, b, w); --a, --b;
        FOR(i, 0, 4) {
            G[N * i + a].pb({N * i + b, w});
            G[N * i + b].pb({N * i + a, w});
        }
        G[a].pb({N + b, 0});
        G[b].pb({N + a, 0});

        G[a].pb({2 * N + b, 2 * w});
        G[b].pb({2 * N + a, 2 * w});

        G[N + a].pb({3 * N + b, 2 * w});
        G[N + b].pb({3 * N + a, 2 * w});

        G[2 * N + a].pb({3 * N + b, 0});
        G[2 * N + b].pb({3 * N + a, 0});

        G[a].pb({3 * N + b, w});
        G[b].pb({3 * N + a, w});
    }
    dijkstra();
    FOR(i, 1, N) printf("%lld ", D[3 * N + i]);
    printf("\n");
    return 0;
}