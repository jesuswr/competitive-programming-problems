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
const int maxN = 101; // CAMBIAR ESTE
const int MOD = 1000000;

// GJNM
int dp[maxN][maxN];

int f(int goal, int left){
	if ( goal==0 && left==0 )
		return 1;
	if ( left<0 )
		return 0;
	if ( dp[goal][left] != -1 )
		return dp[goal][left];

	int &ret = dp[goal][left];
	ret = 0;

	FOR(i,0,goal+1){
		ret += f(goal-i,left-1);
		ret = ret%MOD;
	}
	return ret;
}

int main(){
	int n,k;
	FOR(i,0,maxN) FOR(j,0,maxN)
		dp[i][j] = -1;

	while(rii(n,k), n||k){
		int ans = f(n,k);
		printf("%d\n", ans);
	}
	return 0;
}