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
int n, money;
int sz[21];
int prices[21][21];
int dp[21][201];

int f(int ind, int coins){
	if ( ind >= n && coins >= 0 )
		return 0;
	if ( coins < 0 )
		return -1000000;

	if ( dp[ind][coins] != -100000 )
		return dp[ind][coins];

	FOR(i,0,sz[ind])
		dp[ind][coins] = max(dp[ind][coins], f(ind+1, coins-prices[ind][i]) + prices[ind][i] );
	
	//printf("%d %d %d\n", ind, coins, dp[ind][coins]);
	return dp[ind][coins];
}


int main(){
	int t;
	ri(t);
	while(t--){
		rii(money,n);
		FOR(i,0,n){
			ri(sz[i]);
			FOR(j,0,sz[i])
				ri(prices[i][j]);
		}
		FOR(i,0,n+1)
			FOR(j,0,money+1)
				dp[i][j] = -100000;
		
		int ans = f(0,money);

		if ( ans < 0 )
			printf("no solution\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}