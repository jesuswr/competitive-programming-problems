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
int n,m;

ll to_ll(string &s){
	reverse(s.begin(), s.end());
	ll ret = 0;
	FOR(i,0,s.size())
		if ( s[i] == '1' )
			ret |= (1LL<<i);
	return ret;
}

void prnt_ans(ll x){
	ROF(i,m-1,-1){
		printf("%d", (x & (1LL<<i)) > 0);
	}
	printf("\n");
}

int main(){
	int t;
	ri(t);
	while (t--){
		rii(n,m);

		vector< ll > A;

		FOR(i,0,n){
			string s;
			cin >> s;
			A.pb( to_ll(s) );
		}

		ll mid = ((1LL<<m)-n-1)/2;
		ll l = 0, r = (1LL<<m)-1;
		while ( l <= r ){
			ll m = (l+r)/2;
			ll aux_m = m;
			for(ll x : A)
				if ( m > x )
					aux_m--;

			if ( aux_m <= mid )
				l = m+1;
			else
				r = m-1;
		}
		prnt_ans(r);

	}
	return 0;
}