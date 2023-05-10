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
vi G[MAXN];
multiset<int> MN[MAXN], ALL;

int ANS;

int get_mn(int i) {
	if (MN[i].empty()) 
		return 0;
	return 
		*MN[i].begin();
}

void pre(int u, int f = -1) {
	for(int v : G[u]) if (v != f) {
		pre(v, u);
		MN[u].insert(get_mn(v) + 1);
	}
	if (sz(MN[u]) > 1)
		ALL.insert( *(++MN[u].begin()) );

}


void go(int u, int f = -1) {
	int u_ans = min(*MN[u].begin() + 1, *ALL.begin());
	// cout << u + 1 << endl;
	// for(int x : MN[u]) cout << "    " << x << endl;
	// for(int x : ALL) cout << "        " << x << endl;
	ANS = max(ANS, u_ans);

	for(int v : G[u]) if (v != f) {

		if (sz(MN[u]) > 1) ALL.erase( ALL.find( *(++MN[u].begin()) ) );
		if (sz(MN[v]) > 1) ALL.erase( ALL.find( *(++MN[v].begin()) ) );
		MN[u].erase( MN[u].find( get_mn(v) + 1 ) );
		MN[v].insert(get_mn(u) + 1);
		if (sz(MN[u]) > 1) ALL.insert( *(++MN[u].begin()) );
		if (sz(MN[v]) > 1) ALL.insert( *(++MN[v].begin()) );

		go(v, u);	

		if (sz(MN[u]) > 1) ALL.erase( ALL.find( *(++MN[u].begin()) ) );
		if (sz(MN[v]) > 1) ALL.erase( ALL.find( *(++MN[v].begin()) ) );
		MN[v].erase( MN[v].find(get_mn(u) + 1) );
		MN[u].insert( (get_mn(v) + 1 ) );
		if (sz(MN[u]) > 1) ALL.insert( *(++MN[u].begin()) );
		if (sz(MN[v]) > 1) ALL.insert( *(++MN[v].begin()) );
	}
}


void solve() {
	ri(N);
	FOR(_,1,N) {
		int u, v; rii(u,v);
		--u, --v;
		G[u].pb(v);
		G[v].pb(u);
	}

	ALL.insert(INF);
	pre(0);
	ANS = -1;
	go(0);

	cout << ANS << endl;
	FOR(i,0,N) {
		G[i].clear();
		MN[i].clear();
	}
	ALL.clear();
}



int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
