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
char M[40][40];
int r,c;
ll dp[40][40];

ll f(int col, int blues){
	if ( dp[col][blues] != -1 )
		return dp[col][blues];

	ll &ret = dp[col][blues];
	ret = 0;
	FOR(i,0,blues)
		if ( M[i][col] == 'R' )
			return ret;
	FOR(i,blues,r)
		if ( M[i][col] == 'B' )
			return ret;

	if ( col == 0 )
		return ret = 1;
	FOR(i,blues,r+1)
		ret += f(col-1,i);
	return ret;
}

int main(){
	rii(r,c);
	FOR(i,0,r)
		scanf("%s", M[i]);
	memset(dp,-1,sizeof(dp));

	ll ans = 0;
	FOR(i,0,r+1)
		ans += f(c-1,i);

	printf("%lld\n", ans);
	return 0;
}