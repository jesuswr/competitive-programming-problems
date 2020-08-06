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
const int maxN = 2e5 + 10; // CAMBIAR ESTE

// GJNM
ll a[maxN], pre[maxN];
ll dp[maxN][2];
bool vis[maxN][2];
int n;

ll f(int ind, int mode) {
	if ( ind == n )
		return 0;
	if ( ind == n - 1 && mode )
		return -LLINF;
	if ( vis[ind][mode] )
		return dp[ind][mode];
	vis[ind][mode] = true;
	dp[ind][mode] = 0;
	if ( mode & 1 ) {
		dp[ind][mode] = (ind & 1 ? a[ind] : a[ind + 1]);
		dp[ind][mode] += max(f(ind + 2, 1), pre[n - 1] - pre[ind + 1]);
	}
	else {
		dp[ind][mode] = ( ind & 1 ? 0 : a[ind]);
		dp[ind][mode] += max(f(ind + 1, 1), f(ind + 1, 0));
	}
	return dp[ind][mode];
}

int main() {
	int t;
	ri(t);
	while (t--) {
		ri(n);
		FOR(i, 0, n) {
			rl(a[i]);
			vis[i][1] = vis[i][0] = false;
		}
		vis[n][0] = vis[n][1] = false;
		pre[0] = a[0];
		FOR(i, 1, n) {
			pre[i] = pre[i - 1];
			if ( ~i & 1 )
				pre[i] += a[i];
		}

		printf("%lld\n", max(f(0, 0), f(0, 1)));
	}
	return 0;
}