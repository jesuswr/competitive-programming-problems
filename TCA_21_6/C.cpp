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
const int MAXN = 61; // CAMBIAR ESTE
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M, R; // cities, cars, rounds
int D[MAXN][MAXN][MAXN];
int DP[MAXN][MAXN][MAXN];

int main() {
    riii(N, M, R);
    FOR(i, 0, N) FOR(j, 0, N) FOR(k, 0, N) DP[i][j][k] = INF;
    FOR(c, 0, M) {
        FOR(i, 0, N) FOR(j, 0, N) ri(D[c][i][j]);
        FOR(k, 0, N) FOR(i, 0, N) FOR(j, 0, N) D[c][i][j] = min(D[c][i][j], D[c][i][k] + D[c][k][j]);
        FOR(i, 0, N) FOR(j, 0, N) DP[0][i][j] = min(DP[0][i][j], D[c][i][j]);
    }
    FOR(r, 1, N) FOR(i, 0, N) FOR(j, 0, N) {
        DP[r][i][j] = INF;
        FOR(k, 0, N) DP[r][i][j] = min(DP[r][i][j], DP[r - 1][i][k] + DP[0][k][j]);
    }
    while (R--) {
        int s, t, k; riii(s, t, k);
        printf("%d\n", DP[min(k, N - 1)][s - 1][t - 1]);
    }
    return 0;
}