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
const int MAXN = 1e3 + 10; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int DP[MAXN];
void pre() {
    FOR(i, 0, MAXN) DP[i] = INF;
    DP[1] = 0;
    for (int i = 1; i < MAXN; ++i) {
        for (int x = 1; x <= i; ++x)
            if (i + i / x < MAXN)
                DP[i + i / x] = min(DP[i + i / x], DP[i] + 1);
    }
}

int N, K;
int B[MAXN], C[MAXN];

int dp[MAXN][13 * MAXN + 10];

void solve() {
    rii(N, K);
    FOR(i, 0, N) ri(B[i]);
    FOR(i, 0, N) ri(C[i]);
    int sm = 0;
    FOR(i, 0, N) sm += DP[B[i]];
    K = min(K, sm); // K <= 13 * 1000
    int mx = 0;
    for (int i = 0; i <= K; ++i) dp[N][i] = 0;
    for (int i = N - 1; i >= 0; --i) {
        for (int k = 0; k <= K; ++k) {
            dp[i][k] = dp[i + 1][k];
            if (k - DP[B[i]] >= 0) {
                // printf("alo %d\n", C[i]);
                dp[i][k] = max(dp[i][k], dp[i + 1][k - DP[B[i]]] + C[i]);
            }
            // printf("%d\n", dp[i][k]);
            mx = max(mx, dp[i][k]);
        }
    }
    printf("%d\n", mx);
}


int main() {
    pre();
    int t; ri(t);
    while (t--) solve();
    return 0;
}