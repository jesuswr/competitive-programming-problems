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
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
int A[MAXN], B[MAXN];
int DP[MAXN][MAXN * MAXN];

int main() {
    FOR(i, 0, MAXN) FOR(j, 0, MAXN * MAXN) DP[i][j] = -1e9;
    ri(N);
    FOR(i, 0, N) rii(A[i], B[i]);
    long double tot = 0;
    FOR(i, 0, N) tot += B[i];
    DP[0][0] = 0;
    for (int i = 0; i < N; ++i) for (int k = N; k >= 1; --k) for (int as = 100 * 100; as >= A[i]; --as) {
                DP[k][as] = max(DP[k][as], B[i] + DP[k - 1][as - A[i]]);
            }
    FOR(k, 1, N + 1) {
        long double bst = 0;
        FOR(as, 1, 100 * 100 + 1) {
            bst = max(bst, (ld)min((ld)as, (ld)(tot + DP[k][as]) / 2.0) );
        }
        printf("%.10Lf ", bst);
    }

    return 0;
}