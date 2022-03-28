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
const ll MOD = 998244353;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
bool BAD[MAXN];
vi G[MAXN];
int DST[MAXN];

ll binpow(ll b, ll e) {
    ll r = 1;
    while (e) {
        if (e & 1) r = (r * b) % MOD;
        e >>= 1;
        b = (b * b) % MOD;
    }
    return r;
}

int main() {
    ri(N);
    FOR(i, 0, N) DST[i] = INF;
    FOR(i, 1, N) {
        int fi; ri(fi); --fi;
        BAD[fi] = 1;
        G[fi].pb(i);
        G[i].pb(fi);
    }
    queue<int> q;
    FOR(i, 0, N) if (!BAD[i]) {
        q.push(i);
        DST[i] = 1;
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : G[u]) {
            if (DST[u] + 1 < DST[v]) {
                DST[v] = DST[u] + 1;
                q.push(v);
            }
        }
    }
    ll sm = 0;
    FOR(i, 0, N) sm += DST[i];
    printf("%lld\n", ((sm % MOD) * binpow(N, MOD - 2)) % MOD);
    return 0;
}