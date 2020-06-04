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
ll check(ll a, ll i){
	if ( a & (1LL<<i) ){
		a = a >> (i+1);
		return a + 1;
	}
	else{
		a -= (1LL<<i);
		if ( a < (1LL<<i) )
			return 0;
		a = a >> (i+1);
		return a + 1;
	}
}

int main(){
	int t;
	ri(t);
	while(t--){
		ll a;
		rl(a);
		ll ans = 0;
		FOR(i,0,64){
			if ( (1LL << i) > a )
				break;
			ans += check(a, i)*(i+1);
		}
		printf("%lld\n",ans );
	}
	return 0;
}