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
const int MAXN = 3e5 + 10; // CAMBIAR ESTE

// GJNM
struct EDGE {
    int to, w, ind;
};

int N, M;
vector<EDGE> G[MAXN];

ll ans;
vi ord;

ll D[MAXN];
pair<ll, ll> LST[MAXN];
priority_queue<pair<ll, ll>> pq;
void dijkstra(int s) {
    FOR(i, 0, N) D[i] = LLINF, LST[i].F = LST[i].S = LLINF;
    pq.push({0, s}); D[s] = 0;

    while (!pq.empty()) {
        ll x = pq.top().S;
        ll c = -pq.top().F;
        pq.pop();
        if (c != D[x]) continue;
        for (auto aux : G[x]) {
            ll y = aux.to;
            ll w = aux.w;
            ll i = aux.ind;
            if (D[y] > D[x] + w) {
                D[y] = D[x] + w;
                pq.push({ -D[y], y});
            }
            if (D[y] == D[x] + w) {
                if (LST[y].F > w) {
                    LST[y].F = w;
                    LST[y].S = i;
                }
            }
        }
    }
}

int main() {
    rii(N, M);
    FOR(i, 0, M) {
        int a, b, w; riii(a, b, w); --a, --b;
        G[a].pb({b, w, i});
        G[b].pb({a, w, i});
    }
    int s; ri(s); --s;
    dijkstra(s);

    FOR(i, 0, N) {
        if (i != s) {
            ord.pb(LST[i].S + 1);
            ans += LST[i].F;
        }
    }

    printf("%lld\n", ans);
    for (auto i : ord) printf("%d ", i);
    printf("\n");
    return 0;
}