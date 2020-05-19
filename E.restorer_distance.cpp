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
ll n,a,r,m;
ll H[maxN];

ll h_cost(ll h){
	ll low, high;
	low = high = 0;
	ll ret = 0;

	FOR(i,0,n){
		if ( H[i] > h ){
			high += H[i] - h;
		}
		else if ( H[i] < h ){
			low += h - H[i];
		}
	}

	if ( low > 0 && high > 0 ){
		ll mn = min(low,high);
		ret += min( (a+r)*mn, m*mn );
		low -= mn;
		high -= mn;
	}

	if ( low > 0 )
		ret += low*a;

	if ( high > 0 )
		ret += high*r;

	return ret;
}

int main(){
	rll(n,a), rll(r,m);
	FOR(i,0,n){
		rl(H[i]);
	}
	ll ans1 = LLINF;
	ll low = 0, high = 1e9;

	//FOR(i,low,high+1){
	//	printf("%d -> %lld\n", i, h_cost(i));
	//}
	while( low <= high ){
		ll mid = (low + high)/2;
		if ( h_cost(mid) > h_cost(mid+1) ){
			low = mid + 1;
			ans1 = min(ans1, h_cost(mid+1) );
		}
		else{
			high = mid-1;
			ans1 = min(ans1, h_cost(mid));
		}
	}

	printf("%lld\n", ans1);

	return 0;
}