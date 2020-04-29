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
const int maxN = 103; // CAMBIAR ESTE

// GJNM
ll arr[maxN];
ll dp[maxN][maxN];
bool vis[maxN][maxN];

ll f(int i, int n){
	if ( n == 0 )
		return 1;

	if ( vis[i][n] )
		return dp[i][n];
	
	vis[i][n] = true;

	return dp[i][n] = arr[i]*f(i+1,n-1);

}

int main(){
	while (scanf("%lld",arr) != EOF){
		int n = 1;
		while(rl(arr[n]), arr[n]!=-999999 )
			n++;

		FOR(i,0,n+1)
			FOR(j,0,n+1)
				vis[i][j] = false;
		ll ans = arr[0];
		FOR(len,1,n+1)
			FOR(start,0,n-len+1)
				ans = max(ans, f(start,len));
			
		printf("%lld\n",ans );
		
	}
	return 0;
}