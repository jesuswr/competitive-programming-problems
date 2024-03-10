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

typedef int flow_t; // long long or int depending on the needs of the problem
struct edge {int to,rev;flow_t f,cap;};
struct Dinic{
	int nodes,src,dst;
	vi dist,q,work;
	vector<vector<edge>> g, gr;
	Dinic(int x):nodes(x),dist(x),q(x),work(x),g(x){}
	void add_edge(int s, int t, flow_t cap){
		g[s].pb((edge){t,sz(g[t]),0,cap});
		g[t].pb((edge){s,sz(g[s])-1,0,0});
	}
	bool dinic_bfs(){
		fill(all(dist),-1);dist[src]=0;
		int qt=0;q[qt++]=src;
		for(int qh=0;qh<qt;qh++){
			int u=q[qh];
			FOR(i,0,sz(g[u])){
				edge &e=g[u][i];int v=g[u][i].to;
				if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
			}
		}
		return dist[dst]>=0;
	}
	flow_t dinic_dfs(int u, flow_t f){
		if(u==dst)return f;
		for(int &i=work[u];i<sz(g[u]);i++){
			edge &e=g[u][i];
			if(e.cap<=e.f)continue;
			int v=e.to;
			if(dist[v]==dist[u]+1){
				flow_t df=dinic_dfs(v,min(f,e.cap-e.f));
				if(df>0){e.f+=df;g[v][e.rev].f-=df;return df;}
			}
		}
		return 0;
	}
	flow_t max_flow(int _src, int _dst){
		src=_src;dst=_dst;
		flow_t result=0;
		while(dinic_bfs()){
			fill(all(work),0);
			while(flow_t delta=dinic_dfs(src,INF))result+=delta;
		}
		return result;
	}
	void fill_reverse() {
		gr.resize(nodes);
		FOR(i,0,nodes) {
			for(auto e : g[i]) {
				gr[e.to].pb({i, -1, e.f, e.cap});
			}
		}
	}
};

vector<bool> bfs(const vector<vector<edge>> &g, int s) {
	int n = sz(g);
	
	vector<bool> vis(n); vis[s] = 1;
	queue<int> q; q.push(s);

	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(auto &e : g[u]) {
			if (vis[e.to] || e.f >= e.cap) continue;
			vis[e.to] = 1;
			q.push(e.to);
		}
	}

	return vis;
}

void solve() {
	int n,m; rii(n,m);
	int s = 2 * n, t = s + 1;
	Dinic mxf(2 * n + 2);
	FOR(i,0,n) {
		mxf.add_edge(s, i, 1);
		mxf.add_edge(n+i, t, 1);
	} 
	FOR(i,0,m) {
		int a,b; rii(a,b); --a; --b;
		mxf.add_edge(a, n+b, 1);
	}

	mxf.max_flow(s,t);
	mxf.fill_reverse();

	vector<bool> visS = bfs(mxf.g, s), visT = bfs(mxf.gr, t);
	// FOR(i,0,n) cout << i << ' ' << visS[i] << endl;
	// FOR(i,0,n) cout << i << ' ' << visT[n+i] << endl;

	int cntl = 0, cntr = 0;
	FOR(i,0,n) {
		cntl += visS[i];
		cntr += visT[n+i];
	}

	cout << 1ll * cntl * cntr << endl;

}


int main(){	
	int t; ri(t);
	while(t--) solve();
	return 0;
}
