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
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
ll binPow(ll b, ll e) {
    ll ret = 1;
    while (e) {
        if (e & 1) ret = (ret * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return ret;
}

int main() {
    ll n; rl(n);
    int ans = 0;
    for (ll i = 1, j; i <= n; i = j) {
        ll q = n / i; j = n / q + 1;
        ll x = j - i, y = i + j - 1;
        if (x % 2 == 0) x /= 2;
        else y /= 2;
        x %= MOD, y %= MOD;
        ans = (ans + q % MOD * x % MOD * y % MOD) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}