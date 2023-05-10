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

int N, Q;
vi G[MAXN];
map<int,int> CNT[MAXN]; 
bool IN_CYCLE[MAXN];
int CYC_SIZE;

map<int,int> EDGE_COL[MAXN];
map<int,int> CYCLE_COL_CNT;

bool VIS[MAXN];
int P[MAXN];
void dfs(int u = 0, int f = -69) {
	VIS[u] = 1;
	for(int v : G[u]) {
		if (v == f) 
			continue;

		if (!VIS[v]) {
			P[v] = u;
			dfs(v,u);
		}
		else if (!IN_CYCLE[u]) {
			IN_CYCLE[u] = 1;
			CYC_SIZE++;
			int x = u;
			CYCLE_COL_CNT[ EDGE_COL[u][v] ] += 1;
			do {
				CYCLE_COL_CNT[ EDGE_COL[x][P[x]] ] += 1;
				x = P[x];
				IN_CYCLE[x] = 1;
			CYC_SIZE++;
			} while(x != v);
		}
	}
}

void solve() {
	rii(N,Q);
	FOR(i,0,N) {
		int u,v,c; rii(u,v), ri(c);
		--u; --v;
		G[u].pb(v);
		G[v].pb(u);
		CNT[u][c] += 1;
		CNT[v][c] += 1;

		EDGE_COL[u][v] = c;
		EDGE_COL[v][u] = c;
	}
	dfs();

	int ans = 0;
	FOR(i,0,N) ans += sz(CNT[i]);
	ans -= N;

	while(Q--) {
		int u,v,c; rii(u,v), ri(c);
		--u, --v;

		int old_c = EDGE_COL[u][v];

		EDGE_COL[u][v] = EDGE_COL[v][u] = c;

		ans -= sz(CNT[u]);
		ans -= sz(CNT[v]);

		CNT[u][old_c]--;
		if (CNT[u][old_c] == 0) CNT[u].erase(old_c);
		CNT[v][old_c]--;
		if (CNT[v][old_c] == 0) CNT[v].erase(old_c);

		CNT[u][c]++;
		CNT[v][c]++;

		ans += sz(CNT[u]);
		ans += sz(CNT[v]);

		if (IN_CYCLE[u] && IN_CYCLE[v]) {
			CYCLE_COL_CNT[old_c]--;
			if (CYCLE_COL_CNT[old_c] == 0) CYCLE_COL_CNT.erase(old_c);
			CYCLE_COL_CNT[c]++;
		}

		int add = 0;
		if (sz(CYCLE_COL_CNT) == 1) {
			add = 1;
		}
		cout << ans + add << endl;
	}

	FOR(i,0,N) {
		G[i].clear();
		CNT[i].clear();
		IN_CYCLE[i] = 0;
		EDGE_COL[i].clear();
		VIS[i] = 0;
	}
	CYCLE_COL_CNT.clear();
	CYC_SIZE = 0;
}


int main(){
	int t; ri(t);
	FOR(i,1,t+1) {
		printf("Case #%d:\n", i);
		solve();
	}
	return 0;
}
