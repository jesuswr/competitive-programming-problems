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
const int MAXN = 1e3; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, K, P;
int A[MAXN], B[2 * MAXN];

ll DP[MAXN][2 * MAXN];
ll f(int i, int j) {
    if (i == N)
        return 0;
    if (j == K)
        return LLINF;
    ll &ret = DP[i][j];
    if (ret != -1)
        return ret;
    ret = min(f(i, j + 1), max((ll)abs(A[i] - B[j]) + abs(B[j] - P), f(i + 1, j + 1)));
    return ret;
}

int main() {
    memset(DP, -1, sizeof(DP));
    riii(N, K, P);
    FOR(i, 0, N) ri(A[i]);
    FOR(i, 0, K) ri(B[i]);
    sort(A, A + N);
    sort(B, B + K);
    printf("%lld\n", f(0, 0));
    return 0;
}