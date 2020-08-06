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
const int maxN = 1e5; // CAMBIAR ESTE
const int MOD = 100000000;

// GJNM
int N1, N2, K1, K2;
int dp[110][110][20][20];
bool vis[110][110][20][20];

int f(int fm, int hm, int fmax, int hmax) {
	if ( fm < 0 || hm < 0 || fmax > K1 || hmax > K2 )
		return 0;
	if ( fm == 0 && hm == 0 )
		return 1;
	if ( vis[fm][hm][fmax][hmax] )
		return dp[fm][hm][fmax][hmax];
	vis[fm][hm][fmax][hmax] = true;

	int &ret = dp[fm][hm][fmax][hmax];
	return ret = (f(fm - 1, hm, fmax + 1, 0) + f(fm, hm - 1, 0, hmax + 1)) % MOD;
}

int main() {
	rii(N1, N2), rii(K1, K2);

	printf("%d\n", f(N1, N2, 0, 0));

	return 0;
}