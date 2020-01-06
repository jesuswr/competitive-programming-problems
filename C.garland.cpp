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
int dp[101][101][101][2];
int arr[101];
int n;


int f( int ind , int odd , int even , int prev ){
	if ( odd < 0 || even < 0 )
		return INF;

	if ( ind == n )
		return 0;

	if ( dp[ind][odd][even][prev] != -1)
		return dp[ind][odd][even][prev];

	int ans = INF;
	if ( arr[ind] != 0 ){
		if ( arr[ind] & 1 )
			ans = min( ans , f(ind+1,odd-1,even,1) + ( prev == 0 ? 1 : 0) );
		else
			ans = min( ans , f(ind+1,odd,even-1,0) + ( prev == 1 ? 1 : 0) );

	}
	else{
		ans = min( ans , f(ind+1,odd,even-1,0) + ( prev == 1 ? 1 : 0) );
		ans = min( ans , f(ind+1,odd-1,even,1) + ( prev == 0 ? 1 : 0) );
	}

	return dp[ind][odd][even][prev] = ans;
	
}

int main()
{
	FOR(i,0,101)
		FOR(j,0,101)
			FOR(k,0,101)
				FOR(l,0,2)
					dp[i][j][k][l] = -1;

	ri(n);
	int odd, even;
	odd = even = n/2;
	if (n&1)
		odd++;

	FOR(i,0,n){
		ri( arr[i] );
		if ( arr[i] == 0 ) 
			continue;

		
	}

	if ( arr[0] == 0)
		printf("%d\n", min( f(1,odd-1,even,1) , f(1,odd,even-1,0) ) );
	else if ( arr[0] & 1 )
		printf("%d\n", f(1,odd-1,even,1) );
	else
		printf("%d\n",f(1,odd,even-1,0)  );


	return 0;
}