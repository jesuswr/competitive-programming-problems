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
int n;
pair<ll, ll> M[maxN];
ll dp[maxN][maxN];
bool vis[maxN][maxN];

ll f(int ind, int last) {
	if ( ind == n )
		return 0;
	if ( vis[ind][last] )
		return dp[ind][last];
	vis[ind][last] = true;

	return dp[ind][last] = min(M[ind].S + f(ind + 1, ind), (M[ind].F - M[last].F) + f(ind + 1, last));
}



int main() {
	ri(n);
	FOR(i, 0, n) {
		rll(M[i].F, M[i].S);
	}
	sort(M, M + n);
	printf("%lld\n", M[0].S + f(1, 0) );

	return 0;
}