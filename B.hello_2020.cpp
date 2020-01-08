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
vi maxs;
vi mins;

int main()
{
	int n;
	ri(n);
	ll ans = 0;
	FOR(i,0,n){
		int l;
		ri(l);
		int mn = INF, mx = -1;
		bool asc = false;
		FOR(j,0,l){
			int aux;
			ri(aux);
			if ( aux > mn )
				asc = true;
			mn = min( mn , aux );
			mx = max( mx , aux );
		}
		if ( !asc ){
			mins.pb(mn);
			maxs.pb(mx);
		}
		else
			ans += n;
	}
	/*for( auto x : mins )
		printf("%d ",x );
	printf("\n");
	for( auto x : maxs )
		printf("%d ",x );
	printf("\n");*/

	sort(maxs.begin(),maxs.end());
	/*for( auto x : maxs )
		printf("%d ",x );
	printf("\n");*/
	for( auto x : mins ){
		auto y = upper_bound( maxs.begin() , maxs.end() , x );
		//printf("%d %d %d\n", x,*y,(int)( y - maxs.begin() ));
		ll aux = (ll)( y - maxs.begin() );
		ans += n-aux;
	}
	printf("%lld\n", ans);
	return 0;
}