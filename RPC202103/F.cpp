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
const int MAXN = 1010; // CAMBIAR ESTE

// GJNM
int V, E;
int P, C;
int START[110];
int GOAL = 0;
vector<pair<int, ll>> G[MAXN];
vector<ll> D[MAXN];

void dijkstra(int s) {
    D[s].clear();
    FOR(i, 0, V) D[s].pb(LLINF);
    D[s][s] = 0;
    priority_queue< pair < ll, int> > pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int x = pq.top().S;
        ll dst = -pq.top().F;
        pq.pop();
        if (D[s][x] < dst) continue;
        for (auto aux : G[x]) {
            int y = aux.F;
            ll c = aux.S;
            if (D[s][y] > D[s][x] + c) {
                D[s][y] = D[s][x] + c;
                pq.push({ -D[s][y], y});
            }
        }
    }
}


int main() {
    rii(V, E); rii(P, C);
    FOR(i, 0, P) {
        ri(START[i]);
        START[i]--;
    }
    FOR(i, 0, E) {
        int a, b; ll c;
        rii(a, b); rl(c);
        --a, --b;
        G[a].pb({b, c});
        G[b].pb({a, c});
    }
    dijkstra(GOAL);
    FOR(i, 0, P) dijkstra(START[i]);

    ll ans = LLINF;
    FOR(i, 0, V) {
        ll curr_ans = 0;
        FOR(j, 0, P) {
            ll act = D[START[j]][GOAL];
            if (D[START[j]][i] + D[GOAL][i] <= act)
                act = min(act, C + D[START[j]][i]);
            curr_ans += act;
        }
        //printf("%d : %lld\n", i + 1, curr_ans);
        ans = min(ans, curr_ans);
    }
    printf("%lld\n", ans);
    return 0;
}