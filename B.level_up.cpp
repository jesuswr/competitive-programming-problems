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
typedef pair<ll, ll> pll;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%lld %lld %lld", &a, &b, &c)
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
const int maxN = 600; // CAMBIAR ESTE

// GJNM
ll n, s1, s2;
pair<pll, pll> q[maxN];
ll dp_prev[maxN][maxN], dp[maxN][maxN];

int main() { // B
	riii(n, s1, s2);
	FOR(i, 0, n) {
		rll(q[i].F.F, q[i].F.S), rll(q[i].S.F, q[i].S.S);
	}
	sort(q, q + n);
	FOR(i, 0, s1 + 1) {
		FOR(j, 0, s2 + 1) {
			dp[i][j] = LLINF;
		}
	}
	dp[0][0] = 0;

	FOR(k, 0, n) {
		FOR(i, 0, s1 + 1) {
			FOR(j, 0, s2 + 1) {
				dp_prev[i][j] = dp[i][j];
			}
		}

		FOR(i, 0, s1 + 1) {
			FOR(j, 0, s2 + 1) {
				if ( dp_prev[i][j] == LLINF )
					continue;
				//printf("%d %d %d\n", i, j, k );
				//printf("%lld %lld %lld %lld\n", q[k].F.F, q[k].F.S, q[k].S.F, q[k].S.S);
				if ( i + q[k].F.F > s1 && i != s1 ) {
					//printf("if1\n");
					dp[s1][min(s2, j + i + q[k].F.F - s1)] = min(dp[s1][min(s2, j + i + q[k].F.F - s1)], dp_prev[i][j] + q[k].F.S);
				}
				else if ( i != s1 ) {
					//printf("if2\n");
					dp[i + q[k].F.F][j] = min(dp[i + q[k].F.F][j], dp_prev[i][j] + q[k].F.S);
				}

				dp[i][min(s2, j + q[k].S.F)] = min(dp[i][min(s2, j + q[k].S.F)], dp_prev[i][j] + q[k].S.S);
			}
		}
	}
	//printf("\n\n");
	//FOR(i, 0, s1 + 1) {
	//	FOR(j, 0, s2 + 1) {
	//		if ( dp[i][j] != LLINF)
	//			printf("%d %d: %lld\n", i, j, dp[i][j]);
	//	}
	//}

	printf("%lld\n", (dp[s1][s2] == LLINF ? -1ll : dp[s1][s2]));



	return 0;
}