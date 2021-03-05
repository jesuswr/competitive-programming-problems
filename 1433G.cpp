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
int N, M, K;
vii G[MAXN];
pii P[MAXN];

int D[MAXN][MAXN];
void dijkstra(int s) {
    FOR(i, 0, N) D[s][i] = INF;
    D[s][s] = 0;
    priority_queue< pii > pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int x = pq.top().S;
        int cst = -pq.top().F;
        pq.pop();
        if (cst != D[s][x]) continue;
        for (auto aux : G[x]) {
            int y = aux.F;
            int y_cst = aux.S;
            if (D[s][y] > cst + y_cst) {
                D[s][y] = cst + y_cst;
                pq.push({ -D[s][y], y});
            }
        }
    }
}

int main() {
    riii(N, M, K);
    FOR(_, 0, M) {
        int a, b, c; riii(a, b, c); --a, --b;
        G[a].pb({b, c});
        G[b].pb({a, c});
    }
    FOR(i, 0, K) {
        rii(P[i].F, P[i].S);
        --P[i].F;
        --P[i].S;
    }

    FOR(i, 0, N) dijkstra(i);

    int ans = 1e9 + 1e8;
    FOR(x, 0, N) {
        for (auto aux : G[x]) {
            int y = aux.F;
            int curr_ans = 0;
            FOR(i, 0, K) {
                curr_ans += min({
                    D[P[i].F][P[i].S],
                    D[P[i].F][x] + D[y][P[i].S],
                    D[P[i].S][x] + D[y][P[i].F]
                });
            }
            ans = min(ans, curr_ans);
        }
    }
    printf("%d\n", ans);
    return 0;
}