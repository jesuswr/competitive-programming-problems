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
const int maxN = 110; // CAMBIAR ESTE

// GJNM
long double dp[maxN][maxN][maxN];
int r, s, p;




int main() {
	riii(r, s, p);

	long double rprob = 0, sprob = 0, pprob = 0;
	dp[r][s][p] = 1.0;

	ROF(ri, r, -1) {
		ROF(si, s, -1) {
			ROF(pi, p, -1) {
				long double RS = ri * si, SP = si * pi, RP = ri * pi;

				if ( RS > 0.5 ) {
					dp[ri][si - 1][pi] += (RS / (RS + SP + RP)) * dp[ri][si][pi];
				}
				if ( SP > 0.5) {
					dp[ri][si][pi - 1] += (SP / (RS + SP + RP)) * dp[ri][si][pi];
				}
				if ( RP > 0.5 ) {
					dp[ri - 1][si][pi] += (RP / (RS + SP + RP)) * dp[ri][si][pi];
				}
			}
		}
	}
	FOR(i, 1, 101) {
		rprob += dp[i][0][0];
		sprob += dp[0][i][0];
		pprob += dp[0][0][i];
	}
	printf("%.12Lf %.12Lf %.12Lf\n", rprob, sprob, pprob);

	return 0;
}