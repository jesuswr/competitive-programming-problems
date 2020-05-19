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
ll pre[3000000];

int look_max(int l, int h, int goal, int low_lim, int high_lim){
	int ans = -1;
	while( l <= h ){
		int m = (l+h)/2;
		if ( goal - m < low_lim ){
			h = m - 1;
		}
		else if ( goal - m > high_lim ){
			l = m + 1;
		}
		else{
			l = m + 1;
			ans = max(ans, m);
		}
	}
	return ans;
}

int look_min(int l, int h, int goal, int low_lim, int high_lim){
	int ans = INF;
	while( l <= h ){
		int m = (l+h)/2;
		if ( goal - m < low_lim ){
			h = m - 1;
		}
		else if ( goal - m > high_lim ){
			l = m + 1;
		}
		else{
			h = m - 1;
			ans = min(ans, m);
		}
	}
	return ans;
}


int main(){
	int a,b,c,d;
	rii(a,b), rii(c,d);
	
	ll ans = 0;
	FOR(i,1,2e6){
		ll l = look_min(a,b,i,b,c);
		ll h = look_max(a,b,i,b,c);
		if ( h == -1 || l == INF )
			continue;
		pre[i] = h-l+1;
	}
	ROF(i,2e6,-1){
		pre[i] += pre[i+1];
	}
	FOR(i,c,d+1){
		ans += pre[i+1];
	}
	printf("%lld\n", ans);
	return 0;
}