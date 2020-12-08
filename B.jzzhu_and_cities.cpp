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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
struct EDGE {
    int to, cost, bad;
};
int n, m, k;
vector<EDGE> G[MAXN];
bool need_bad[MAXN];

ll dist[MAXN];
void dijkstra(int s) {
    FOR(i, 0, n) dist[i] = LLINF;

    priority_queue<pair<ll, int>> pq;
    dist[s] = 0; pq.push({0, s});

    while (!pq.empty()) {
        int x = pq.top().S;
        ll d = -pq.top().F;
        pq.pop();

        if (d != dist[x]) continue;

        for (auto e : G[x]) {
            int y = e.to;
            ll c = e.cost;
            bool bad = e.bad;

            if (bad) {
                if (dist[y] > d + c) {
                    need_bad[y] = true;
                    dist[y] = d + c;
                    pq.push({ -(d + c), y});
                }
            }
            else {
                if (dist[y] >= d + c && need_bad[y]) {
                    need_bad[y] = false;
                    dist[y] = d + c;
                    pq.push({ -(d + c), y});
                }
                else if (dist[y] > d + c) {
                    need_bad[y] = false;
                    dist[y] = d + c;
                    pq.push({ -(d + c), y});
                }

            }
        }
    }

}

int main() {
    riii(n, m, k);
    FOR(i, 0, m) {
        int a, b, c; riii(a, b, c); a--, b--;
        G[a].pb({b, c, 0});
        G[b].pb({a, c, 0});
    }
    FOR(i, 0, k) {
        int a, b, c; rii(b, c); b--;
        a = 0;
        G[a].pb({b, c, 1});
        G[b].pb({a, c, 1});
    }

    dijkstra(0);
    int ans = k;
    FOR(i, 0, n) ans -= need_bad[i];
    printf("%d\n", ans);

    return 0;
}