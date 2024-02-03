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
#define lri(a) scanf("%lld", &a)
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
set<int> G2[MAXN];

int low[MAXN], disc[MAXN];
bool artVis[MAXN];
int t;
vi artPs;
void dfsAP(int x, int father = -1){
	low[x] = disc[x] = t++;
	artVis[x] = true;
	int children = 0;
	for(auto y : G[x]){
		if ( !artVis[y] ){
			children++;
			dfsAP(y,x);
			if (low[y]>=disc[x] && father!=-1){
				artPs.pb(x);
			}
			low[x] = min(low[x],low[y]);
		}
		else if ( y != father ){
			low[x] = min(low[x], disc[y]);
		}
	}
	if ( father == -1 && children > 1 ){
		artPs.pb(x);
	}
}

int C;
int CMP[MAXN];
void cmpDFS(int u, int cmp) {
	CMP[u] = cmp;
	for(int v : G[u]) if (CMP[v] == -1) {
		cmpDFS(v, cmp);
	}
}

int _tc = 1;
void go(){
	dfsAP(0);
	for(int x : artPs) if (CMP[x] == -1) CMP[x] = C++;
	FOR(i,0,N) if (CMP[i] == -1) { 
		cmpDFS(i,C++);
	}
	
	vi cmpCNT(C);
	FOR(i,0,N) cmpCNT[CMP[i]] ++;

	if (C == 1) {
		printf("Case %d: %d %lld\n", _tc++, 2, 1ll * N * (N - 1) / 2);
		return;
	}
	FOR(u,0,N) for(int v : G[u]) if (CMP[u] != CMP[v]) {
		G2[CMP[u]].insert(CMP[v]);
		G2[CMP[v]].insert(CMP[u]);
	}

	int leafs = 0; ll prod = 1;
	FOR(i,0,C) if (sz(G2[i]) == 1) {
		leafs++;
		prod *= cmpCNT[i];
	}

	printf("Case %d: %d %lld\n", _tc++, leafs, prod);
}

int main(){
	while(ri(N), N > 0) {
		int mx = 0;
		FOR(_,0,N) {
			int a,b; rii(a,b);
			G[a-1].pb(b-1);
			G[b-1].pb(a-1);
			mx = max(mx, max(a,b));
		}
		N = mx;
		FOR(i,0,N) CMP[i] = -1;
		FOR(i,0,N) artVis[i] = 0;
		FOR(i,0,N) low[i] = disc[i] = 0;
		artPs.clear();
		t = C = 0;
		
		go();
		
		FOR(i,0,N) G2[i].clear();
		FOR(i,0,N) G[i].clear();
	}
	return 0;
}
