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
const int MOD = 998244353;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, K;
int A[MAXN + 10];
int inv[200 + 1];


int pick(ll x, int y) {
    if (y < 0 || y > x)
        return 0;
    assert(x > 0);
    int ret = 1;
    for (int i = 1; i <= y; ++i) {
        ret = (1ll * ret * (x - i + 1)) % MOD;
        ret = (1ll * ret * inv[i]) % MOD;
    }
    return ret;
}

int main() {
    rii(N, K);
    FOR(i, 0, N) ri(A[i]);

    inv[1] = 1;
    for (int i = 2; i <= K; i ++) inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;

    int ans = 1;

    auto C = [&](long long x, int y) -> int {
        if (y < 0 || y > x) {
            return 0;
        }
        int c = 1;
        for (int i = 1; i <= y; i++) {
            c = (1ll * c * (x - i + 1)) % MOD;
            c = (1ll * c * inv[i]) % MOD;
        }
        return c;
    };

    FOR(i, 1, N) {
        ans = (1ll * ans * C(A[i] + K - 1, K - 1)) % MOD;
        A[0] -= A[i];
        if (A[0] < K) {
            printf("0\n");
            return 0;
        }
    }

    ans = (1ll * ans * C(A[0] - 1, K - 1)) % MOD;
    printf("%d\n", ans);

    return 0;
}