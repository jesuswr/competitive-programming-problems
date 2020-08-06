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
#define riiii(a,b,c,d) rii(a,b),rii(c,d)
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
const int maxN = 12; // CAMBIAR ESTE

// GJNM
int HAVE[maxN], NEED[maxN], NEED_N[maxN], VALUE[maxN];
int n, m;

int dp[maxN][1010];
bool vis[maxN][1010];

int f(int ind, int n) {
	if ( ind == m || n == 0 )
		return 0;
	if ( vis[ind][n] )
		return dp[ind][n];
	vis[ind][n] = true;

	int &ret = dp[ind][n] = -1;
	int aux = 0;
	while ( aux * NEED[ind] <= HAVE[ind] && aux * NEED_N[ind] <= n ) {
		ret = max(ret, aux * VALUE[ind] + f(ind + 1, n - aux * NEED_N[ind]));
		aux++;
	}

	return ret;
}

int main() {
	rii(n, m), rii(NEED_N[0], VALUE[0]);
	m++;
	FOR(i, 1, m) {
		riiii(HAVE[i], NEED[i], NEED_N[i], VALUE[i]);
	}

	printf("%d\n", f(0, n));

	return 0;
}