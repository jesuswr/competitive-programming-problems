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

// GJNM
int n;
int XG[13], YG[13], XB[13], YB[13];
int dp[1 << 13][13];

bool can_pass(pii a, pii b, pii c) {
	int x1 = a.F, y1 = a.S;
	int x2 = b.F, y2 = b.S;
	int x3 = c.F, y3 = c.S;
	int ans = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
	if ( ans != 0 )
		return true;
	if ( min(x1, x2) <= x3 && x3 <= max(x1, x2) && min(y1, y2) <= y3 && y3 <= max(y1, y2) )
		return false;
	return true;
}

int f(int btmsk, int ind) {
	if ( ind == n - 1 )
		return 0;
	if ( dp[btmsk][ind] != 0 )
		return dp[btmsk][ind];

	int &ret = dp[btmsk][ind] = INF;
	FOR(i, 0, n) {
		if ( btmsk & (1 << i) )
			continue;
		bool pass = true;
		FOR(j, 0, n) {
			if ( !can_pass({XG[ind], YG[ind]}, {XG[i], YG[i]}, {XB[j], YB[j]}))
				pass = false;
			if ( j != ind && j != i ){
				if ( !can_pass({XG[ind], YG[ind]}, {XG[i], YG[i]}, {XG[j], YG[j]}) )
					pass = false;
			}
		}
		if ( pass ) {
			ret = min(ret, 1 + f(btmsk | (1 << i), i));
		}
	}
	return ret;
}

int main() {
	ri(n);
	FOR(i, 0, n) {
		rii(XG[i], YG[i]);
	}
	FOR(i, 0, n) {
		rii(XB[i], YB[i]);
	}

	int ans = f(1, 0);
	printf("%d\n", (ans >= 69 ? -1 : ans));
	return 0;
}