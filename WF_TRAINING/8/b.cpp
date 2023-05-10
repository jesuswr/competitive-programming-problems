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

auto S_start = std::chrono::high_resolution_clock::now();
auto S_end = std::chrono::high_resolution_clock::now();

void start() {
	S_start = std::chrono::high_resolution_clock::now();
}
void end() {
	S_end = std::chrono::high_resolution_clock::now();
	 std::chrono::duration<double> elapsed = S_end - S_start; // Calculate the elapsed time
    std::cout << "Elapsed time: " << elapsed.count() << " seconds" << std::endl; // Output the elapsed time
}


int N, M;
vi G[MAXN];
vi A[MAXN];

map<ii,int> EDGE_CNT;
void dfs(int x, int father, vector<int> &low, vector<int> &disc, vector<bool> &vis, int &t, vii &bridges, vii &rest) {
	low[x] = disc[x] = t++;
	vis[x] = true;
	int children = 0;
	for(auto y : G[x]){
		if ( !vis[y] ){
			children++;
			dfs(y,x,low,disc,vis,t,bridges,rest);
			if (low[y]>disc[x] && EDGE_CNT[{min(x,y), max(x,y)}] <= 1)
				bridges.pb({x,y});
			else 
				rest.pb({x,y});
			low[x] = min(low[x],low[y]);
		}
		else if ( y != father ){
			low[x] = min(low[x], disc[y]);
		}
	}
}

int father[MAXN], siz[MAXN];
void makeSet(int n, int m){
	for (int i = n; i <= m; ++i){
		father[i] = -1;
		siz[i] = 0;
	}
}
int find(int x){
	if (father[x]==-1)  return x;
	return father[x] = find(father[x]);
}
void unio(int x, int y){ 
	if (siz[x] > siz[y]) 
		father[y] = x;
	else{
		father[x] = y;
		if ( siz[x] == siz[y] ) siz[y]++;
	}
}

void updateGraph() {
	vii brigdes, rest;
	vi low(N), disc(N);
	vector<bool> vis(N);
	int _t = 0;
	FOR(i,0,N) if (!vis[i]) dfs(i,-1,low,disc,vis,_t,brigdes,rest);
	makeSet(0, N-1);
	for(auto [a,b] : rest) {
		a = find(a), b = find(b);
		if (a != b) 
			unio(a,b);
	}
	FOR(i,0,N) G[i].clear();
	for(auto [a,b] : brigdes) {
		// cout << a << " " << b << "   to    ";
		a = find(a); b = find(b);
		G[a].pb(b);
		G[b].pb(a);
		// cout << a << " " << b << endl;
	}
	FOR(i,0,N) if (i != find(i)) {
		A[find(i)].pb(A[i][0]);
	}
	// FOR(i,0,N) if (i == find(i)) {
	// 	for(int a : A[i]) printf("%d : %d\n", i, a);
	// }
}

struct NOSE {
	int mx = MAXN - 1;
	int FREQ[MAXN], CNT[MAXN];
	vector<int> AUX;
	void clear() {
		for(int x : AUX) CNT[x] = 0;
		FOR(i,0,mx+1) FREQ[i] = 0;
		mx = 0;
		AUX.clear();
	}
	void add(int x) {
		AUX.pb(x);
		if (CNT[x] > 0)
			FREQ[CNT[x]]--;
		CNT[x]++;
		FREQ[CNT[x]]++;
		mx = max(mx, CNT[x]);
	}
	void rem(int x) {
		FREQ[CNT[x]]--;
		CNT[x]--;
		FREQ[CNT[x]]++;
		if (FREQ[mx] == 0)
			mx--;
	}
};

NOSE SUBT, OTHERS;
int AUX;

int sz[MAXN], st[MAXN], ft[MAXN], ver[MAXN], t;
void getsz(int v, int p) {
    sz[v] = 1;  // every vertex has itself in its subtree
    ver[t] = v;
    st[v] = t++;
	for(int a : A[v]) OTHERS.add(a); 
    for (auto u : G[v])
        if (u != p) {
            getsz(u, v);
            sz[v] += sz[u]; // add size of child u to its parent(v)
        }
    ft[v] = t;
}

unordered_map<ll, int> MP;

ll f(int u, int v) {
	if (u > v) swap(u,v);
	return 2ll * N * u + v;
}

void dfs(int v, int p, bool keep) { // O(nlogn)
    int mx = -1, bigChild = -1;
    for (auto u : G[v])
        if (u != p && sz[u] > mx)
            mx = sz[u], bigChild = u;
    for (auto u : G[v])
        if (u != p && u != bigChild)
            dfs(u, v, 0); 
    if (bigChild != -1)
        dfs(bigChild, v, 1);  
    for (auto u : G[v])
        if (u != p && u != bigChild)
            for (int p = st[u]; p < ft[u]; p++)
                for(int a : A[ver[p]] ) OTHERS.rem(a), SUBT.add(a);
	for(int a : A[v] ) OTHERS.rem(a), SUBT.add(a);
	MP[f(v, p)] = (SUBT.mx + OTHERS.mx - AUX);
    if (keep == 0)
        for (int p = st[v]; p < ft[v]; p++)
            for(int a : A[ver[p]] ) OTHERS.add(a), SUBT.rem(a);
}



void solve() {
	rii(N,M);
	FOR(i,0,N) G[i].clear();
	FOR(i,0,N) A[i].resize(1);
	FOR(i,0,N) ri(A[i][0]);
	vii edges;
	EDGE_CNT.clear();
	FOR(_,0,M) {
		int u,v; rii(u,v); --u; --v;
		edges.pb({u,v});
		if (u > v) swap(u,v);
		if (u == v) continue;
		G[u].pb(v);
		G[v].pb(u);
		EDGE_CNT[{u,v}]++;
	}
	updateGraph();
	MP.clear();
	int x = 1;
	while(x <= M) x <<= 1;
	MP.reserve(x);
	MP.max_load_factor(0.25);
	int sm = 0;
	FOR(i,0,N) sz[i] = 0;
		// start();
	FOR(i,0,N) {
		if (i == find(i) && !sz[i]) {
			t = 0;
			OTHERS.clear();
			SUBT.clear();
			getsz(i,-1);
			AUX = OTHERS.mx;
			// cout << "PARA " << i << " TEMGO TOTAL " << AUX << endl;
			sm += AUX;
			dfs(i,-1,0);
		}
	}
		// end();
	bool fst = true;
	for(auto [u,v] : edges) {
		u = find(u); v = find(v);
		if (u > v) swap(u, v);
		if (!fst) printf(" ");
		fst = 0;
		printf("%d", sm + MP[f(u,v)]);
	}
	printf("\n");
}


int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
