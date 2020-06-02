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
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
ll dp[30][200];
int n,x;

ll f(int ind, int sum){
	if ( ind == n && sum >= x)
		return 1;
	if ( ind == n )
		return 0;
	if ( dp[ind][sum] != -1 )
		return dp[ind][sum];

	dp[ind][sum] = 0;
	FOR(i,0,6)
		dp[ind][sum] += f(ind+1, sum+i+1);
	return dp[ind][sum];
}

int main(){
	while(rii(n,x), n != 0 ){
		FOR(i,0,n+1)
			FOR(j,0,6*n+1)
				dp[i][j] = -1;

		ll ans = f(0,0);
		ll div = 1;
		FOR(i,0,n)
			div *= 6;
		ll g = __gcd(ans, div);
		if ( ans == div )
			printf("1\n");
		else if ( ans == 0 )
			printf("0\n");
		else	
			printf("%lld/%lld\n",ans/g, div/g );
	}
	return 0;
}