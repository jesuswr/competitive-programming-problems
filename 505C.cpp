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
const int MAXN = 30011; // CAMBIAR ESTE
const int OFFSET = 300;

// GJNM
int n, d;
int good[MAXN];
bool vis[MAXN][600];
int dp[MAXN][600];

int f(int pos, int jump) {
    if (pos > 30000)
        return 0;
    if (vis[pos][jump])
        return dp[pos][jump];
    vis[pos][jump] = true;
    int &ret = dp[pos][jump] = 0;
    int delta_jump = jump - OFFSET + d;
    ret = max(ret, good[pos] + f(pos + delta_jump, jump));
    ret = max(ret, good[pos] + f(pos + delta_jump + 1, jump + 1));
    if (delta_jump > 1)
        ret = max(ret, good[pos] + f(pos + delta_jump - 1, jump - 1));
    return ret;
}

int main() {
    rii(n, d);
    FOR(i, 0, n) {
        int tmp; ri(tmp);
        good[tmp]++;
    }
    printf("%d\n", f(d, OFFSET));
    return 0;
}