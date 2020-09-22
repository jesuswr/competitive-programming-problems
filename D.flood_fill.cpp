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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int n;
vi cols;
int dp[5010][5010];
bool vis[5010][5010];

int f(int l, int r) {
	if (l == r)
		return 0;
	if (vis[l][r])
		return dp[l][r];
	vis[l][r] = true;
	if (cols[l] == cols[r])
		dp[l][r] = 1 + f(l + 1, r - 1);
	else
		dp[l][r] = 1 + min(f(l + 1, r), f(l, r - 1));

	return dp[l][r];
}


int main() {
	ri(n);
	FOR(i, 0, n) {
		int aux;
		ri(aux);
		if (cols.size() == 0 || cols[cols.size() - 1] != aux)
			cols.pb(aux);
	}
	n = cols.size();
	printf("%d\n", f(0, n - 1) );

	return 0;
}