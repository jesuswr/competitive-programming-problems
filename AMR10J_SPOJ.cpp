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
const int MAXN = 110; // CAMBIAR ESTE
const int MOD = 1e9 + 7;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, K;
int D[MAXN];
bool V[MAXN];
bool MAT[MAXN][MAXN];

int dfs(int u) {
    V[u] = 1;
    FOR(i, 0, N) if (MAT[u][i] && !V[i]) {
        return dfs(i) + 1;
    }
    return 1;
}


ll binpow(ll b, ll e) {
    ll r = 1;
    while (e) {
        if (e & 1) r = (r * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return r;
}

int f(int n) {
    return (binpow(K - 1, n) + binpow(-1, n) * (K - 1)) % MOD;
}

void solve() {
    rii(N, K);
    FOR(i, 0, N) {
        int a; ri(a);
        MAT[a][i] = MAT[i][a] = 1;
        D[a]++;
        D[i]++;
    }
    ll ans = 1;
    FOR(i, 0, N) if (D[i] == 0) ans = (ans * K) % MOD;
    while (1) {
        bool fnd = 0;
        FOR(i, 0, N) if (D[i] == 1) {
            D[i]--;
            FOR(j, 0, N) if (MAT[i][j]) {
                D[j]--;
                MAT[i][j] = MAT[j][i] = 0;
            }
            fnd = 1;
            ans = (ans * (K - 1)) % MOD;
            break;
        }
        if (!fnd)
            break;
    }

    FOR(i, 0, N) if (D[i] && !V[i]) {
        int len = dfs(i);
        ans = (ans * f(len)) % MOD;
    }


    printf("%lld\n", ans);
    FOR(i, 0, N) {
        D[i] = 0;
        V[i] = 0;
        FOR(j, 0, N) MAT[i][j] = 0;
    }
}



int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}