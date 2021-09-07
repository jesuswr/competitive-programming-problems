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
const int MAXN = 1e5; // CAMBIAR ESTE
const int MOD = 1e9 + 7;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
ll DP[500 * 501];
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
    DP[0] = 1;
    int n; ri(n);
    int mx = (n * (n + 1)) / 2;
    for (int x = 1; x <= n; ++x)
        for (int sm = mx; sm >= x; --sm) {
            DP[sm] += DP[sm - x];
            if (DP[sm] >= MOD)
                DP[sm] -= MOD;
        }

    if (mx % 2 == 0)
        printf("%lld\n", (DP[mx / 2] * binpow(2, MOD - 2)) % MOD);
    else
        printf("0\n");
    return 0;
}