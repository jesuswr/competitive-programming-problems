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
const int MAXN = 1e5 + 69; // CAMBIAR ESTE
const int MOD = 1e9 + 7;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M;
vii G[MAXN];
ll D[MAXN], MN[MAXN], MX[MAXN], NP[MAXN];

int main() {
    rii(N, M);
    FOR(_, 0, M) {
        int a, b, c; riii(a, b, c);
        G[a - 1].pb({b - 1, c});
    }
    FOR(i, 0, N) D[i] = LLINF;

    D[0] = 0; MN[0] = MX[0] = 0; NP[0] = 1;
    priority_queue<pair<ll, int>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [c, u] = pq.top();
        c = -c;
        pq.pop();
        if (c != D[u])
            continue;
        for (auto [v, e] : G[u]) {
            if (D[v] > D[u] + e) {
                D[v] = D[u] + e;
                MN[v] = MN[u] + 1;
                MX[v] = MX[u] + 1;
                NP[v] = NP[u];
                pq.push({ -D[v], v});
            }
            else if (D[v] == D[u] + e) {
                MN[v] = min(MN[v], MN[u] + 1);
                MX[v] = max(MX[v], MX[u] + 1);
                NP[v] += NP[u];
                if (NP[v] >= MOD)
                    NP[v] -= MOD;
            }
        }
    }
    printf("%lld %lld %lld %lld\n", D[N - 1], NP[N - 1], MN[N - 1], MX[N - 1]);
    return 0;
}