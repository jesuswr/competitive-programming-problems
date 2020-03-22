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

int main(){
	int t;
	ri(t);
	while(t--){
		ll n, g, b;
		rll(n,g);
		rl(b);
		if ( g >= b )
			printf("%lld\n", n);
		else{
			ll ans;
			ll min_good = (n+1)/2;
			ll need = min_good/g;
			if ( min_good%g ){
				ans = need*(g+b) + min_good%g;
			}
			else{
				ans = need*(g+b) - b;
			}
			ans = max(ans,n);
			//printf("%lld %lld %lld \n", ans, min_good, need);
			printf("%lld\n", ans);
		}
	}
	return 0;
}