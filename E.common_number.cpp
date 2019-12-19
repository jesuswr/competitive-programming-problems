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

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 5005; // CAMBIAR ESTE
ll n, k;

// GJNM
bool checkO( ll x ){
	ll curr = 1;
	ll cnt = 0;
	while (curr*x <= n){
		cnt += min( n - curr*x +1 , curr );
		curr = curr*2;
	}
	if ( cnt >= k ) return true;
	return false;
}

bool checkE( ll x ){
	ll curr = 1;
	ll cnt = 0;
	while (curr*x <= n){
		cnt += min( n - curr*x +1 , 2*curr );
		curr = curr*2;
	}
	if ( cnt >= k ) return true;
	return false;
}

int main()
{	
	ll oddMax, evenMax;
	rll(n,k);
	oddMax = n/2 + ( n%2 & 1 ? 1 : 0 );
	evenMax = n/2;

	ll s = 0, m;
	ll ans, ans1;
	ans = ans1 = 1;
	while ( s <= oddMax ){
		m = ( oddMax + s ) / 2;
		if ( checkO( 2*m+1 ) ) {
			s = m+1;
			ans = 2*m+1;
		}
		else oddMax = m-1;
	}
	ll s1 = 1, m1;
	while ( s1 <= evenMax ){

		m1 = ( evenMax + s1 ) / 2;
		if ( checkE( 2*m1 ) ) {
			s1 = m1+1;
			ans1 = 2*m1;
		}
		else evenMax = m1-1;
	}
	printf("%lld\n", max(ans,ans1));
	return 0;
}