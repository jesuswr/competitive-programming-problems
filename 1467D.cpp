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

using namespace std;

typedef long long ll;
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
const int MAXN = 5010; // CAMBIAR ESTE
const ll MOD = 1e9 + 7;

// GJNM
int N, K, Q;
ll A[MAXN];
ll DP[MAXN][MAXN];
ll CNT[MAXN];
ll CNT2[MAXN][MAXN];

ll f(int p, int k) {
    if (DP[p][k] != -1) return DP[p][k];
    if (k == 0) return DP[p][k] = 1;
    DP[p][k] = 0;
    if (p > 0) DP[p][k] += f(p - 1, k - 1);
    if (p < N - 1) DP[p][k] += f(p + 1, k - 1);
    if (DP[p][k] >= MOD) DP[p][k] -= MOD;
    return DP[p][k];
}


int main() {
    riii(N, K, Q);
    memset(DP, -1, sizeof(DP));
    FOR(i, 0, N) rl(A[i]);
    FOR(i, 0, N) f(i, K);
    for (int j = K; j >= 0; j--) FOR(i, 0, N) {
        if (j == K) CNT2[i][j] = 1;
        else {
            if (i > 0) CNT2[i][j] += CNT2[i - 1][j + 1];
            if (i + 1 < N) CNT2[i][j] += CNT2[i + 1][j + 1];
            if (CNT2[i][j] >= MOD) CNT2[i][j] -= MOD;
        }
        CNT[i] += f(i, j) * CNT2[i][j];
        CNT[i] %= MOD;
    }


    ll ans = 0;
    FOR(i, 0, N) ans = (ans + CNT[i] * A[i]) % MOD;
    while (Q--) {
        int i; ll x; ri(i), rl(x); --i;
        ans = (ans - CNT[i] * A[i]) % MOD;
        ans = (ans + MOD) % MOD;
        A[i] = x;
        ans = (ans + A[i] * CNT[i]) % MOD;
        printf("%lld\n", ans);
    }

    return 0;
}