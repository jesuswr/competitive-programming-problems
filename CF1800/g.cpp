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
map<vi, int> HASH;
vi G[MAXN];

pair<int, bool> go(int u, int f = -1) {
	vector<pair<int, bool>> hshs;
	for(int v : G[u])  if (v != f)
		hshs.pb(go(v, u));
	sort(all(hshs));

	bool ANS = 1;
	bool o = sz(hshs) & 1;
	for(int i = 0; i < sz(hshs); ++i) {
		if (i + 1 < sz(hshs)) {
			if (hshs[i+1].F != hshs[i].F && o && hshs[i].S) o = false;
			else if (hshs[i+1].F == hshs[i].F) ++i;
			else ANS = false;
		}
		else {
			if (o && hshs[i].S) o = false;
			else ANS = false;
		}
	}

	vector<int> h;
	FOR(i,0,sz(hshs)) h.pb(hshs[i].F);
	if (HASH.find(h) == HASH.end()) HASH[h] = sz(HASH) + 1;
	return {HASH[h], ANS};
}


void solve() {
	ri(N);
	FOR(i,0,N) G[i].clear();
	HASH.clear();
	FOR(_,1,N) {
		int a, b; rii(a,b); --a; --b;
		G[a].pb(b);
		G[b].pb(a);
	}
	bool ANS = go(0).S;
	if (ANS) cout << "yes" << endl;
	else cout << "no" << endl;
}




int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
