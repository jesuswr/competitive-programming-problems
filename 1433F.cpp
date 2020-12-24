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
const int MAXN = 2e5; // CAMBIAR ESTE

// GJNM
int n, m, k;
int a[70][70];
int dp[70][70][40][70]; // row / col / cnt / mod

int f(int r, int c, int cnt, int md) {
    if (r == n && md == 0)
        return 0;
    if (r == n)
        return -INF;
    if (c == m)
        return f(r + 1, 0, 0, md);
    if (dp[r][c][cnt][md] != -1)
        return dp[r][c][cnt][md];

    int &ret = dp[r][c][cnt][md];
    if (cnt < m / 2) {
        ret = a[r][c] + f(r, c + 1, cnt + 1, ((md - a[r][c]) % k + k) % k);
        ret = max(ret, f(r, c + 1, cnt, md));
    }
    else
        ret = f(r, c + 1, cnt, md);
    return ret;
}



int main() {
    riii(n, m, k);
    FOR(i, 0, n) FOR(j, 0, m) ri(a[i][j]);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", f(0, 0, 0, 0));

    return 0;
}