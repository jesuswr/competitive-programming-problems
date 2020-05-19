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
ll minmax(ll x){
	ll mn = 20;
	ll mx = 0;
	while( x > 0 ){
		mn = min(mn, x%10);
		mx = max(mx, x%10);
		x = x/10;
	}
	return mn*mx;
}

int main(){
	int t;
	ri(t);
	while(t--){
		ll a,k;
		rll(a,k);
		ll i = 1;
		while( i < k ){
			ll aux = a + minmax(a);
			if ( aux == a )
				break;
			a = aux;
			i++;
		}
		printf("%lld\n", a);
	}
	return 0;
}