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

// GJNM
int DP[31][31][51];

int f(int n, int m, int k) {
    if (DP[n][m][k] != -1) return DP[n][m][k];
    int &ret = DP[n][m][k] = INF;
    if (k == n * m || k == 0) return ret = 0;
    if (k > n * m) return ret;
    FOR(k0, 0, k + 1) {
        FOR(n0, 1, n) ret = min(ret, m * m + f(n0, m, k0) + f(n - n0, m, k - k0));
        FOR(m0, 1, m) ret = min(ret, n * n + f(n, m0, k0) + f(n, m - m0, k - k0));
    }
    return ret;
}


int main() {
    int t; ri(t);
    memset(DP, -1, sizeof(DP));
    while (t--) {
        int n, m, k; riii(n, m, k);
        printf("%d\n", f(n, m, k));
    }
    return 0;
}