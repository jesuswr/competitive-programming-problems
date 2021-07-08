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
int V, E;
vector<pair<int, ll>> G[MAXN];
set<pii> BAD;

vector<int> dijkstra(int s = 1, int t = 0) {
    vector<ll> D(V, LLINF);
    vector<int> F(V, -1);
    priority_queue< pair<ll, int> > pq;

    D[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [c, v] = pq.top(); pq.pop();
        c = -c;
        if (D[v] < c)
            continue;

        for (auto [u, cu] : G[v]) {
            if (D[u] > c + cu) {
                D[u] = c + cu;
                F[u] = v;
                pq.push({ -D[u], u});
            }
        }
    }


    vector<ll> D2(V, LLINF);
    vector<int> F2(V, -1);
    priority_queue< pair<ll, int> > pq2;

    D2[t] = 0;
    pq2.push({0, t});

    while (!pq2.empty()) {
        auto [c, v] = pq2.top(); pq2.pop();
        c = -c;
        if (D2[v] < c)
            continue;

        for (auto [u, cu] : G[v]) {
            if (D2[u] > c + cu && u != F[v]) {
                D2[u] = c + cu;
                F2[u] = v;
                pq2.push({ -D2[u], u});
            }
        }
    }

    vi ret;
    if (D2[s] != LLINF) {
        while (s != -1) {
            ret.pb(s);
            s = F2[s];
        }
        reverse(ALL(ret));
    }
    return ret;

}

int main() {
    rii(V, E);
    FOR(_, 0, E) {
        int a, b, c; riii(a, b, c);
        G[a].pb({b, c});
        G[b].pb({a, c});
    }

    auto path = dijkstra();
    if (path.size() == 0)
        printf("impossible\n");
    else {
        printf("%d", SZ(path));
        for (auto p : path) printf(" %d", p);
        printf("\n");
    }


    return 0;
}