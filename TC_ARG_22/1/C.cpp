#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dasdas;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dasdas=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dasdas=scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


int N;
int X[MAXN], Y[MAXN], Z[MAXN];
int ans = 0;
ii inds;
map<ii, ii> MP;


void try_upd(int i) {
	if ( min( {X[i], Y[i], Z[i] + MP[ {X[i], Y[i]}].F } ) > ans ){
		ans = min( {X[i], Y[i], Z[i] + MP[ {X[i], Y[i]}].F } );
		inds = {i, MP[ {X[i], Y[i]}].S };
	}
	if ( min( {X[i], Z[i], Y[i] + MP[ {X[i], Z[i]}].F } ) > ans ){
		ans = min( {X[i], Z[i], Y[i] + MP[ {X[i], Z[i]}].F } );
		inds = {i, MP[ {X[i], Z[i]}].S };
	}
	if ( min( {Y[i], Z[i], X[i] + MP[ {Y[i], Z[i]}].F } ) > ans ){
		ans = min( {Y[i], Z[i], X[i] + MP[ {Y[i], Z[i]}].F } );
		inds = {i, MP[ {Y[i], Z[i]}].S };
	}
}


int main(){
	ri(N);
	FOR(i,0,N){
		rii(X[i], Y[i]), ri(Z[i]);
	}


	FOR(i,0,N) {
		if ( min({X[i], Y[i], Z[i]}) > ans ) {
			ans = min({X[i], Y[i], Z[i]});
			inds = {i, -1};
		}
	
		try_upd(i);	
	
		MP[ {X[i], Y[i]} ] = max(MP[ {X[i], Y[i]} ], {Z[i], i});
		MP[ {X[i], Z[i]} ] = max(MP[ {X[i], Z[i]} ], {Y[i], i});
		MP[ {Y[i], X[i]} ] = max(MP[ {Y[i], X[i]} ], {Z[i], i});
		MP[ {Y[i], Z[i]} ] = max(MP[ {Y[i], Z[i]} ], {X[i], i});
		MP[ {Z[i], X[i]} ] = max(MP[ {Z[i], X[i]} ], {Y[i], i});
		MP[ {Z[i], Y[i]} ] = max(MP[ {Z[i], Y[i]} ], {X[i], i});
	}

	if (inds.S != -1) cout << 2 << endl;
	else cout << 1 << endl;
	if (inds.S != -1) cout << inds.F + 1 << " " << inds.S + 1<< endl;
	else cout << inds.F + 1 << endl;

	return 0;
}
