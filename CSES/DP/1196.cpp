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
const int MAXN = 3e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
vii G[MAXN];
priority_queue<ll> BST[MAXN];

int main() {
    int n, m, k; riii(n, m, k);
    priority_queue<pair<ll, int>> pq;
    FOR(_, 0, m) {
        int a, b, c; riii(a, b, c);
        G[a - 1].pb({b - 1, c});
    }

    BST[0].push(0);
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [c, u] = pq.top(); pq.pop();
        c = -c;
        if (c > BST[u].top())
            continue;
        for (auto [v, e] : G[u]) {
            if (SZ(BST[v]) < k) {
                pq.push({ -(c + e), v});
                BST[v].push(c + e);
            }
            else if (BST[v].top() > c + e) {
                BST[v].pop();
                pq.push({ -(c + e), v});
                BST[v].push(c + e);
            }
        }
    }

    vector<ll> ans;
    FOR(_, 0, k) {
        ans.pb(BST[n - 1].top());
        BST[n - 1].pop();
    }
    FOR(i, 0, k) printf("%lld ", ans[k - 1 - i]);
    printf("\n");
    return 0;
}