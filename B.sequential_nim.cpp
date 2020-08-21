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
const int MAXN = 1e6; // CAMBIAR ESTE

// GJNM
bool dp[MAXN][3];
bool vis[MAXN][3];
int n;
int a[MAXN];


int f(int pos, int take) {
	if ( pos == n )
		return false;
	if ( vis[pos][take] )
		return dp[pos][take];
	vis[pos][take] = true;
	dp[pos][take] = true;
	bool &ret = dp[pos][take];

	if ( take == 0 ) {
		if ( a[pos] > 1 ) {
			ret &= (!f(pos, 1));
		}
		else {
			ret &= (!f(pos + 1, 0));
			ret &= (!f(pos + 1, 1));
		}
	}
	else {
		ret &= (!f(pos + 1, 0));
		ret &= (!f(pos + 1, 1));
	}
	//printf("%d %d %d\n", pos, take, ret);

	return ret;
}


void solve() {
	ri(n);
	FOR(i, 0, n) {
		ri(a[i]);
		dp[i][0] = dp[i][1] = dp[i][2] = vis[i][0] = vis[i][1] = vis[i][2] = false;
		a[i] = min(a[i], 2);
	}

	if ( f(0, 0) || f(0, 1)) {
		printf("First\n");
	}
	else {
		printf("Second\n");
	}

}

int main() {
	int t;
	ri(t);
	while (t--) {
		solve();
	}

	return 0;
}