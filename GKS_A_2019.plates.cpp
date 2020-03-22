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
int n, k, p;
int st[60][40];
int dp[60][2000];

int f( int ind , int left ){ // dp what stack am i on and how many plates i still need
	if ( ind == n && left > 0 )
		return -INF;
	if ( ind == n )
		return 0;
	if ( dp[ind][left] != -1)
		return dp[ind][left];

	int n = min(left,k);
	int ans = f(ind+1,left);
	int cnt = 0;
	FOR(i,0,n){
		cnt += st[ind][i];
		ans = max(ans, cnt + f(ind+1,left-i-1));
	}
	return dp[ind][left] = ans;
}

int main(){
	int t = 1;
	int t2;
	ri(t2);
	while(t<=t2){
		riii(n,k,p);
		FOR(i,0,n){
			FOR(j,0,k){
				ri(st[i][j]);
			}
			FOR(j,0,p+10){
				dp[i][j] = -1;
			}
		}
		int ans = f(0,p);
		printf("Case #%d: %d\n",t, ans );
		t++;
	}
	return 0;
}