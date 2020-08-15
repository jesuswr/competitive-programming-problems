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

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 3010; // CAMBIAR ESTE

// GJNM
bool vis[maxN][maxN][4];
ll dp[maxN][maxN][4];
int r, c, k;
ll v[maxN][maxN];

ll f(int row, int col, int left) {
    if ( row >= r || col >= c )
        return -LLINF;
    if ( row == r - 1 && col == c - 1) {
        if ( left > 0 )
            return v[row][col];
        else
            return 0;
    }
    if ( vis[row][col][left] )
        return dp[row][col][left];
    vis[row][col][left] = true;

    ll &ret = dp[row][col][left] = 0;

    ret = max(ret, f(row + 1, col, 3));
    ret = max(ret, f(row, col + 1, left));

    if ( left > 0 && v[row][col] > 0 ) {
        ret = max(ret, v[row][col] + f(row + 1, col, 3));
        ret = max(ret, v[row][col] + f(row, col + 1, left - 1));
    }
    return ret;
}

int main() {
    riii(r, c, k);
    FOR(i, 0, k) {
        int aux_r, aux_c;
        rii(aux_r, aux_c);
        rl(v[aux_r - 1][aux_c - 1]);
    }

    printf("%lld\n", f(0, 0, 3));

    return 0;
}