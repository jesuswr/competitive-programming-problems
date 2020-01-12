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

pair<ll,ll> makeOrdPair( ll a , ll b ){
	if ( a >= b )
		return {a,b};
	return {b,a};
}

pair<ll,ll> minPLL( pair<ll,ll> p , pair<ll,ll> q){
	if ( p.f > q.f )
		return q;
	else
		return p;
}

int main()
{
	ll n;
	rl(n);
	pair<ll,ll> ans = {LLINF,LLINF};
	if ( n == 1 )
		ans = {1,1};
	for (ll i = 1; i*i < n; i++){
		if ( n%i == 0 && __gcd(i,n/i) == 1)
			ans = minPLL( ans , makeOrdPair( i , n/i ) );
	}
	printf("%lld %lld\n", ans.f, ans.s);
	return 0;
}