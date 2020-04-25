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
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;
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
#define f first
#define s second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
int n;
int costs[12][12];
int dp[1<<12][11];

int f(int bitmask, int ind){
	if ( bitmask == (1<<n)-1 )
		return costs[ind][0];
	if ( dp[bitmask][ind] != -1 )
		return dp[bitmask][ind];

	int &ret = dp[bitmask][ind];
	ret = INF;

	FOR(i,1,n){
		if ( bitmask & (1<<n) )
			continue;

		ret = min(ret, f(bitmask | (1<<i), i) + costs[ind][i] );
	}
	return ret;

}

void solve(){
	ri(n);
	n++;
	FOR(i,0,n)
		FOR(j,0,n)
			if ( i!=j )
				ri(costs[i][j]);
	FOR(i,0,1<<n)
		FOR(j,0,n)
			dp[i][j] = -1;

	int ans = f(1,0);
	printf("%d\n", ans);
}


int main(){
	int t;
	ri(t);
	while(t--){
		solve();
	}
	return 0;
}