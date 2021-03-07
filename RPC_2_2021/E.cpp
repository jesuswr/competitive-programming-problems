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
const int MAXN = 510; // CAMBIAR ESTE

// GJNM
int R, C, N;
int MAT[MAXN][MAXN];

bool valid(int r, int c) {
    return min(r, c) >= 0 && r < R && c < C && MAT[r][c] != -1;
}

int is_pass(int r, int c) {
    if (!valid(r + 1, c) || MAT[r + 1][c] <= MAT[r][c]) return 0;
    if (!valid(r - 1, c) || MAT[r - 1][c] <= MAT[r][c]) return 0;
    if (!valid(r, c + 1) || MAT[r][c + 1] >= MAT[r][c]) return 0;
    if (!valid(r, c - 1) || MAT[r][c - 1] >= MAT[r][c]) return 0;
    return 1;
}

int DP[MAXN][MAXN][11];

int f(int r, int c, int n) {
    if (c == C) {
        if (n != 0) return INF;
        else return 0;
    }
    if (n < 0 || !valid(r, c)) return INF;
    if (DP[r][c][n] != -1) return DP[r][c][n];
    int &ret = DP[r][c][n];
    int is_p = is_pass(r, c);
    ret = MAT[r][c];
    ret += min({
        f(r + 1, c + 1, n - is_p),
        f(r, c + 1, n - is_p),
        f(r - 1, c + 1, n - is_p)
    });
    //printf("%d %d %d : %d\n", r, c, n, ret);
    return ret;
}

int main() {
    memset(DP, -1, sizeof(DP));
    riii(R, C, N);
    FOR(i, 0, R) FOR(j, 0, C) ri(MAT[i][j]);
    int ans = INF;
    FOR(i, 0, R) if (valid(i, 0)) ans = min(ans, f(i, 0, N));
    if (ans >= INF) printf("impossible\n");
    else printf("%d\n", ans);

    return 0;
}