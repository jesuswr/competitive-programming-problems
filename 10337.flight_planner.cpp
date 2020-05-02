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
int x;
int A[10][1001], dp[10][1001];

int f(int h, int d){
	if ( d == x && h == 0 )
		return 0;
	if ( h<0 || h>9)
		return INF;
	if ( d == x )
		return INF;
	if ( dp[h][d] != -1 )
		return dp[h][d];

	int &ret = dp[h][d];
	ret = -A[h][d];

	ret += min(
				f(h+1,d+1) + 60, // up
				min(
					f(h,d+1) + 30, // same
					f(h-1,d+1) +20 // down
				   )
			  );
	return ret;

}

int main(){
	int t;
	ri(t);
	while(t--){
		ri(x);
		x /= 100;

		ROF(i,9,-1)
			FOR(j,0,x){
				ri(A[i][j]);
				dp[i][j] = -1;
			}


		
		printf("%d\n\n", f(0,0));
		
	}
	return 0;
}