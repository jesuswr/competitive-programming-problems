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
int N, M;
vector<pair<int, ll>> G[MAXN];
ll H[MAXN];
ll CST[MAXN];

int main() {
    rii(N, M);
    FOR(i, 0, N) rl(H[i]);
    FOR(_, 0, M) {
        int a, b; rii(a, b);
        --a, --b;
        if (H[a] < H[b])
            swap(a, b);
        G[a].pb({b, H[a] - H[b]});
        G[b].pb({a, -2 * (H[a] - H[b])});
    }
    FOR(i, 1, N) CST[i] = -LLINF;
    priority_queue< tuple<ll, ll, int> > pq; // {altura, costo}
    pq.push({ H[0], 0, 0});
    ll mx = 0;
    while (!pq.empty()) {
        auto [_, cst, u] = pq.top();
        pq.pop();
        if (cst != CST[u]) continue;
        mx = max(mx, cst);
        for (auto [v, ec] : G[u]) {
            if (CST[v] < cst + ec) {
                CST[v] = cst + ec;
                pq.push({ H[v], CST[v], v});
            }
        }
    }
    printf("%lld\n", mx);
    return 0;
}