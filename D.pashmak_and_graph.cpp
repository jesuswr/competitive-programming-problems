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
const int maxN = 1e6; // CAMBIAR ESTE

// GJNM
int V, E;
vii EDGES[maxN];
int dp[maxN];

int main() {
	rii(V, E);
	FOR(i, 0, E) {
		int from, to, cost;
		riii(from, to, cost);
		from--, to--;
		EDGES[cost].pb({from, to});
	}

	FOR(i,1,maxN){
		map<int,int> aux_dp;
		for(auto e : EDGES[i]){
			if ( aux_dp.find(e.S) == aux_dp.end() )
				aux_dp[e.S] = 0;

			aux_dp[e.S] = max(aux_dp[e.S], dp[e.F] + 1);
		}
		for(auto p : aux_dp){
			dp[p.F] = max(dp[p.F], p.S);
		}
	}
	int ans = 0;
	FOR(i,0,V){
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}