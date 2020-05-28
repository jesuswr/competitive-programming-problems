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
ll h,c,t;

ll calc(ll x){
	return x*h + x*c +h;
}


int main(){
	int w;
	ri(w);
	while(w--){
		rll(h,c), rl(t);


		ll l=0,r=1e9;
		while(l<=r){
			ll m=(l+r)/2;
			ll n=m;
			ll num=(n+1)*h+n*c;
			ll den=2*n+1;
			if(num>=t*den) l=m+1;
			else r=m-1;
		}
		
		int ans = 2;
		long double hh = h, cc = c, tt = t;
		long double aux = (hh+cc)/2;

		FOR(i,max(0LL, l-10), l + 10){

			if ( abs( (hh*(i+1) + cc*(i)) / (2*i+1) - t) < abs(aux - t) ){
				aux = (hh*(i+1) + cc*(i)) / (2*i+1);
				ans = 2*i+1;
			}
		}

		
		printf("%d\n", ans);
	}
	return 0;
}