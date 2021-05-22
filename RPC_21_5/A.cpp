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
int N, K, T;
ll A[MAXN];
ll B[MAXN];
vi G[MAXN];


ll dfs(int v, int f = -1) {
    priority_queue<ll> pq;
    for (auto u : G[v]) {
        if (u == f) continue;
        pq.push(dfs(u, v));
    }

    if (pq.empty()) return 1;

    if (f == -1) {
        while (!pq.empty()) {
            B[T] = pq.top();
            pq.pop();
            T++;
        }
        return 0;
    }
    else {
        ll ret = pq.top();
        pq.pop();
        while (!pq.empty()) {
            B[T] = pq.top();
            pq.pop();
            T++;
        }
        return ret + 1;
    }
}


int main() {
    rii(N, K);
    FOR(i, 0, K) rl(A[i]);
    FOR(i, 1, N) {
        int a; ri(a);
        G[a].pb(i);
    }
    dfs(0);
    sort(A, A + K);
    sort(B, B + K);
    ll ans = 0;
    FOR(i, 0, K) ans += A[i] * B[i];
    printf("%lld\n", ans);
    return 0;
}