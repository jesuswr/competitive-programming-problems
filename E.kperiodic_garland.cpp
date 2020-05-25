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
const int maxN = 1e6+69; // CAMBIAR ESTE

// GJNM
int n,k;
int CNT[maxN], A[maxN];
int dp[maxN][2]; // index - on or off

int f(int ind, int on){
	if ( ind >= n )
		return 0;
	if ( dp[ind][on] != -1 )
		return dp[ind][on];

	int &ret = dp[ind][on];
	ret = INF;

	if ( on ){
		ret = min(ret, CNT[n-1] - CNT[ind] ); // turn all off
		ret = min(ret, ( ind+k-1 <= n-1 ? CNT[ind+k-1] : CNT[n-1] ) - CNT[ind] + f(ind+k, on) ); // turn on the next one
		ret += 1 - A[ind];
	}
	else{
		ret = min(ret, f(ind+1, 0));
		ret = min(ret, f(ind+1, 1));
		ret += A[ind];
	}
	return ret;
}

int main(){
	int t;
	ri(t);
	while (t--){
		rii(n,k);
		FOR(i,0,n){
			dp[i][0] = dp[i][1] = -1;
			scanf("%1d", &CNT[i]);
			A[i] = CNT[i];
		}

		FOR(i,1,n)
			CNT[i] += CNT[i-1];
		
		printf("%d\n", min(f(0,0), f(0,1)) );


	}
	return 0;
}