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
const int maxN = 1010; // CAMBIAR ESTE

// GJNM
int n;
double dp[maxN];
ll X[maxN], Y[maxN], T[maxN];
double P[maxN];
bool vis[maxN];

double f(int ind) {
	if ( vis[ind] )
		return dp[ind];
	vis[ind] = true;
	dp[ind] = P[ind];

	FOR(i, 0, n) {
		if ( T[i] <= T[ind] )
			continue;

		if (  ((double)(T[i] - T[ind])) >= sqrt((X[i] - X[ind]) * (X[i] - X[ind]) + (Y[i] - Y[ind]) * (Y[i] - Y[ind]))  )
			dp[ind] = max(dp[ind], P[ind] + f(i));
	}
	return dp[ind];
}

int main() {
	ri(n);
	FOR(i, 0, n) {
		scanf("%lld %lld %lld %lF", X + i, Y + i, T + i, P + i);
	}
	double ans = 0;
	FOR(i, 0, n) {
		ans = max(ans, f(i));
	}
	printf("%.8lF\n",ans );

	return 0;
}