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
ll l;
ll c[40];

ll f(ll curr_l){
	if ( curr_l <= 0 )
		return 0;
	ll ans;
	ROF(i,31,-1){
		if ( (1<<i) & curr_l ){
			ans = c[i] + f( curr_l - (1LL<<i) );
			FOR(j,i+1,32){
				ans = min(ans,c[j]);
			}
			break;
		}
	}
	return ans;
}


int main(){
	ri(n);
	rl(l);
	FOR(i,0,32)
		c[i] = LLINF;
	FOR(i,0,n)
		rl(c[i]);
	FOR(i,0,n)
		FOR(j,i+1,32)
			c[j] = min(c[j], c[i]*(1LL<<(j-i)));
		
	printf("%lld\n", f(l));
	

	return 0;
}