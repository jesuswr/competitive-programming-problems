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
const int maxN = 20; // CAMBIAR ESTE

// GJNM
int n,m,x;
int cost[maxN];
int A[maxN][maxN];
int mxpos[maxN];
int dp[1<<12];

int f(int bitmask){
	if ( bitmask != (1<<12) && dp[bitmask] != -1 )
		return dp[bitmask];

	int mx[maxN];
	FOR(i,0,m)
		mx[i] = 0;

	FOR(i,0,n){
		if ( bitmask & (1<<i) ){
			FOR(j,0,m){
				mx[j] += A[i][j];
			}
		}
	}

	bool gotit = true;

	FOR(i,0,m){
		if ( mx[i] < x )
			gotit = false;
	}

	if ( gotit )
		return dp[bitmask] = 0;

	dp[bitmask] = INF;
	FOR(i,0,n){
		if ( bitmask & (1<<i) )
			continue;

		dp[bitmask] = min(dp[bitmask], cost[i] + f(bitmask | (1<<i)) );
	}
	return dp[bitmask];
}

int main(){
	riii(n,m,x);
	FOR(i,0,n){
		ri(cost[i]);
		FOR(j,0,m){
			ri(A[i][j]);
			mxpos[j] += A[i][j];
		}
	}
	FOR(i,0,m){
		if ( mxpos[i] < x ){
			printf("-1\n");
			return 0;
		}
	}
	memset(dp,-1,sizeof(dp));
	printf("%d\n",f(0) );
	return 0;
}