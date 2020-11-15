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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define all(s) s.begin(),s.end()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 5010; // CAMBIAR ESTE

// GJNM
int ans;
int n1, n2;
string s1, s2;
int dp[MAXN][MAXN];
bool vis[MAXN][MAXN];

int f(int p1, int p2) {
    if (p1 == n1 || p2 == n2)
        return 0;
    if (vis[p1][p2])
        return dp[p1][p2];
    vis[p1][p2] = true;
    int &ret = dp[p1][p2] = 0;

    if (s1[p1] == s2[p2])
        ret = max(ret, f(p1 + 1, p2 + 1) + 2);
    ret = max(ret, f(p1 + 1, p2) - 1);
    ret = max(ret, f(p1, p2 + 1) - 1);
    ans = max(ans, ret);
    return ret;
}

int main() {
    rii(n1, n2);
    cin >> s1; cin >> s2;
    f(0, 0);
    printf("%d\n", ans);
    return 0;
}