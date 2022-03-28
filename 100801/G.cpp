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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int V, E, K;
vi G[MAXN];
int DEG[MAXN];
vii edges;
vi ans;

set<int> ord, need;

void rem(int x) {
    ans.pb(x);
    for (auto v : G[x]) {
        DEG[v]--;
        if (DEG[v] == 0) ord.insert(v);
    }
}

int main() {
    freopen("graph.in", "r", stdin);
    freopen("graph.out", "w", stdout);
    riii(V, E, K);
    FOR(_, 0, E) {
        int a, b; rii(a, b);
        --a; --b;
        G[a].pb(b);
        DEG[b]++;
    }
    FOR(i, 0, V) if (DEG[i] == 0) ord.insert(i);

    while (!ord.empty() || !need.empty()) {
        if (K && !ord.empty() && (SZ(ord) > 1 || (!need.empty() && *ord.begin() < *need.rbegin())  )) {
            K--;
            need.insert(*ord.begin());
            ord.erase(*ord.begin());
        }
        else if (!ord.empty()) {
            int p = *ord.begin();
            ord.erase(p);
            rem(p);
        }
        else {
            int p = *need.rbegin();
            edges.pb({ans.back(), p});
            need.erase(p);
            rem(p);
        }
    }



    for (auto x : ans) printf("%d ", x + 1);
    printf("\n");
    printf("%d\n", SZ(edges));
    for (auto [u, v] : edges) printf("%d %d\n", u + 1, v + 1);

    return 0;
}