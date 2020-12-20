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
const int MAXN = 2e6; // CAMBIAR ESTE

// GJNM
int n;
string s[2];
bool vis[MAXN][2];
int DP[MAXN][2];

int f(int p, int x) {
    if (p == n)
        return 0;
    if (vis[p][x])
        return DP[p][x];
    vis[p][x] = true;
    int act = s[0][p] - s[1][p];
    if (x == 0) {
        DP[p][x] = max(DP[p][x], act + f(p + 1, x));
        DP[p][x] = max(DP[p][x], act + f(p + 1, 1 - x));
    }
    else {
        DP[p][x] = min(DP[p][x], act + f(p + 1, x));
        DP[p][x] = min(DP[p][x], act + f(p + 1, 1 - x));
    }
    return DP[p][x];
}

int main() {
    ri(n);
    cin >> s[0];
    cin >> s[1];
    int cnt[2] = {0, 0};
    FOR(j, 0, 2) FOR(i, 0, n) cnt[j] += s[j][i] == '0';
    if (cnt[0] != cnt[1]) {
        printf("-1\n");
        return 0;
    }

    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans = max(ans, max(abs(f(i, 1)), f(i, 0)));
    }
    printf("%d\n", ans);
    return 0;
}