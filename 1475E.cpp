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
const int MAXN = 1e5; // CAMBIAR ESTE
const int MOD = 1e9 + 7;

// GJNM
int dp[1010][1010];
int f(int n, int k) {
    if (n == k || k == 0) return 1;
    if (dp[n][k] != 0) return dp[n][k];
    dp[n][k] = f(n - 1, k - 1) + f(n - 1, k);
    if (dp[n][k] >= MOD) dp[n][k] -= MOD;
    return dp[n][k];
}

void solve() {
    int n, k; rii(n, k);
    map<int, int> total;
    FOR(i, 0, n) {
        int a; ri(a);
        total[a]++;
    }
    map<int, int> take;
    for (auto it = total.rbegin(); it != total.rend(); it++) {
        pii tmp = *it;
        auto aux = min(k, tmp.S);
        k -= aux;
        if (aux > 0) take[tmp.F] = aux;
    }
    auto mn = *take.begin();
    printf("%d\n", f(total[mn.F], mn.S));
}

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}