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
const int maxN = 310; // CAMBIAR ESTE

// GJNM
int n;
int m[maxN][maxN];
int dp[maxN][maxN][2 * maxN];


int f(int col1, int col2, int diag) {
	int row1 = diag - col1, row2 = diag - col2;
	if ( col1 < 0 || col2 < 0 || row1 < 0 || row2 < 0 )
		return -INF;
	if ( diag == 0 )
		return m[0][0];
	if ( dp[col1][col2][diag] != -400000 )
		return dp[col1][col2][diag];

	int &ret = dp[col1][col2][diag];

	ret = f(col1 - 1, col2, diag - 1);
	ret = max(ret, f(col1 - 1, col2 - 1, diag - 1));
	ret = max(ret, f(col1, col2, diag - 1));
	ret = max(ret, f(col1, col2 - 1, diag - 1));

	ret = ret + ( col1 == col2 ? m[col1][row1] : m[col1][row1] + m[col2][row2]);

	return ret;
}


int main() {
	ri(n);
	FOR(i, 0, n) {
		FOR(j, 0, n) {
			ri(m[i][j]);
		}
	}
	int diag_num = n + n - 2;
	FOR(i, 0, n+1) {
		FOR(j, 0, n+1) {
			FOR(k, 0, diag_num + 3) {
				dp[i][j][k] = -400000;
			}
		}
	}

	ll ans = f(n - 1, n - 1, diag_num);
	printf("%lld\n", ans);
	return 0;
}