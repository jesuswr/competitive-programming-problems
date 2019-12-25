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
const int maxN = 2e5+5; // CAMBIAR ESTE

// GJNM
ll n, t, a, b;
pair<ll,int> arr[maxN];

ll getmax( ll time , ll good , ll bad , ll rgood , ll rbad ){
	time -= good*a + bad*b;
	ll cnt = good + bad;
	if ( time < 0 ) return 0;
	if ( time > 0 ){
		ll aux = min(time/a,rgood);
		if ( aux > 0 ){
			time -= aux*a;
			cnt += aux;
		}
		if ( time > 0 ){
			ll aux = min(time/b,rbad);
			if ( aux > 0 ){
				time -= aux*b;
				cnt += aux;
			}
		}
	}
	return cnt;
}

int main(){

	int q;
	ri(q);
	while( q-- ){
		rll(n,t);
		rll(a,b);
		FOR(i,0,n) ri(arr[i].s);
		FOR(i,0,n) rl(arr[i].f);
		ll good = 0, bad = 0;
		FOR(i,0,n){
			if ( arr[i].s ) bad++;
			else good++;
		}
		ll ogood = 0, obad = 0;
		sort(arr,arr+n);
		ll ans = 0;
		FOR(i,0,n){
			ans = max( ans , getmax( arr[i].f-1 , ogood , obad , good - ogood , bad - obad ) );
			if ( arr[i].s ) obad++;
			else ogood++;
		}
		ans = max( ans , getmax( t , ogood , obad , good - ogood , bad - obad ) );
		printf("%lld\n", ans);
	}
	return 0;
}