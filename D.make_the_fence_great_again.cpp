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
const ll LLINF = 1e18 + 10;
const int maxN = 4e5; // CAMBIAR ESTE

// GJNM
int n;
ll a[maxN], b[maxN];
ll dp[maxN][3];

ll f(int ind, int add) {
	if ( ind == n )
		return 0;
	if ( dp[ind][add] != -666 )
		return dp[ind][add];

	dp[ind][add] = LLINF;
	FOR(i, 0, 3) {
		if ( a[ind] + add == a[ind + 1] + i )
			continue;
		dp[ind][add] = min(dp[ind][add], add * b[ind] + f(ind + 1, i));
	}
	return dp[ind][add];
}

int main() {
	int q;
	ri(q);
	while (q--) {
		ri(n);
		FOR(i, 0, n) {
			rll(a[i], b[i]);
			dp[i][0] = dp[i][1] = dp[i][2] = -666;
		}
		a[n] = -INF;
		printf("%lld\n", min(f(0, 0), min(f(0, 1), f(0, 2))) );
	}

	return 0;
}