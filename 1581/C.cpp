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
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int n, m;
string M[469];
int DP[469][469];
int DP2[469][469];
void pre() {
    FOR(i, 0, n)FOR(j, 0, m) DP[i][j] = M[i][j] == '1';
    FOR(i, 0, n) FOR(j, 0, m) {
        if (i > 0) DP[i][j] += DP[i - 1][j];
        if (j > 0) DP[i][j] += DP[i][j - 1];
        if (i > 0 && j > 0) DP[i][j] -= DP[i - 1][j - 1];
    }
    FOR(i, 0, n)FOR(j, 0, m) DP2[i][j] = M[i][j] == '0';
    FOR(i, 0, n) FOR(j, 0, m) {
        if (i > 0) DP2[i][j] += DP2[i - 1][j];
        if (j > 0) DP2[i][j] += DP2[i][j - 1];
        if (i > 0 && j > 0) DP2[i][j] -= DP2[i - 1][j - 1];
    }
}
int query(int x1, int y1, int x2, int y2) {
    int ret = DP[x2][y2];
    if (x1 > 0)
        ret -= DP[x1 - 1][y2];
    if (y1 > 0)
        ret -= DP[x2][y1 - 1];
    if (x1 > 0 && y1 > 0)
        ret += DP[x1 - 1][y1 - 1];
    return ret;
}
int q2(int x1, int y1, int x2, int y2) {
    int ret = DP2[x2][y2];
    if (x1 > 0)
        ret -= DP2[x1 - 1][y2];
    if (y1 > 0)
        ret -= DP2[x2][y1 - 1];
    if (x1 > 0 && y1 > 0)
        ret += DP2[x1 - 1][y1 - 1];
    return ret;
}

void solve() {
    rii(n, m);
    FOR(i, 0, n) cin >> M[i];
    pre();
    int ans = 16;
    FOR(x1, 0, n) FOR(y1, 0, m) FOR(x2, x1 + 4, n) FOR(y2, y1 + 3, m) {
        int cnt = query(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
        if (cnt > ans)
            break;
        int cnt2 = q2(x1, y1 + 1, x1, y2 - 1) + q2(x2, y1 + 1, x2, y2 - 1)
                   + q2(x1 + 1, y1, x2 - 1, y1) + q2(x1 + 1, y2, x2 - 1, y2);
        if (cnt2 - q2(x1 + 1, y2, x2 - 1, y2) > ans)
            break;
        ans = min(ans, cnt + cnt2);
    }
    printf("%d\n", ans);

}


int main() {
    int t; ri(t);
    while (t--) solve();
}