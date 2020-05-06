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
int n,b;
ll dp[70][70];

unsigned long long f(int n, int b){
	if ( n<=1 )
		return 1;
	if ( dp[n][b] != -1 )
		return dp[n][b];

	dp[n][b] = 1;
	FOR(i,1,b+1){
		dp[n][b] += f(n-i,b);
	}
	return dp[n][b];
}

int main(){
	int t = 1;
	while(scanf("%d %d", &n, &b) != EOF){
		if ( n > 61 || b > 60 )
			continue;
		memset(dp,-1,sizeof(dp));
		printf("Case %d: ", t++);
		printf("%llu\n",f(n,b) );
	}
	return 0;
}