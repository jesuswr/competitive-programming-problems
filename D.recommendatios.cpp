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
const int maxN = 2e5+5; // CAMBIAR ESTE

// GJNM
map< ll , priority_queue<ll> > mp; // pq of times, map of location
pair< ll , ll > A[maxN]; // first is time then is location
map< ll , ll > cnt; 
set< ll > not_used;


int main(){
	int n;
	ri(n);
	FOR(i,0,n){
		rl( A[i].S );
		cnt[ A[i].S ]++;
	}
	FOR(i,0,n)
		rl( A[i].F );

	FOR(i,0,n)
		mp[ A[i].S ].push({A[i].F});

	sort(A,A+n,greater< pair<ll,ll>>());

	ll owe = 0;
	for(auto it = cnt.begin(); it != cnt.end(); it++){
		auto it2 = it;
		it2++;
		ll low_bound = (*it).F;
		owe += (*it).S;

		ll up_bound = ( it2 != cnt.end() ? (*it2).F : LLINF);

		while( owe > 0 && low_bound < up_bound ){
			owe--;
			not_used.insert(low_bound++);
		}
	}

	ll ans = 0;

	FOR(i,0,n){
		auto it = not_used.lower_bound( A[i].S );
		ll aux = *it;
		ans += (aux-A[i].S)*A[i].F;

		not_used.erase(it);
		mp[aux].push(LLINF);
	}
	printf("%lld\n",ans );

	return 0;
}