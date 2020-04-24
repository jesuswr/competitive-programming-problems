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
int arr[maxN];
int dp[maxN];

int f(int ind){
	if ( ind == 0 )
		return 1;

	if ( dp[ind] != 0 )
		return dp[ind];

	dp[ind] = 1;
	ROF(i,ind-1,-1){
		if ( arr[i] >= arr[ind] )
			continue;

		dp[ind] = max(dp[ind], f(i)+1);
	}
	return dp[ind];
}

int main(){
	int t;
	ri(t);
	while(t--){
		int n;
		ri(n);
		FOR(i,0,n){
			dp[i] = 0;
			ri(arr[i]);
		}

		int ans = -1;
		ROF(i,n-1,-1)
			ans = max(ans, f(i));
		printf("%d\n", ans);
	}
	return 0;
}