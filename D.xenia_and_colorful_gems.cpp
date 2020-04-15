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
const int maxN = 2e5; // CAMBIAR ESTE

// GJNM
ll ans;

void solve(vector<ll> &v1, vector<ll> &v2, vector<ll> &v3){
	for(ll x : v1){
		auto y = lower_bound(v2.begin(),v2.end(),x);
		auto z = lower_bound(v3.begin(),v3.end(),x);
		if ( y == v2.end() ){
			y--;
		}
		if ( z == v3.end() ){
			z--;
		}
		ans = min( ans , (x - (*y))*(x - (*y)) + (x - (*z))*(x - (*z)) + ((*z) - (*y))*((*z) - (*y))  );
		if ( y != v2.begin() ){
			y--;
			ans = min( ans , (x - (*y))*(x - (*y)) + (x - (*z))*(x - (*z)) + ((*z) - (*y))*((*z) - (*y))  );
			y++;
		}
		if ( z != v3.begin() ){
			z--;
			ans = min( ans , (x - (*y))*(x - (*y)) + (x - (*z))*(x - (*z)) + ((*z) - (*y))*((*z) - (*y))  );
			z++;
		}
		if ( z != v3.begin() && y != v2.begin() ){
			z--;
			y--;
			ans = min( ans , (x - (*y))*(x - (*y)) + (x - (*z))*(x - (*z)) + ((*z) - (*y))*((*z) - (*y))  );
		}

	}
}


int main(){
	int r,g,b;
	int n;
	ri(n);
	while(n--){

	riii(r,g,b);
	vector<ll> red(r), green(g), blue(b);
	FOR(i,0,r)
		rl(red[i]);
	FOR(i,0,g)
		rl(green[i]);
	FOR(i,0,b)
		rl(blue[i]);
	sort(red.begin(),red.end());
	sort(green.begin(),green.end());
	sort(blue.begin(),blue.end());
	ans = 9e18;

	solve(red,green,blue);
	solve(green,red,blue);
	solve(blue,green,red);

	printf("%lld\n", ans);

	}
	return 0;
}