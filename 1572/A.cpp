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
const int MAXN = 2e5 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
vi G[MAXN];
int DEG[MAXN];
void solve() {
    int n; ri(n);
    FOR(i, 0, n) {
        DEG[i] = 0;
        G[i].clear();
    }
    FOR(i, 0, n) {
        int k; ri(k);
        while (k--) {
            int a; ri(a);
            G[a - 1].pb(i);
            ++DEG[i];
        }
    }
    priority_queue<pii> pq;
    FOR(i, 0, n) if (DEG[i] == 0)
        pq.push({0, -i});

    int ans = 0;
    FOR(_, 0, n) {
        if (pq.empty()) {
            printf("-1\n");
            return;
        }
        auto [a, u] = pq.top(); pq.pop();
        u = -u;
        a = -a;
        ans = a + 1;
        for (auto v : G[u]) {
            DEG[v]--;
            if (DEG[v] == 0) {
                if (v < u)
                    pq.push({ -a - 1, -v});
                else
                    pq.push({ -a, -v});
            }
        }
    }
    printf("%d\n", ans);
}


int main() {
    int t = 1; ri(t);
    while (t--) solve();
    return 0;
}