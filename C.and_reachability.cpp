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
const int maxN = 3e5 + 10; // CAMBIAR ESTE
const int maxBit = 19;

// GJNM
int dp[maxN][maxBit];
bool vis[maxN][maxBit];
vi hasBit[maxBit];
int a[maxN];
int n, q;

int f(int ind, int bit) {
	if ( ind == n )
		return INF;
	if ( vis[ind][bit] )
		return dp[ind][bit];
	vis[ind][bit] = true;

	int &ret = dp[ind][bit] = INF;

	if ( a[ind] & (1 << bit) )
		return ret = ind;


	FOR(b, 0, maxBit) {
		if ( a[ind] & (1 << b) ) {
			auto it = ub(hasBit[b].begin(), hasBit[b].end(), ind);
			if ( it != hasBit[b].end() ) {
				ret = min(ret, f(*it, bit));
			}
		}
	}
	return ret;
}

int main() {
	rii(n, q);
	FOR(i, 0, n) {
		ri(a[i]);
		FOR(b, 0, maxBit) {
			if ( a[i] & (1 << b) ) {
				hasBit[b].pb(i);
			}
		}
	}
	FOR(i, 0, q) {
		int x, y;
		rii(x, y);
		x--, y--;
		bool ans = false;
		FOR(b, 0, maxBit) {
			if ( ( a[y] & (1 << b) ) && f(x, b) <= y )
				ans = true;
		}
		printf("%s\n", (ans ? "Shi" : "Fou"));
	}

	return 0;
}