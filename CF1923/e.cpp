#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int das;
#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) das=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) das=scanf("%lld", &a)
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
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
int COL[MAXN];
vi G[MAXN];
map<int,int> CNT[MAXN];
ll ANS;

void f(int u, int ft = -1) {
	int big = -1;
	FOR(i,0,sz(G[u])) {
		int v = G[u][i];
		if (v == ft) continue;

		f(v,u);

		if (big == -1) big = v;
		else if (sz(CNT[v]) > sz(CNT[big])) big = v;
	}

	if (big != -1) {
		swap(CNT[u], CNT[big]);
	}

	for(int v : G[u]) if (v != ft && v != big) {
		for(auto &[col, cnt] : CNT[v]) {
			if (col != COL[u]) ANS += 1ll * cnt * CNT[u][col];
			CNT[u][col] += cnt;
		}
	}
	ANS += CNT[u][COL[u]];
	CNT[u][COL[u]] = 1;
}

void solve() {
	ri(N);
	FOR(i,0,N) ri(COL[i]);
	FOR(i,1,N) {
		int u,v; rii(u,v); --v;--u;
		G[u].pb(v);
		G[v].pb(u);
	}

	ANS = 0;
	f(0);
	cout << ANS << endl;

	FOR(i,0,N) G[i].clear();
	FOR(i,0,N) CNT[i].clear();

}


int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
