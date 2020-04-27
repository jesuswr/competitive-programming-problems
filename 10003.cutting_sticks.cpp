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
const int maxN = 1e3 +10; // CAMBIAR ESTE

// GJNM
int arr[51];
int dp[maxN][maxN];
int l,n;

int f(int left, int right){
	if ( dp[left][right] != -1 )
		return dp[left][right];

	int &ret = dp[left][right];
	ret = INF;
	bool div = false;
	auto it = ub(arr,arr+n,left); // here we look for a cut point at the right of left

	while( it<arr+n && *it<right ){ // here we move on cut points that are right of left 
		div = true;
		ret = min(ret, f(left,*it) + f(*it,right) + right-left); // cut there and save min
		it++;
	}

	if (!div)
		ret = 0;
	return ret;
}

int main(){
	while(ri(l), l!=0){
		ri(n);
		FOR(i,0,n)
			ri(arr[i]);

		FOR(i,0,l+1)
			FOR(j,0,l+1)
				dp[i][j] = -1;

		int ans = f(0,l);
		printf("The minimum cutting is %d.\n", ans);
	}
	return 0;
}