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
const int MAXN = 101; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
int A[MAXN];
int B[MAXN];

ll DP[MAXN][MAXN * MAXN];
ll f(int p, int a_sum, int b_sum) {
    if (p == N) return 0;
    if (DP[p][a_sum] != -1)
        return DP[p][a_sum];
    DP[p][a_sum] = 1ll * (N - 1) * (1ll * A[p] * A[p] + 1ll * B[p] * B[p]);
    ll op1 = 2ll * A[p] * a_sum + 2ll * B[p] * b_sum + f(p + 1, a_sum + A[p], b_sum + B[p]);
    ll op2 = 2ll * B[p] * a_sum + 2ll * A[p] * b_sum + f(p + 1, a_sum + B[p], b_sum + A[p]);
    return DP[p][a_sum] = DP[p][a_sum] + min(op1, op2);
}

void solve() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    FOR(i, 0, N) ri(B[i]);
    FOR(i, 0, N + 1) FOR(j, 0, MAXN * MAXN) DP[i][j] = -1;
    printf("%lld\n", f(0, 0, 0));
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}