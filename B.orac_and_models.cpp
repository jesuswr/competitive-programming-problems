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
int n;
int A[maxN+10];
int dp[maxN+10];

int f(int ind){
	if ( dp[ind] != -1 )
		return dp[ind];

	int aux = 2;
	dp[ind] = 1;
	while( aux*ind <= n ){
		if ( A[ind] < A[aux*ind] )
			dp[ind] = max(dp[ind], 1 + f(aux*ind));
		aux++;
	}
	return dp[ind];
}

int main(){
	int t;
	ri(t);
	while( t-- ){
		ri(n);
		FOR(i,1,n+1){
			ri(A[i]);
			dp[i] = -1;
		}
		int ans = 0;
		FOR(i,1,n+1){
			ans = max(ans, f(i));
			//printf("%d : %d\n",i, f(i));
		}
		printf("%d\n", ans);
	}
	return 0;
}